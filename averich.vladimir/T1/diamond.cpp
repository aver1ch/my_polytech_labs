#include "diamond.hpp"

#include <cmath>
#include <stdexcept>

namespace averich
{
  double distance(point_t p1, point_t p2)
  {
    return std::sqrt(std::pow(p2.x - p1.x, 2.0) + std::pow(p2.y - p1.y, 2.0));
  }
  bool isTriangle(point_t p1, point_t p2, point_t p3)
  {
    const double d1 = distance(p1, p2);
    const double d2 = distance(p1, p3);
    const double d3 = distance(p2, p3);
    return (d1 + d2 > d3) && (d1 + d3 > d2) && (d2 + d3 > d1);
  }
  bool tryWithCenter(point_t possibleCenter, point_t p1, point_t p2, point_t& center, double& width, double& height)
  {
    if (possibleCenter.x == p1.x && possibleCenter.y == p2.y)
    {
      center = possibleCenter;
      width = std::abs(p2.x - center.x) * 2.0;
      height = std::abs(p1.y - center.y) * 2.0;

      return true;
    }
    if (possibleCenter.x == p2.x && possibleCenter.y == p1.y)
    {
      center = possibleCenter;
      width = std::abs(p1.x - center.x) * 2.0;
      height = std::abs(p2.y - center.y) * 2.0;

      return true;
    }
    return false;
  }
  Diamond::Diamond(point_t p1, point_t p2, point_t p3)
  {
    if (!isTriangle(p1, p2, p3))
    {
      throw std::invalid_argument("Can't create Diamond with given parameters");
    }
    if (!tryWithCenter(p1, p2, p3, center_, width_, height_))
    {
      if (!tryWithCenter(p2, p1, p3, center_, width_, height_))
      {
        if (!tryWithCenter(p3, p1, p2, center_, width_, height_))
        {
          throw std::invalid_argument("Can't create Diamond with given parameters");
        }
      }
    }
  }
  Diamond::Diamond(point_t center, size_t width, size_t height):
    center_(center),
    width_(width),
    height_(height)
  {
    if (width == 0 || height == 0)
    {
      throw std::invalid_argument("Can't create Diamond with given parameters");
    }
  }
  void Diamond::move(point_t p)
  {
    center_ = p;
  }
  void Diamond::move(double shift_x, double shift_y)
  {
    center_.x += shift_x;
    center_.y += shift_y;
  }
  void Diamond::scale(double scale)
  {
    width_ *= scale;
    height_ *= scale;
  }
  Shape* Diamond::clone() const
  {
    return new Diamond(center_, height_, width_);
  }
  double Diamond::getArea() const
  {
    return (width_ * height_) / 2.0;
  }
  rectange_t Diamond::getFrameRect() const
  {
    return rectange_t{center_, width_, height_};
  }
}
