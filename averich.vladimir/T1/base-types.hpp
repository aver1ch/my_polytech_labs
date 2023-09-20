#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace averich
{
  struct point_t
  {
    double x, y;
  };
  struct rectange_t
  {
    point_t center;
    double width, height;
    point_t bl() const
    {
      return {center.x - width / 2.0, center.y - height / 2.0};
    }
    point_t ur() const
    {
      return {center.x + width / 2.0, center.y + height / 2.0};
    }
  };
}

#endif
