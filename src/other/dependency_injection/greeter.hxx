#pragma once

#ifndef DEPENDENCY_INJECTION_GREETER_HXX
#define DEPENDENCY_INJECTION_GREETER_HXX

#include <fruit/fruit.h>

#include <string>

#include "writer.hxx"

struct greeter {
  virtual ~greeter() = default;

  virtual void greet() = 0;
};

fruit::Component<fruit::Required<writer>, greeter> get_greeter_component();

#endif // DEPENDENCY_INJECTION_GREETER_HXX
