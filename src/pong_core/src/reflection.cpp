//==============================================================
// Filename : reflection.cpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description : Source file for the Reflection class.
//   This class implements the reflection of the ball on a bat or wall,
//   and provides methods for computing the reflection given the object type,
//   the ball state before the reflection, the bat state (if the object is a bat),
//   and the reflection coefficient (gamma), which can be used 
//   to accelerate or slow down the ball.
//==============================================================

#include "pong_core/reflection.hpp"

pong_core::msg::BallState Reflection::reflect(const pong_core::msg::BallState& ball_state_before,
                                               const ObjectType object_type,
                                               const pong_core::msg::BatsState& bat_state,
                                               double gamma) {
    pong_core::msg::BallState ball_state_after;

    if (object_type == ObjectType::BAT) {
        // Bat reflection
        double normal_x = 0.0;
        //TODO: modify it
        double normal_y = bat_state.right_pos_y;

        ball_state_after = bat_reflection(ball_state_before, normal_x, normal_y, gamma);
    } else {
        // Wall reflection
        ball_state_after = wall_reflection(ball_state_before, gamma);
    }

    return ball_state_after;
}

pong_core::msg::BallState Reflection::bat_reflection(const pong_core::msg::BallState& ball_state_before,
                                                     double normal_x, double normal_y, double gamma) {
    pong_core::msg::BallState ball_state_after;

    double dot_product = ball_state_before.vel_x * normal_x + ball_state_before.vel_y * normal_y;

    ball_state_after.vel_x = gamma * (ball_state_before.vel_x - 2 * normal_x * dot_product);
    ball_state_after.vel_y = gamma * (ball_state_before.vel_y - 2 * normal_y * dot_product);

    return ball_state_after;
}

pong_core::msg::BallState Reflection::wall_reflection(const pong_core::msg::BallState& ball_state_before, double gamma) {
    pong_core::msg::BallState ball_state_after;

    ball_state_after.vel_x = ball_state_before.vel_x * gamma;
    ball_state_after.vel_y = -ball_state_before.vel_y * gamma;

    return ball_state_after;
}
