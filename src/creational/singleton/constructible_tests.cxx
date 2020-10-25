#include <gtest/gtest.h>

#include <type_traits>

#include "constructible.hxx"

TEST(ConstructibleSingletonTest, SingletonShouldBeConstructible) {
  EXPECT_TRUE((std::is_constructible<constructible_singleton, int>::value));
}

TEST(ConstructibleSingletonTest, SingletonShouldNotBeCopyable)
{
  EXPECT_FALSE(std::is_copy_constructible<constructible_singleton>::value);
  EXPECT_FALSE(std::is_copy_assignable<constructible_singleton>::value);
}

TEST(ConstructibleSingletonTest, SingletonShouldNotBeMovable)
{
  EXPECT_FALSE(std::is_move_constructible<constructible_singleton>::value);
  EXPECT_FALSE(std::is_move_assignable<constructible_singleton>::value);
}

TEST(ConstructibleSingletonTest, SingletonShouldBeAccessible)
{
  constructible_singleton obj{42};
  EXPECT_EQ(constructible_singleton::get_instance().get_answer(), 42);
}

TEST(ConstructibleSingletonTest, ThereCanBeOnlyOne) {
  ASSERT_DEATH({
    constructible_singleton a{42};
    constructible_singleton b{23};
  }, "^Assertion failed: \\(instance==nullptr\\).*$");
}

TEST(ConstructibleSingletonTest, CrashesIfThereIsNoInstanceYet) {
  ASSERT_DEATH({
      (void)constructible_singleton::get_instance();
  }, "^Assertion failed: \\(instance!=nullptr\\).*$");
}
