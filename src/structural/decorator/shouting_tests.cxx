#include <gtest/gtest.h>

#include "shouting.hxx"
#include "mock_printer.hxx"

TEST(ShoutingTest, ShouldPrintMessageAllUppercase)
{
  mock_printer base_printer;
  shouting shout_printer{base_printer};

  EXPECT_CALL(base_printer, print("HELLO"));
  shout_printer.print("hello");
}
