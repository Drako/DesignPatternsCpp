#pragma once

#ifndef DECORATOR_STREAM_PRINTER_HXX
#define DECORATOR_STREAM_PRINTER_HXX

#include "printer.hxx"

#include <iosfwd>

class stream_printer : public printer {
  std::ostream& out;

public:
  explicit stream_printer(std::ostream& out) noexcept;

  stream_printer(stream_printer const&) = delete;
  stream_printer(stream_printer&&) = delete;
  stream_printer& operator=(stream_printer const&) = delete;
  stream_printer& operator=(stream_printer&&) = delete;

  void print(const std::string& message) override;
};

#endif // DECORATOR_STREAM_PRINTER_HXX
