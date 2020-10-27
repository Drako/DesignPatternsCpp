#include "writer.hxx"

#include <iostream>

class stdout_writer: public writer {
public:
  INJECT(stdout_writer()) = default;

  void write(std::string const& message) override
  {
    std::cout << message;
  }
};

fruit::Component<writer> get_writer_component()
{
  return fruit::createComponent().bind<writer, stdout_writer>();
}
