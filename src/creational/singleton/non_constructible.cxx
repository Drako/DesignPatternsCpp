#include "non_constructible.hxx"

non_constructible_singleton::non_constructible_singleton(int answer) noexcept
    :answer{answer}
{
}

non_constructible_singleton& non_constructible_singleton::get_instance() noexcept
{
  static non_constructible_singleton instance{42};
  return instance;
}

int non_constructible_singleton::get_answer() const noexcept
{
  return answer;
}
