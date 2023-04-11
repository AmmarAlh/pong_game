//==============================================================
// Filename : LightPositionDetection.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description : Header file for GameController class.
// This class provides game control for a Pong game. It includes methods
// for updating the ball and bats position, detecting collisions, and
// publishing the updated ball position to ROS2 topics. It uses the
// ROS2 framework for communication and includes message and parameter
// handling functions.
//==============================================================


#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <memory>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "pong_core/msg/ball_state.hpp"
#include "pong_core/msg/bats_state.hpp"
#include "pong_core/collision_detection.hpp"
#include "pong_core/trajectory.hpp"
#include "pong_core/reflection.hpp"


using namespace std::chrono_literals;

class GameController : public rclcpp::Node
{
public:
  GameController();

private:
  void batsStateCallback(const pong_core::msg::BatsState::SharedPtr msg);
  void update();
  void ballMovement();
  void collisionDet();
  void BatLeftMovement();
  void BatRightMovement();

  rclcpp::Publisher<pong_core::msg::BallState>::SharedPtr ball_state_publisher_;
  rclcpp::Subscription<pong_core::msg::BatsState>::SharedPtr bats_state_subscription_;
  rclcpp::TimerBase::SharedPtr timer_;

  double ball_pos_x_, ball_pos_y_;
  double ball_vel_x_, ball_vel_y_;
  double bat_left_pos_y_, bat_right_pos_y_;
  double time_step_{0.2};
//   std::shared_ptr<BatCollisionDetection> bat_collision_detector_;
//   std::shared_ptr<WallCollisionDetection> wall_collision_detector_;
};

#endif  // GAME_CONTROLLER_HPP