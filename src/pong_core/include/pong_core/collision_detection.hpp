//==============================================================
// Filename : collision_detection.hpp
// Authors : Ammar Alhannafi & Michiel van Geene
// Group : 33
// License : N.A.
// Description : Header file for CollisionDetection classes.
// This file includes the class definitions for CollisionDetection,
// BatCollisionDetection, and WallCollisionDetection. These classes
// are used for detecting collisions between the ball and the bat
// or walls in a game. They include methods for checking if the ball
// is inside an object, detecting collisions between the ball and an
// object, and computing the collision point.
//==============================================================


#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

class CollisionDetection
{
public:
  struct Rectangle
  {
    double x1, y1, x2, y2;
  };

  struct Point
  {
    double x, y;
  };

  virtual ~CollisionDetection() = default;

  bool isInside(const Point &ball, const Rectangle &object, double ball_size = 0.0);
  virtual bool isCollision(const Point &prev_ball_pos, const Point &curr_ball_pos, double ball_size = 0.0, Point *collision_point = nullptr) = 0;

protected:
  Rectangle object_;

  void computeCollisionPoint(const Point &prev_ball_pos, const Point &curr_ball_pos, Point &collision_point);
};

class BatCollisionDetection : public CollisionDetection
{
public:
  BatCollisionDetection(const Rectangle &bat);
  bool isCollision(const Point &prev_ball_pos, const Point &curr_ball_pos, double ball_size = 0.0, Point *collision_point = nullptr) override;
};

class WallCollisionDetection : public CollisionDetection
{
public:
  WallCollisionDetection(const Rectangle &wall);
  bool isCollision(const Point &prev_ball_pos, const Point &curr_ball_pos, double ball_size = 0.0, Point *collision_point = nullptr) override;
};

#endif // COLLISION_DETECTION_HPP
