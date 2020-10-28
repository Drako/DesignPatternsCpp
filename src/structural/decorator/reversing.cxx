#include "reversing.hxx"

reversing::reversing(printer& base) noexcept
    :decorator<printer>{base}
{
}

void reversing::print(const std::string& message)
{
  std::string reversed{message.crbegin(), message.crend()};
  base.print(reversed);
}
