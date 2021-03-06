#include <ddic.hxx>

#include "api/data_source.hxx"
#include "api/data_processor.hxx"
#include "console.hxx"

#include <iostream>

int main()
{
  ddic::container c;
  c.register_type<console>().as<output_device>();
  c.load_types("dummy_source_plugin");
  c.load_types("list_buffer_plugin");
  c.load_types("noop_converter_plugin");
  c.load_types("printer_plugin");

  auto input = c.resolve<data_source>();
  auto output = c.resolve<data_processor>();
  input->start();
  output->start();

  std::cin.get();

  output->stop();
  input->stop();

  return 0;
}
