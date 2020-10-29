#pragma once

#include "api/output_device.hxx"

#include <mutex>

class console: public output_device {
  std::mutex mutex;

public:
  void print_line(const std::string& message) override;
};
