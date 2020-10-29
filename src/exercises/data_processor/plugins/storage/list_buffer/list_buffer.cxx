#include <ddic.hxx>

#include <data_storage.hxx>
#include <output_device.hxx>

#include <list>
#include <iomanip>
#include <memory>
#include <mutex>
#include <sstream>
#include <thread>

class list_buffer: public data_storage {
  static std::size_t const MAX_BUFFER_SIZE = 32u;

  std::shared_ptr<output_device> out;

  std::list<package> buffer{};

  std::condition_variable cv;
  std::mutex mutex;

public:
  explicit list_buffer(std::shared_ptr<output_device> out)
      :out{std::move(out)}
  {
  }

  void store_package(package data) override
  {
    {
      std::lock_guard<std::mutex> lock{mutex};
      if (buffer.size()==MAX_BUFFER_SIZE) {
        std::ostringstream formatter;
        formatter << "Thread #" << std::this_thread::get_id() << ": ";
        formatter << "[storage] Discarding package -> ";
        formatter << std::hex;
        for (std::size_t n = 0u; n < 8u; ++n) {
          formatter << std::setw(2) << std::setfill('0') << static_cast<int>(buffer.front()[n]);
        }

        out->print_line(formatter.str());

        buffer.pop_front();
      }
      buffer.push_back(data);
    }
    cv.notify_one();
  }

  package read_package() override
  {
    package pkg;
    {
      std::unique_lock<std::mutex> lock{mutex};
      cv.wait(lock);

      pkg = buffer.front();
      buffer.pop_front();
    }

    cv.notify_one();
    return pkg;
  }
};

DDIC_REGISTER_TYPES(c)
{
  c->register_type<
          list_buffer,
          ddic::creation_policy::always_same
      >(ddic::inject<output_device>{})
      .as<data_storage>();

  return true;
}
