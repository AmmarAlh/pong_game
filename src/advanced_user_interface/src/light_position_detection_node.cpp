#include "advanced_user_interface/light_position_detection.hpp"


int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LightPositionDetection>());
  rclcpp::shutdown();
  return 0;
}