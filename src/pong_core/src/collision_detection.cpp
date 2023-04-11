//==============================================================
// Filename : collision_detection.cpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License : N.A.
// Description : Source file for CollisionDetection classes.
// This file includes the class implementation for CollisionDetection,
// BatCollisionDetection, and WallCollisionDetection. These classes
// are used for detecting collisions between the ball and the bat
// or walls in a game. They include methods for checking if the ball
// is inside an object, detecting collisions between the ball and an
// object, and computing the collision point.
//==============================================================


#include "pong_core/collision_detection.hpp"

bool CollisionDetection::isInside(const Point &ball, const Rectangle &object, double ball_size)
{
  return (object.x1 - ball_size / 2 <= ball.x && ball.x <= object.x2 + ball_size / 2) &&
         (object.y1 - ball_size / 2 <= ball.y && ball.y <= object.y2 + ball_size / 2);
}

void CollisionDetection::computeCollisionPoint(const Point &prev_ball_pos, const Point &curr_ball_pos, Point &collision_point)
{
  double alpha = (object_.x1 - prev_ball_pos.x) / (curr_ball_pos.x - prev_ball_pos.x);
  collision_point.x = (1 - alpha) * prev_ball_pos.x + alpha * curr_ball_pos.x;
  collision_point.y = (1 - alpha) * prev_ball_pos.y + alpha * curr_ball_pos.y;
}

/* ----------------------- BatCollisionDetection class ---------------------- */


BatCollisionDetection::BatCollisionDetection(const Rectangle &bat)
{
  object_ = bat;
}

bool BatCollisionDetection::isCollision(const Point &prev_ball_pos, const Point &curr_ball_pos, double ball_size, Point *collision_point)
{
  bool was_inside = isInside(prev_ball_pos, object_, ball_size);
  bool is_inside = isInside(curr_ball_pos, object_, ball_size);

  if (!was_inside && is_inside)
  {
    if (collision_point != nullptr)
    {
      computeCollisionPoint(prev_ball_pos, curr_ball_pos, *collision_point);
    }
    return true;
  }
  return false;
}


/* ---------------------- WallCollisionDetection class ---------------------- */

WallCollisionDetection::WallCollisionDetection(const Rectangle &wall)
{
  object_ = wall;
}

bool WallCollisionDetection::isCollision(const Point &prev_ball_pos, const Point &curr_ball_pos, double ball_size, Point *collision_point)
{
  bool was_inside = isInside(prev_ball_pos, object_, ball_size);
  bool is_inside = isInside(curr_ball_pos, object_, ball_size);

  if (!was_inside && is_inside)
  {
    if (collision_point != nullptr)
    {
      computeCollisionPoint(prev_ball_pos, curr_ball_pos, *collision_point);
    }
    return true;
  }
  return false;
}