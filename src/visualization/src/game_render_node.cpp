#include <memory>

#include <iostream>
#include <SDL2/SDL.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visualization/Pong_field.hpp"
#include "visualization/SDL2_UI.hpp"
#include "game_render.cpp"
using std::placeholders::_1;


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GameRender>());
  rclcpp::shutdown();
  return 0;
}
