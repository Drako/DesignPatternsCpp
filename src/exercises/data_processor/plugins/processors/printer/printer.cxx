#include <ddic.hxx>

#include <data_processor.hxx>
#include <data_storage.hxx>
#include <data_converter.hxx>
#include <output_device.hxx>

#include <iomanip>
#include <sstream>
#include <thread>

using namespace std::literals::chrono_literals;

class printer: public data_processor {
  std::shared_ptr<data_storage> storage;
  std::shared_ptr<data_converter> converter;
  std::shared_ptr<output_device> out;

  bool running = false;
  std::thread worker{};

public:
  explicit printer(
      std::shared_ptr<data_storage> storage,
      std::shared_ptr<data_converter> converter,
      std::shared_ptr<output_device> out
  )
      :storage{std::move(storage)}, converter{std::move(converter)}, out{std::move(out)}
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

        std::ostringstream formatter;
        formatter << "Thread #" << std::this_thread::get_id() << ": ";
        formatter << "[processor] Received package #" << std::dec << ++counter << " -> ";
        formatter << std::hex;
        for (std::size_t n = 0u; n < 8u; ++n) {
          formatter << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[n]);
        }

        out->print_line(formatter.str());
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
      >(ddic::inject<data_storage, data_converter, output_device>{})
      .as<data_processor>();

  return true;
}
