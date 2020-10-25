#include <gtest/gtest.h>

#include <type_traits>

#include "static.hxx"

TEST(StaticSingletonTest, SingletonShouldNotBeConstructible)
{
  EXPECT_FALSE(std::is_default_constructible<static_singleton>::value);
  EXPECT_FALSE(std::is_copy_constructible<static_singleton>::value);
  EXPECT_FALSE(std::is_move_constructible<static_singleton>::value);
}

TEST(StaticSingletonTest, SingletonShouldNotBeAssignable)
{
  EXPECT_FALSE(std::is_copy_assignable<static_singleton>::value);
  EXPECT_FALSE(std::is_move_assignable<static_singleton>::value);
}

TEST(StaticSingletonTest, SingletonShouldBeAccessible)
{
  EXPECT_EQ(static_singleton::get_instance().get_answer(), 42);
}
