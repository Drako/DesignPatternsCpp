#include "shouting.hxx"

#include <algorithm>
#include <cctype>

shouting::shouting(printer& base) noexcept
    :decorator<printer>{base}
{
}

void shouting::print(const std::string& message)
{
  std::string shouted{message};
  std::transform(shouted.cbegin(), shouted.cend(), shouted.begin(), [](char c) {
    return static_cast<char>(std::toupper(c));
  });
  base.print(shouted);
}
