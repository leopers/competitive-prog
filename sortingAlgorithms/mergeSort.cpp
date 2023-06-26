#include "stdc++.h"

template <std::forward_iterator It>
void merge(It begin, It mid, It end)
{
  std::vector<std::iter_value_t<It>> tmp;

  auto it1 = begin;
  auto it2 = mid;
  while (it1 != mid && it2 != end)
    tmp.push_back(std::move(*it1 < *it2 ? *it1++ : *it2++));

  std::move(it1, mid, back_inserter(tmp));
  std::move(it2, end, back_inserter(tmp));
  std::move(tmp.begin(), tmp.end(), begin);
}

template <std::forward_iterator It>
void mergesort(It begin, It end)
{
  const auto length = std::distance(begin, end);
  if (length < 2)
    return;

  const auto mid = std::next(begin, length / 2);

  mergesort(begin, mid);
  mergesort(mid, end);

  merge(begin, mid, end);
}