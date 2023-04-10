#include <memory>

#include <iostream>
#include <SDL2/SDL.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "/home/ram-user/ros2_ws/src/visualization_pkg/include/Pong_field.hpp"
#include "/home/ram-user/ros2_ws/src/visualization_pkg/include/SDL2_UI.hpp"
#include "/home/ram-user/ros2_ws/src/visualization_pkg/src/visualization.cpp"
using std::placeholders::_1;


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Visualization>());
  rclcpp::shutdown();
  return 0;
}
