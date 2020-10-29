#include <gtest/gtest.h>

#include "foo.hxx"

TEST(FooTest, ShouldGiveCorrectAnswer)
{
  foo f;
  EXPECT_EQ(f.get_answer(), 42);
}
