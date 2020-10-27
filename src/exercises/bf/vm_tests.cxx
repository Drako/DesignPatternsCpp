#include <gtest/gtest.h>

#include "vm.hxx"

#include <sstream>

TEST(VmTest, ShouldAllowValueModification)
{
  vm state{};
  state.modify_value(3);
  EXPECT_EQ(state.memory[0], 3);
  state.modify_value(4);
  EXPECT_EQ(state.memory[0], 7);
  state.modify_value(-10);
  EXPECT_EQ(state.memory[0], -3);
}

TEST(VmTest, ShouldAllowPointerModification)
{
  vm state{};
  state.modify_pointer(3);
  EXPECT_EQ(state.pointer, 3);
  state.modify_pointer(4);
  EXPECT_EQ(state.pointer, 7);
  state.modify_pointer(-10);
  EXPECT_EQ(state.pointer, 65533);
}

TEST(VmTest, CorrectCellIsModified)
{
  vm state{};
  state.modify_pointer(2);
  state.modify_value(4);
  EXPECT_EQ(state.memory[2], 4);
}

TEST(VmTest, PrintingWorks)
{
  vm state{};
  state.memory[0] = 'A';

  std::ostringstream strm;
  state.print_value(strm);

  EXPECT_EQ(strm.str(), "A");
}
