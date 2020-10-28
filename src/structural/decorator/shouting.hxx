#pragma once

#ifndef DECORATOR_SHOUTING_HXX
#define DECORATOR_SHOUTING_HXX

#include "printer.hxx"
#include "decorator.hxx"

struct shouting: public decorator<printer> {
  explicit shouting(printer& base) noexcept;

  shouting(shouting const&) = delete;
  shouting(shouting&&) = delete;
  shouting& operator=(shouting const&) = delete;
  shouting& operator=(shouting&&) = delete;

  void print(const std::string& message) override;
};

#endif // DECORATOR_SHOUTING_HXX
