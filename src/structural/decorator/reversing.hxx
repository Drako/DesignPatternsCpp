#pragma once

#ifndef DECORATOR_REVERSING_HXX
#define DECORATOR_REVERSING_HXX

#include "printer.hxx"

class reversing: public printer {
  printer& base;

public:
  explicit reversing(printer& base) noexcept;

  reversing(reversing const&) = delete;
  reversing(reversing&&) = delete;
  reversing& operator=(reversing const&) = delete;
  reversing& operator=(reversing&&) = delete;

  void print(const std::string& message) override;
};

#endif // DECORATOR_REVERSING_HXX
