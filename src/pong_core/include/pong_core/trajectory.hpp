//==============================================================
// Filename: trajectory.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description: Header file for Trajectory class.
//              This class provides a base class for
//              trajectory calculations and derived class for ball
//              trajectories, including functions
//              for updating the ball position and getting the
//              ball position. It uses the ROS2 framework for communication
//              and includes message and parameter handling functions.
//==============================================================

#ifndef TRAJECTORY_HPP
#define TRAJECTORY_HPP

#include "pong_core/msg/ball_state.hpp"

class Trajectory
{
public:
    Trajectory()= default;
    virtual ~Trajectory() = default;

    virtual void updatePosition(const pong_core::msg::BallState& state, float time_step) = 0;

protected:
    pong_core::msg::BallState ball_state_;
};

class BallTrajectory : public Trajectory
{
public:
    BallTrajectory() = default;
    void updatePosition(const pong_core::msg::BallState& ball_state, float time_step) override;

    const pong_core::msg::BallState& getBallPosition() const;
    void setBallPosition(const pong_core::msg::BallState& ball_position);

};

#endif // TRAJECTORY_HPP
