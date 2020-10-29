#pragma once

#include "package.hxx"

struct data_storage {
  virtual ~data_storage() = default;

  virtual void store_package(package data) = 0;
  virtual package read_package() = 0;
};
