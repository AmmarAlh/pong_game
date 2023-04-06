//==============================================================
// Filename : LightPositionDetection.
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description : Header file for LightPositionDetection class.
//   This class provides image processing for detecting the
//   position of a light source in an image. It includes methods
//   for applying a region of interest, processing the image,
//   and finding the brightest spot. It uses the ROS2 framework
//   for communication and includes message and parameter
//   handling functions.
//==============================================================

#include "advanced_user_interface/light_position_detection.hpp"

using std::placeholders::_1;

LightPositionDetection::LightPositionDetection()
    : Node("light_position_detection"), brightness_threshold_{0}
{
  RCLCPP_INFO(this->get_logger(), "Node is running");
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>("webcam_input", 10, std::bind(&LightPositionDetection::callbackLPD, this, _1));
  publisher_ = this->create_publisher<advanced_user_interface::msg::Point2>("light_position", 1);

  // Declaring parameters
  // In case the param is not set, the default value is applied
  this->declare_parameter<int>("brightness_threshold", 250);
  this->declare_parameter<std::vector<int>>("roi_origin", {0, 0});
  this->declare_parameter<std::vector<int>>("roi_size", {-1, -1});

  // Getting parameters value at execution
  brightness_threshold_ = this->get_parameter("brightness_threshold").as_int();
  roi_origin_ = this->get_parameter("roi_origin").as_integer_array();
  roi_size_ = this->get_parameter("roi_size").as_integer_array();

  // Param at run time configuration
  callback_handle_ = this->add_on_set_parameters_callback(
      std::bind(&LightPositionDetection::callbackParam, this, std::placeholders::_1));
  RCLCPP_INFO_STREAM(this->get_logger(), "brightness threshold value is set to " << brightness_threshold_);
  RCLCPP_INFO_STREAM(this->get_logger(), "roi origin value is set to [" << roi_origin_[0] << "," << roi_origin_[1] << "].");
  RCLCPP_INFO_STREAM(this->get_logger(), "roi width value is set to [" << roi_size_[0] << "," << roi_size_[1] << "].");
}
/**
 * @brief Callback function to set the parameters for the node at runtime.
 * @param parameters A vector of parameters to set.
 * @return rcl_interfaces::msg::SetParametersResult Result of setting the parameters.
 */
rcl_interfaces::msg::SetParametersResult LightPositionDetection::callbackParam(
    const std::vector<rclcpp::Parameter> &parameters)
{
  rcl_interfaces::msg::SetParametersResult result;
  result.successful = false;
  result.reason = "";
  for (const auto &param : parameters)
  {
    if (param.get_name() == "brightness_threshold")
    {
      if (param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER)
      {
        brightness_threshold_ = param.as_int();
        result.reason = "Successful";
        result.successful = true;
        RCLCPP_INFO_STREAM(this->get_logger(), "brightness threshold value is set to " << brightness_threshold_);
      }
      else if (param.get_name() == "roi_origin")
      {
        if (param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER_ARRAY)
        {
          roi_origin_ = param.as_integer_array();
          result.reason = "Successful";
          result.successful = true;
          RCLCPP_INFO_STREAM(this->get_logger(), "ROI origin is set to (" << roi_origin_[0] << ", " << roi_origin_[1] << ")");
        }
      }
      else if (param.get_name() == "roi_size")
      {
        if (param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER_ARRAY)
        {
          roi_size_ = param.as_integer_array();
          result.reason = "Successful";
          result.successful = true;
          RCLCPP_INFO_STREAM(this->get_logger(), "ROI size is set to (" << roi_size_[0] << ", " << roi_size_[1] << ")");
        }
      }
    }
  }
  return result;
}
/**
 * @brief Callback function for image processing.
 * This function takes in an image message and processes it to detect the brightest spot.
 * The image is first converted to grayscale and a region of interest is applied to the image.
 * A Gaussian blur is applied to reduce noise and thresholding is done to segment the image.
 * Morphological operations are performed to fill gaps in white regions and contour detection
 * is used to detect the boundaries of the white regions. The center of gravity of the brightest
 * spot is then calculated and published.
 * @param msg Input image message to be processed
 */
void LightPositionDetection::callbackLPD(const sensor_msgs::msg::Image &msg)
{
  cv_bridge::CvImagePtr cv_ptr;

  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception &e)
  {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    return;
  }
  cv::Mat processed_img;
  // processes the input image by converting it to grayscale, applying a region of interest,
  // Gaussian blur, and thresholding, and returns the processed image as an output parameter.
  // Convert the image to grayscale in-place
  cv::cvtColor(cv_ptr->image, processed_img, cv::COLOR_BGR2GRAY);
  applyRegionOfInterest(processed_img, processed_img, roi_origin_, roi_size_);
  cv::GaussianBlur(processed_img, processed_img, cv::Size(15, 15), 0);
  cv::inRange(processed_img, brightness_threshold_, 255, processed_img);

  double mean = cv::mean(processed_img)[0];
  cv::Canny(processed_img, processed_img, mean * 0.66, mean * 0.33, 3);

  // Getting the COG of the brightest spot in image
  advanced_user_interface::msg::Point2 pt;
  findBrightestSpot(cv_ptr->image, processed_img, pt);
  normalizePoint(pt,pt,cv_ptr->image.cols,cv_ptr->image.rows);
  RCLCPP_INFO_STREAM(this->get_logger(), "Publishing  x =" << pt.x << ", and y = " << pt.y);
  // publish the COG of the largest point
  publisher_->publish(pt);
}
/**
 * @brief Finds the center of the brightest spot in a processed image using contour detection.
 *
 * @param orig_img The original input image (not modified).
 * @param processed_img The processed image to be used for contour detection.
 * @param pt The output parameter for the center of the brightest spot.
 * 
 * This function applies contour detection on the processed image to locate the brightest spot,
 * which is represented by the largest contour. The center of mass of the largest contour is
 * calculated and returned as the center of the brightest spot. The center of mass is then
 * converted to the original image coordinates and returned as an output parameter.
 */
void LightPositionDetection::findBrightestSpot(cv::Mat &orig_img, cv::Mat &processed_img, advanced_user_interface::msg::Point2 &pt)
{
  std::vector<std::vector<cv::Point>> contours;
  std::vector<cv::Vec4i> hierarchy;

  cv::findContours(processed_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

  if (!contours.empty())
  {
    // Find the contour with the largest area
    size_t max_contour_index = 0;
    double max_contour_area = cv::contourArea(contours[0]);
    for (size_t i = 1; i < contours.size(); i++)
    {
      double contour_area = cv::contourArea(contours[i]);
      if (contour_area > max_contour_area)
      {
        max_contour_area = contour_area;
        max_contour_index = i;
      }
    }

    // Calculate the center of mass of the largest contour
    cv::Moments moments = cv::moments(contours[max_contour_index]);
    cv::Point2f center_of_mass(moments.m10 / (moments.m00 + 1e-5), moments.m01 / (moments.m00 + 1e-5));

    // Convert the center of mass to the original image coordinates
    pt.x = static_cast<int>(center_of_mass.x) + roi_origin_[0];
    pt.y = static_cast<int>(center_of_mass.y) + roi_origin_[1];
#define __DEBUG
#ifdef __DEBUG
    // Draw the contour and center of mass on the original image
    cv::Point ptsh;
    ptsh.x = pt.x;
    ptsh.y = pt.y;
    cv::Scalar color = cv::Scalar(0, 0, 255); // BGR values
    cv::drawContours(orig_img, contours, max_contour_index, color, 2);
    cv::circle(orig_img, ptsh, 4, color, -1);
#endif
  }

#ifdef __DEBUG
  // Display the original image with the contour and center of mass drawn
  cv::namedWindow("Light Indicator", cv::WINDOW_AUTOSIZE);
  cv::imshow("Light Indicator", orig_img);
  cv::waitKey(3);
#endif
}
/**
 * @brief Applies a region of interest (ROI) to the input image by extracting the subregion of the image specified
 * by the ROI and returning it as the processed image.
 * 
 * @param input_img The input image to apply the ROI to.
 * @param processed_img The processed image to store the output in.
 * @param roi_origin A vector of two integers specifying the x and y coordinates of the upper-left corner of the ROI.
 * @param roi_size A vector of two integers specifying the width and height of the ROI.
 */
void LightPositionDetection::applyRegionOfInterest(cv::Mat &input_img, cv::Mat &processed_img, const std::vector<long int> &roi_origin, const std::vector<long int> &roi_size)
{
  // Define the region of interest
  cv::Rect roi;

  // Define the region of interest
  if (roi_size[0] > 0 && roi_size[1] > 0 && (roi_origin[0] >= 0) && (roi_origin[1] >= 0))
  {
    // Update the roi values
    roi.x = roi_origin[0];
    roi.y = roi_origin[1];
    roi.width = roi_size[0];
    roi.height = roi_size[1];
  }
  else // set the left-side of the image as roi
  {
    // Update the roi values
    roi.x = roi_origin[0];
    roi.y = roi_origin[1];
    roi.width = input_img.cols / 2;
    roi.height = input_img.rows;
  }

  // Apply the region of interest to the image
  processed_img = input_img(roi);
}

/**
 * @brief Normalizes a point in an image to be between 0 and 1.
 * 
 * @param input_point The point to be normalized.
 * @param normalized_point The normalized point (output).
 * @param img_width The width of the image.
 * @param img_height The height of the image.
 */

void LightPositionDetection::normalizePoint(const advanced_user_interface::msg::Point2& input_point, advanced_user_interface::msg::Point2& normalized_point, int img_width, int img_height)
{
    if (img_width == 0 || img_height == 0)
    {
        RCLCPP_ERROR(this->get_logger(), "Image width or height is zero, cannot normalize point");
        return;
    }
    
    normalized_point.x = input_point.x / static_cast<double>(img_width);
    normalized_point.y = input_point.y / static_cast<double>(img_height);
}

