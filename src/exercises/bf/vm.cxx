#include "vm.hxx"

#include <ostream>

void vm::modify_value(int const by)
{
  memory[pointer] += by;
}

void vm::modify_pointer(std::int16_t const by)
{
  pointer += by;
}

void vm::print_value(std::ostream& out)
{
  out.put(static_cast<char>(memory[pointer]));
}
