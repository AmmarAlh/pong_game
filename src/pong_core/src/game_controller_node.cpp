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
#include "pong_core/game_controller.hpp"

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameController>());
  rclcpp::shutdown();
  return 0;
}