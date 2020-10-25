#include "constructible.hxx"

#include <cassert>

constructible_singleton* constructible_singleton::instance = nullptr;

constructible_singleton::constructible_singleton(int answer) noexcept
    :answer{answer}
{
  assert(instance==nullptr);
  instance = this;
}

constructible_singleton& constructible_singleton::get_instance() noexcept
{
  assert(instance!=nullptr);
  return *instance;
}

int constructible_singleton::get_answer() const noexcept
{
  return answer;
}

constructible_singleton::~constructible_singleton()
{
  assert(instance!=nullptr);
  instance = nullptr;
}


