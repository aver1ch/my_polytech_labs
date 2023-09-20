#include "shape.hpp"

#include <iomanip>

namespace averich
{
std::ostream& operator<<(std::ostream& os, const Shape& obj)
{
  rectange_t frameRect = obj.getFrameRect();
  point_t bottom_left = frameRect.bl();
  point_t upper_right = frameRect.ur();
  os << std::fixed << std::setprecision(1)
     << obj.getArea() << " "
     << bottom_left.x << " " << bottom_left.y << " "
     << upper_right.x << " " << upper_right.y;
  return os;
}
}
