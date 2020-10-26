#include <gtest/gtest.h>

#include "prefixing.hxx"
#include "reversing.hxx"
#include "shouting.hxx"
#include "mock_printer.hxx"

TEST(CombinedTest, ShouldPrintMessageUppercasedAndPrefixed)
{
  mock_printer base_printer;
  prefixing pref_printer{base_printer, "Shouted: "};
  shouting shout_pref_printer{pref_printer};

  EXPECT_CALL(base_printer, print("Shouted: HELLO, WORLD!"));
  shout_pref_printer.print("Hello, world!");
}

TEST(CombinedTest, ShouldPrintMessagePrefixedAndUppercased)
{
  mock_printer base_printer;
  shouting shout_printer{base_printer};
  prefixing pref_shout_printer{shout_printer, "Shouted: "};

  EXPECT_CALL(base_printer, print("SHOUTED: HELLO, WORLD!"));
  pref_shout_printer.print("Hello, world!");
}

TEST(CombinedTest, ShouldPrintUppercasedAndReversed)
{
  mock_printer base_printer;
  shouting shout_printer{base_printer};
  reversing rev_shout_printer{shout_printer};

  EXPECT_CALL(base_printer, print("OLLEH"));
  rev_shout_printer.print("hello");
}

TEST(CombinedTest, ShouldPrintPrefixedWithReversedAndUppercasedMessage)
{
  mock_printer base_printer;
  prefixing pref_printer{base_printer, "Combined: "};
  reversing rev_pref_printer{pref_printer};
  shouting shout_rev_pref_printer{rev_pref_printer};

  EXPECT_CALL(base_printer, print("Combined: OLLEH"));
  shout_rev_pref_printer.print("hello");
}
