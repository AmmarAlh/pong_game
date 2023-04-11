//==============================================================
// Filename : game_render.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License : N.A.
// Description : Header file for GameRender class.
//   This class provides game rendering using SDL2.
//   It uses the ROS2 framework for communication and includes 
//   message and parameter handling functions.
//==============================================================

#pragma once

#include <SDL2/SDL.h>
#include "rclcpp/rclcpp.hpp"
#include "visualization/Pong_field.hpp"
#include "visualization/SDL2_UI.hpp"
#include "game_msgs/msg/game_state.hpp" 

class GameRender : public rclcpp::Node
{
public:
  GameRender();
  void run();
private:
  void gameStateCallback(const game_msgs::msg::GameState::SharedPtr msg);

  rclcpp::Subscription<game_msgs::msg::GameState>::SharedPtr subscription_;
  Pong_field field;
};
