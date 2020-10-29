#include <ddic.hxx>

#include <data_storage.hxx>

#include <list>
#include <mutex>

class list_buffer: public data_storage {
  static std::size_t const MAX_BUFFER_SIZE = 1024u;

  std::list<package> buffer{};

  std::condition_variable cv;
  std::mutex mutex;

public:
  void store_package(package data) override
  {
    {
      std::lock_guard<std::mutex> lock{mutex};
      if (buffer.size() == MAX_BUFFER_SIZE) {
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
      >()
      .as<data_storage>();

  return true;
}
