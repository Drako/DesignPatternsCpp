#pragma once

#include "package.hxx"

struct data_converter {
  virtual ~data_converter() = default;

  virtual void convert(package& data) = 0;
};
