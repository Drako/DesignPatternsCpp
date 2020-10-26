#include "reversing.hxx"

reversing::reversing(printer& base) noexcept
    :base{base}
{
}

void reversing::print(const std::string& message)
{
  std::string reversed{message.crbegin(), message.crend()};
  base.print(reversed);
}
