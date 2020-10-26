#pragma once

#ifndef DECORATOR_MOCK_PRINTER_HXX
#define DECORATOR_MOCK_PRINTER_HXX

#include "printer.hxx"

#include <gmock/gmock.h>

class mock_printer: public printer {
public:
  MOCK_METHOD(void, print, (std::string const&), (override));
};

#endif // DECORATOR_MOCK_PRINTER_HXX
