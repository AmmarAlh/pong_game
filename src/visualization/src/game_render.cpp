//==============================================================
// Filename : game_render.cpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License : N.A.
// Description : Implementation file for GameRender class.
//   This class provides game rendering using SDL2.
//   It uses the ROS2 framework for communication and includes
//   message and parameter handling functions.
//==============================================================
#include "visualization/game_render.hpp"

GameRender::GameRender()
    : Node("GameRender")
{
    subscription_ = this->create_subscription<game_msgs::msg::GameState>(
        "game_state", 10, std::bind(&GameRender::gameStateCallback, this, std::placeholders::_1));
}

void GameRender::run()
{
    rclcpp::Rate rate(30); // 30 Hz refresh rate

    while (rclcpp::ok())
    {
        field.DrawField();

        bool wantsToQuit = field.sdl2_ui.processEvents();
        if (wantsToQuit)
        {
            RCLCPP_INFO(this->get_logger(), "User requested to quit the application.");
            break;
        }

        rclcpp::spin_some(shared_from_this());
        rate.sleep();
    }
}

void GameRender::gameStateCallback(const game_msgs::msg::GameState::SharedPtr msg)
{
    field.setFieldText(std::to_string(msg->score_left) + " - " + std::to_string(msg->score_right));
    field.setXYBall(msg->ball_pos_x, msg->ball_pos_y);
    field.setYBatLeft(msg->bat_left_pos_y);
    field.setYBatRight(msg->bat_right_pos_y);
}

