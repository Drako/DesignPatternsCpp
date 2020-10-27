#pragma once

#ifndef DEPENDENCY_INJECTION_WRITER_HXX
#define DEPENDENCY_INJECTION_WRITER_HXX

#include <fruit/fruit.h>

#include <string>

struct writer {
  virtual ~writer() = default;

  virtual void write(std::string const& message) = 0;
};

fruit::Component<writer> get_writer_component();

#endif // DEPENDENCY_INJECTION_WRITER_HXX
