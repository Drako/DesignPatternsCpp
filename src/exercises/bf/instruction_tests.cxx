#include <gtest/gtest.h>

#include "instruction.hxx"
#include "vm.hxx"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>

TEST(InstructionTest, ValueModifications)
{
  vm state{};

  value_modification{1}.apply_to(state);
  EXPECT_EQ(state.memory[0], 1);
  value_modification{-2}.apply_to(state);
  EXPECT_EQ(state.memory[0], -1);
}

TEST(InstructionTest, PointerModifications)
{
  vm state{};

  pointer_modification{1}.apply_to(state);
  EXPECT_EQ(state.pointer, 1);
  pointer_modification{-2}.apply_to(state);
  EXPECT_EQ(state.pointer, 65535);
}

TEST(InstructionTest, ValueOutput)
{
  vm state{};
  std::ostringstream strm;

  state.memory[0] = 'A';
  value_output{strm}.apply_to(state);

  EXPECT_EQ(strm.str(), "A");
}

TEST(InstructionTest, Scope)
{
  vm state{};
  std::ostringstream strm;

  scope{{
            new value_modification{'A'},
            new value_output{strm},
        }}.apply_to(state);

  EXPECT_EQ(strm.str(), "A");
}

TEST(InstructionTest, Loop)
{
  vm state{};
  std::ostringstream strm;

  std::string const message = "Hello, world!";
  std::copy(std::cbegin(message), std::cend(message), std::begin(state.memory));

  loop{scope{{
    new value_output{strm},
    new pointer_modification{1},
  }}}.apply_to(state);

  EXPECT_EQ(strm.str(), message);
}
