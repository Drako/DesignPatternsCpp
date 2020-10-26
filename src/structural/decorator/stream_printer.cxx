#include "stream_printer.hxx"

#include <ostream>

stream_printer::stream_printer(std::ostream& out) noexcept
    :out{out}
{
}

void stream_printer::print(const std::string& message)
{
  out << message;
}
