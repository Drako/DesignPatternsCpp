#pragma once

#include <string>

struct output_device {
  virtual ~output_device() = default;

  virtual void print_line(std::string const&) = 0;
};
