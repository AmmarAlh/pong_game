//==============================================================
// Filename : reflection.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License :  N.A.
// Description : Header file for the Reflection class.
//   This class implements the reflection of the ball on a bat or wall,
//   and provides methods for computing the reflection given the object type,
//   the ball state before the reflection, the bat state (if the object is a bat),
//   and the reflection coefficient (gamma), which can be used 
//   to accelerate or slow down the ball.
//==============================================================


#ifndef REFLECTION_HPP_
#define REFLECTION_HPP_

#include "pong_core/msg/ball_state.hpp"
#include "pong_core/msg/bats_state.hpp"

class Reflection {
public:
    enum class ObjectType { BAT, WALL };

    pong_core::msg::BallState reflect(const pong_core::msg::BallState& ball_state_before,
                                      const ObjectType object_type,
                                      const pong_core::msg::BatsState& bat_state,
                                      double gamma);

private:
    pong_core::msg::BallState bat_reflection(const pong_core::msg::BallState& ball_state_before,
                                             double normal_x, double normal_y, double gamma);

    pong_core::msg::BallState wall_reflection(const pong_core::msg::BallState& ball_state_before, double gamma);
};

#endif  // REFLECTION_HPP_
