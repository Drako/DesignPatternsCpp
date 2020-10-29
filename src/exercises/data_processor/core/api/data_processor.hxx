#pragma once

struct data_processor {
  virtual ~data_processor() = default;

  virtual bool start() = 0;
  virtual bool stop() = 0;
};
