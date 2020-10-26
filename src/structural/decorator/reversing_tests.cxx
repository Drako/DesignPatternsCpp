#include <gtest/gtest.h>

#include "reversing.hxx"
#include "mock_printer.hxx"

TEST(ReversingTest, ShouldPrintMessageReversed)
{
  mock_printer base_printer;
  reversing rev_printer{base_printer};

  EXPECT_CALL(base_printer, print("olleh"));
  rev_printer.print("hello");
}
