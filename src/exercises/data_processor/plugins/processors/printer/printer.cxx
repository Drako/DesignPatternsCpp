#include <ddic.hxx>

#include <data_processor.hxx>
#include <data_storage.hxx>
#include <data_converter.hxx>

#include <iostream>
#include <iomanip>
#include <thread>

using namespace std::literals::chrono_literals;

class printer: public data_processor {
  std::shared_ptr<data_storage> storage;
  std::shared_ptr<data_converter> converter;

  bool running = false;
  std::thread worker{};

public:
  explicit printer(
      std::shared_ptr<data_storage> storage,
      std::shared_ptr<data_converter> converter
  )
      :storage{std::move(storage)}, converter{std::move(converter)}
  {
  }

  bool start() override
  {
    if (running) {
      return false;
    }

    running = true;
    worker = std::thread{[this] {
      int counter = 0;

      while (running) {
        std::this_thread::sleep_for(250ms);

        auto pkg = storage->read_package();
        converter->convert(pkg);

        std::cout
            << "Package #" << std::dec << ++counter << ": "
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[0])
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[1])
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[2])
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[3])
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[4])
            << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[5])
            << std::endl;
      }
    }};
    return true;
  }

  bool stop() override
  {
    if (!running) {
      return false;
    }

    running = false;
    worker.join();
    return true;
  }
};

DDIC_REGISTER_TYPES(c)
{
  c->register_type<
          printer,
          ddic::creation_policy::always_same
      >(ddic::inject<data_storage, data_converter>{})
      .as<data_processor>();

  return true;
}
