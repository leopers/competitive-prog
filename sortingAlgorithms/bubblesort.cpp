#include "stdc++.h"

template <std::forward_iterator It>
void bubblesort(It begin, It end)
{
  for (; begin != end; --end)
    for (auto left = begin, right = std::next(left); right != end; left = right++)
      if (*left > *right)
        std::iter_swap(left, right);
}

template <std::bidirectional_iterator It>
void shakersort(It begin, It end)
{
  while (true)
  {
    for (auto left = begin, right = std::next(left);
         right != end;
         left = right++)
      if (*left > *right)
        std::iter_swap(left, right);
    if (begin == --end)
      return;

    for (auto right = std::prev(end), left = std::prev(right);
         right != begin;
         right = left--)
      if (*left > *right)
        std::iter_swap(left, right);
    if (++begin == end)
      return;
  }
}