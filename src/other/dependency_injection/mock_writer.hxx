#pragma once

#ifndef DEPENDENCY_INJECTION_MOCK_WRITER_HXX
#define DEPENDENCY_INJECTION_MOCK_WRITER_HXX

#include <fruit/fruit.h>
#include <gmock/gmock.h>

#include "writer.hxx"

class mock_writer: public writer {
public:
  INJECT(mock_writer()) = default;

  MOCK_METHOD(void, write, (std::string const&), (override));
};

inline fruit::Component<writer> get_mock_writer_component()
{
  return fruit::createComponent()
      .bind<writer, mock_writer>();
}

#endif // DEPENDENCY_INJECTION_WRITER_HXX
