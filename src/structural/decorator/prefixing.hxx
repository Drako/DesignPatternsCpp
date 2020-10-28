#pragma once

#ifndef DECORATOR_PREFIXING_HXX
#define DECORATOR_PREFIXING_HXX

#include "printer.hxx"
#include "decorator.hxx"

class prefixing: public decorator<printer> {
  std::string prefix;

public:
  explicit prefixing(printer& base, std::string prefix);

  prefixing(prefixing const&) = delete;
  prefixing(prefixing&&) = delete;
  prefixing& operator=(prefixing const&) = delete;
  prefixing& operator=(prefixing&&) = delete;

  void print(const std::string& message) override;
};

#endif // DECORATOR_PREFIXING_HXX
