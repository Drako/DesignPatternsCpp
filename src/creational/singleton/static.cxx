#include "static.hxx"

static_singleton static_singleton::instance{42};

static_singleton::static_singleton(int answer) noexcept
    :answer{answer}
{
}

static_singleton& static_singleton::get_instance() noexcept
{
  return instance;
}

int static_singleton::get_answer() const noexcept
{
  return answer;
}
