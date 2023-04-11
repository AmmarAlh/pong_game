//==============================================================
// Filename: game_controller.cpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description: Source file for Trajectory class.
//              This class provides a base class for
//              trajectory calculations and derived class for ball
//              trajectories, including functions
//              for updating the ball position and getting the
//              ball position. It uses the ROS2 framework for communication
//              and includes message and parameter handling functions.
//==============================================================

#include "pong_core/trajectory.hpp"


/* -------------------------------------------------------------------------- */
/*                    BallTrajectory class implementation                   */
/* -------------------------------------------------------------------------- */

void BallTrajectory::updatePosition(const pong_core::msg::BallState& ball_state, float time_step)
{
    // If the unit of velocity is <position units>/s
    ball_state_.pos_x += ball_state.vel_x * time_step;
    ball_state_.pos_y += ball_state.vel_y * time_step;

    // If the unit of velocity is <position units>/sample time
    // ball_state_.pos_x += ball_state.vel_x;
    // ball_state_.pos_y += ball_state.vel_y;
}

const pong_core::msg::BallState& BallTrajectory::getBallPosition() const
{
    return ball_state_;
}

void BallTrajectory::setBallPosition(const pong_core::msg::BallState& ball_position)
{
    ball_state_ = ball_position;
}
