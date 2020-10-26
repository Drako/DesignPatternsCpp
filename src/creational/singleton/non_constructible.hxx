#pragma once

#ifndef SINGLETON_NON_CONSTRUCTIBLE_HXX
#define SINGLETON_NON_CONSTRUCTIBLE_HXX

class non_constructible_singleton final {
  int answer;

  explicit non_constructible_singleton(int answer) noexcept;

public:
  non_constructible_singleton(non_constructible_singleton const&) = delete;
  non_constructible_singleton(non_constructible_singleton&&) = delete;
  non_constructible_singleton& operator=(non_constructible_singleton const&) = delete;
  non_constructible_singleton& operator=(non_constructible_singleton&&) = delete;

  [[nodiscard]]
  static non_constructible_singleton& get_instance() noexcept;

  [[nodiscard]]
  int get_answer() const noexcept;
};

#endif // SINGLETON_NON_CONSTRUCTIBLE_HXX
