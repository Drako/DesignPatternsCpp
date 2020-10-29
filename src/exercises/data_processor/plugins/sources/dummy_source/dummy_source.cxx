#include <ddic.hxx>

#include <data_source.hxx>
#include <data_storage.hxx>

#include <algorithm>
#include <chrono>
#include <iterator>
#include <memory>
#include <random>
#include <thread>

using namespace std::literals::chrono_literals;

class dummy_source: public data_source {
  std::shared_ptr<data_storage> storage;
  bool running = false;
  std::thread worker{};

public:
  explicit dummy_source(std::shared_ptr<data_storage> storage)
      :storage{std::move(storage)}
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

      while (running) {
        std::this_thread::sleep_for(200ms);

        package pkg;
        std::generate(std::begin(pkg), std::end(pkg), [&] {
          return dist(generator);
        });
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
      >(ddic::inject<data_storage>{})
      .as<data_source>();

  return true;
}
