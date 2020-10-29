#include <ddic.hxx>

#include <data_source.hxx>
#include <data_storage.hxx>
#include <output_device.hxx>

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iterator>
#include <memory>
#include <random>
#include <sstream>
#include <thread>

using namespace std::literals::chrono_literals;

class dummy_source: public data_source {
  std::shared_ptr<data_storage> storage;
  std::shared_ptr<output_device> out;

  bool running = false;
  std::thread worker{};

public:
  explicit dummy_source(std::shared_ptr<data_storage> storage, std::shared_ptr<output_device> out)
      :storage{std::move(storage)}, out{std::move(out)}
  {
  }

  bool start() override
  {
    if (running) {
      return false;
    }

    running = true;
    worker = std::thread{[this] {
      std::random_device rd;
      std::mt19937 generator{rd()};
      std::uniform_int_distribution<std::uint8_t> dist;

      int counter = 0;

      while (running) {
        std::this_thread::sleep_for(200ms);

        package pkg;
        std::generate(std::begin(pkg), std::end(pkg), [&] {
          return dist(generator);
        });

        std::ostringstream formatter;
        formatter << "Thread #" << std::this_thread::get_id() << ": ";
        formatter << "[source] Sending package #" << std::dec << ++counter << " -> ";
        formatter << std::hex;
        for (std::size_t n = 0u; n < 8u; ++n) {
          formatter << std::setw(2) << std::setfill('0') << static_cast<int>(pkg[n]);
        }

        out->print_line(formatter.str());

        storage->store_package(pkg);
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
          dummy_source,
          ddic::creation_policy::always_same
      >(ddic::inject<data_storage, output_device>{})
      .as<data_source>();

  return true;
}
