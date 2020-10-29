#include "console.hxx"

#include <iostream>

void console::print_line(const std::string& message)
{
  std::lock_guard<std::mutex> lock{mutex};
  std::cout << message << std::endl;
}
