#include <gtest/gtest.h>

#include "stream_printer.hxx"

#include <sstream>

TEST(StreamPrinterTest, ShouldPrintToStream)
{
  std::ostringstream target;
  stream_printer printer{target};

  printer.print("Hello, world!");
  EXPECT_EQ(target.str(), "Hello, world!");
}
