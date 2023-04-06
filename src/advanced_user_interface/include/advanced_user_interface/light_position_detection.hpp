//==============================================================
// Filename : LightPositionDetection.hpp
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

#ifndef LIGHT_POSITION_DETECTION_HPP
#define LIGHT_POSITION_DETECTION_HPP

#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "image_transport/image_transport.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include "advanced_user_interface/msg/point2.hpp"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/hal/interface.h>

class LightPositionDetection : public rclcpp::Node
{
public:
  LightPositionDetection();

private:
  void callbackLPD(const sensor_msgs::msg::Image &msg);
  void normalizePoint(const advanced_user_interface::msg::Point2& input_point, advanced_user_interface::msg::Point2& normalized_point, int img_width, int img_height);
  void findBrightestSpot(cv::Mat &orig_img, cv::Mat &img, advanced_user_interface::msg::Point2 &pt);
  void applyRegionOfInterest(cv::Mat &input_img, cv::Mat &processed_img, const std::vector<long int> &roi_origin, const std::vector<long int> &roi_size);
  rcl_interfaces::msg::SetParametersResult callbackParam(const std::vector<rclcpp::Parameter> &parameters);

  rclcpp::Publisher<advanced_user_interface::msg::Point2>::SharedPtr publisher_;
  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
  OnSetParametersCallbackHandle::SharedPtr callback_handle_;

  std::vector<long int> roi_origin_;
  std::vector<long int> roi_size_;
  int brightness_threshold_;
};

#endif // LIGHT_POSITION_DETECTION_HPP
