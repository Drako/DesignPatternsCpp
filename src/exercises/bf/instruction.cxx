#include "instruction.hxx"
#include "vm.hxx"

#include <utility>

value_modification::value_modification(int modifier)
    :modifier{modifier}
{
}

void value_modification::apply_to(vm& state)
{
  state.modify_value(modifier);
}

pointer_modification::pointer_modification(std::int16_t modifier)
    :modifier{modifier}
{
}

void pointer_modification::apply_to(vm& state)
{
  state.modify_pointer(modifier);
}

value_output::value_output(std::ostream& out)
    :out{out}
{
}

void value_output::apply_to(vm& state)
{
  state.print_value(out);
}

scope::scope(std::vector<instruction*> instructions)
    :instructions{std::move(instructions)}
{
}

void scope::apply_to(vm& state)
{
  for (auto command : instructions) {
    command->apply_to(state);
  }
}

scope::~scope()
{
  for (auto command : instructions) {
    delete command;
  }
}

loop::loop(scope body)
    :body{std::move(body)}
{
}

void loop::apply_to(vm& state)
{
  while (state.memory[state.pointer]) {
    body.apply_to(state);
  }
}
