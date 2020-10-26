#include <gtest/gtest.h>

#include "prefixing.hxx"
#include "mock_printer.hxx"

TEST(PrefixingTest, ShouldPrintMessagePrefixed)
{
  mock_printer base_printer;
  prefixing pref_printer{base_printer, "Message: "};

  EXPECT_CALL(base_printer, print("Message: Hello, world!"));
  pref_printer.print("Hello, world!");
}
