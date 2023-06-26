#include "stdc++.h"

template <std::forward_iterator It>
void selectionsort(It begin, It end)
{
  for (auto it = begin; it != end; ++it)
    std::iter_swap(it, std::min_element(it, end));
}

