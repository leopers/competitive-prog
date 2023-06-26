#include "stdc++.h"

template <std::bidirectional_iterator It>
void quicksort(It begin, It end)
{
  if (begin == end)
    return;

  auto left = begin;
  auto right = std::prev(end);

  const auto pivot_value = *left;

  while (true)
  {
    while (left != right && *right >= pivot_value)
      --right;
    if (left == right)
      break;
    std::iter_swap(left++, right);

    while (left != right && *left <= pivot_value)
      ++left;
    if (left == right)
      break;
    std::iter_swap(left, right--);
  }

  quicksort(begin, left);
  quicksort(std::next(left), end);
}
