#pragma once

#ifndef BF_VM_HXX
#define BF_VM_HXX

#include <array>
#include <cstdint>
#include <iosfwd>

struct vm {
  std::array<int, 65536> memory{};
  std::uint16_t pointer;

  void modify_value(int by);
  void modify_pointer(std::int16_t by);
  void print_value(std::ostream& out);
};

#endif // BF_VM_HXX
