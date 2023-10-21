#ifndef DICT_H
#define DICT_H

#include "AVLTree.h"

namespace aristarkhov
{
  template < typename KeyT, typename ValueT, typename ComparatorT = std::less< KeyT > >
  using Dictionary = detail::AVLTree< KeyT, ValueT, ComparatorT >;
}

#endif
