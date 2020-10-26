#include <gtest/gtest.h>

#include "shape_visitor.hxx"
#include "circle.hxx"
#include "rectangle.hxx"

#include <algorithm>
#include <memory>
#include <vector>

TEST(ShapeVisitorTest, ShouldCalculateCircumferences)
{
  std::vector<std::unique_ptr<shape>> shapes;
  shapes.emplace_back(new circle{2});
  shapes.emplace_back(new rectangle{2, 4});
  std::vector<float> actual(2);
  std::transform(shapes.cbegin(), shapes.cend(), actual.begin(), [](std::unique_ptr<shape> const& s) {
    return circumference(*s);
  });

  EXPECT_FLOAT_EQ(actual[0], M_2_PI * 2.0f);
  EXPECT_FLOAT_EQ(actual[1], 12.0f);
}

TEST(ShapeVisitorTest, ShouldCalculateAreas)
{
  std::vector<std::unique_ptr<shape>> shapes;
  shapes.emplace_back(new circle{2});
  shapes.emplace_back(new rectangle{2, 4});
  std::vector<float> actual(2);
  std::transform(shapes.cbegin(), shapes.cend(), actual.begin(), [](std::unique_ptr<shape> const& s) {
    return area(*s);
  });

  EXPECT_FLOAT_EQ(actual[0], M_PI * 4.0f);
  EXPECT_FLOAT_EQ(actual[1], 8.0f);
}
