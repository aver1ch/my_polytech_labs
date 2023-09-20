#include "circle.hpp"

#include <limits>
#include <stdexcept>

#define _USE_MATH_DEFINES
#include <cmath>

namespace averich
{
  Circle::Circle(point_t center, double radius):
    center_(center),
    radius_(radius)
  {
    if (radius_ < std::numeric_limits< double >::epsilon())
    {
      throw std::invalid_argument("Can't create circle with given radius");
    }
  }
  void Circle::move(point_t p)
  {
    center_ = p;
  }
  void Circle::move(double shift_x, double shift_y)
  {
    center_.x += shift_x;
    center_.y += shift_y;
  }
  void Circle::scale(double scale)
  {
    radius_ *= scale;
  }
  Shape* Circle::clone() const
  {
    return new Circle(center_, radius_);
  }
  double Circle::getArea() const
  {
    return M_PI * radius_ * radius_;
  }
  rectange_t Circle::getFrameRect() const
  {
    return rectange_t{center_, radius_ * 2.0, radius_ * 2.0};
  }
}
