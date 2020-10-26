#pragma once

#ifndef DECORATOR_PRINTER_HXX
#define DECORATOR_PRINTER_HXX

#include <string>

struct printer {
  virtual ~printer() = default;

  virtual void print(std::string const& message) = 0;
};

#endif // DECORATOR_PRINTER_HXX
