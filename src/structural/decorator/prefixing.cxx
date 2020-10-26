#include "prefixing.hxx"

#include <utility>

prefixing::prefixing(printer& base, std::string prefix)
    :base{base}, prefix{std::move(prefix)}
{
}

void prefixing::print(const std::string& message)
{
  base.print(prefix + message);
}
