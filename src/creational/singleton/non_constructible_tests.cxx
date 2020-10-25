#include <gtest/gtest.h>

#include <type_traits>

#include "non_constructible.hxx"

TEST(NonConstructibleSingletonTest, SingletonShouldNotBeConstructible)
{
  EXPECT_FALSE(std::is_default_constructible<non_constructible_singleton>::value);
  EXPECT_FALSE(std::is_copy_constructible<non_constructible_singleton>::value);
  EXPECT_FALSE(std::is_move_constructible<non_constructible_singleton>::value);
}

TEST(NonConstructibleSingletonTest, SingletonShouldNotBeAssignable)
{
  EXPECT_FALSE(std::is_copy_assignable<non_constructible_singleton>::value);
  EXPECT_FALSE(std::is_move_assignable<non_constructible_singleton>::value);
}

TEST(NonConstructibleSingletonTest, SingletonShouldBeAccessible)
{
  EXPECT_EQ(non_constructible_singleton::get_instance().get_answer(), 42);
}
