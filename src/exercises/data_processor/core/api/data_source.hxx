#pragma once

struct data_source {
  virtual ~data_source() = default;

  virtual bool start() = 0;
  virtual bool stop() = 0;
};
