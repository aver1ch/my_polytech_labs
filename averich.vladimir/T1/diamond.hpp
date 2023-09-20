#ifndef DIAMOND_H
#define DIAMOND_H

#include "shape.hpp"

namespace averich
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t p1, point_t p2, point_t p3);
    virtual ~Diamond() = default;
    virtual void move(point_t p) override;
    virtual void move(double shift_x, double shift_y) override;
    virtual void scale(double scale) override;
    virtual double getArea() const override;
    virtual rectange_t getFrameRect() const override;
    virtual Shape* clone() const override;
  private:
    Diamond(point_t center, size_t width, size_t height);
    point_t center_;
    double width_, height_;
  };
}

#endif
