//==============================================================
// Filename : LightPositionDetection.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description : Source file for GameController class.
// This class implements the game logic for a basic Pong game.
// It includes methods for updating the game state, detecting
// collisions, and moving the game elements. It uses the ROS2
// framework for communication and includes message and parameter
// handling functions.
//==============================================================

#include "pong_core/game_controller.hpp"

GameController::GameController()
    : Node("pong_controller")
{
    ball_state_publisher_ = this->create_publisher<pong_core::msg::BallState>("ball_state", 10);
    bats_state_subscription_ = this->create_subscription<pong_core::msg::BatsState>(
        "bats_state",
        10,
        std::bind(&GameController::batsStateCallback, this, std::placeholders::_1));

    // Dont forget to initialize ball_state_, bats_state_, and other state variables

    timer_ = this->create_wall_timer(16ms, std::bind(&GameController::update, this));
}

void GameController::batsStateCallback(const pong_core::msg::BatsState::SharedPtr msg)
{
    // Update bat positions
    bat_left_pos_y_ = msg->left_pos_y;
    bat_right_pos_y_ = msg->right_pos_y;
}

void GameController::update()
{
    // Update ball movement
    ballMovement();

    // Check for collisions
    collisionDet();

    // Move the bats
    BatLeftMovement();
    BatRightMovement();

    // Publish updated ball state
    auto ball_state_msg = pong_core::msg::BallState();
    ball_state_msg.pos_x = ball_pos_x_;
    ball_state_msg.pos_y = ball_pos_y_;
    ball_state_msg.vel_x = ball_vel_x_;
    ball_state_msg.vel_y = ball_vel_y_;
    ball_state_publisher_->publish(ball_state_msg);
}

void GameController::ballMovement()
{
    BallTrajectory trajectory;
    pong_core::msg::BallState ball_state_after;

    trajectory.updatePosition(ball_state_after, time_step_);

    ball_pos_x_ = ball_state_after.pos_x;
    ball_pos_y_ = ball_state_after.pos_y;
}

void GameController::collisionDet()
{

}

void GameController::BatLeftMovement()
{

}

void GameController::BatRightMovement()
{

}
