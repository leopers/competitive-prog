#include "stdc++.h"

template <std::bidirectional_iterator It>
void insertionsort(It begin, It end)
{
  for (auto it = std::next(begin); it != end; ++it)
    for (auto right = it, left = std::prev(right);right != begin && *left > *right;right = left--)
      std::iter_swap(left, right);
}