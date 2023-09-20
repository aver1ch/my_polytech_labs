#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace averich
{
  class Circle: public Shape
  {
  public:
    Circle(point_t center, double radius);
    virtual ~Circle() = default;
    virtual void move(point_t p) override;
    virtual void move(double shift_x, double shift_y) override;
    virtual void scale(double scale) override;
    virtual double getArea() const override;
    virtual rectange_t getFrameRect() const override;
    virtual Shape* clone() const override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
