#include <gtest/gtest.h>

#include "int_range.hxx"

#include <algorithm>
#include <list>
#include <numeric>
#include <vector>

TEST(IntRangeTest, ShouldBeCompatibleWithContainers)
{
  int_range r{10};

  std::vector<int> v{std::cbegin(r), std::cend(r)};
  EXPECT_EQ(v, (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));

  std::list<int> l{std::cbegin(r), std::cend(r)};
  EXPECT_EQ(l, (std::list<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
}

TEST(IntRangeTest, ShouldBeCompatibleWithAlgorithms)
{
  int_range r{10};

  std::vector<int> v;
  std::copy_if(std::cbegin(r), std::cend(r), std::back_inserter(v), [](int n) { return n%2==0; });
  EXPECT_EQ(v, (std::vector<int>{0, 2, 4, 6, 8}));

  v.clear();
  std::transform(std::cbegin(r), std::cend(r), std::back_inserter(v), [](int n) { return n+1; });
  EXPECT_EQ(v, (std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}));
}

TEST(IntRangeTest, ShouldBeCompatibleWithNumerics)
{
  int_range r{10};
  auto const sum = std::accumulate(std::cbegin(r), std::cend(r), 0);
  EXPECT_EQ(sum, 1+2+3+4+5+6+7+8+9);
}

TEST(IntRangeTest, ShouldBeCompatibleWithRangeFor)
{
  int sum = 0;
  for (int n : int_range{1, 11}) {
    sum += n;
  }
  EXPECT_EQ(sum, 1+2+3+4+5+6+7+8+9+10);
}
