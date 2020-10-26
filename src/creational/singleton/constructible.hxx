#pragma once

#ifndef SINGLETON_CONSTRUCTIBLE_HXX
#define SINGLETON_CONSTRUCTIBLE_HXX

class constructible_singleton final {
  static constructible_singleton* instance;

  int answer;

public:
  constructible_singleton(constructible_singleton const&) = delete;
  constructible_singleton(constructible_singleton&&) = delete;
  constructible_singleton& operator=(constructible_singleton const&) = delete;
  constructible_singleton& operator=(constructible_singleton&&) = delete;

  ~constructible_singleton();

  explicit constructible_singleton(int answer) noexcept;

  [[nodiscard]]
  static constructible_singleton& get_instance() noexcept;

  [[nodiscard]]
  int get_answer() const noexcept;
};

#endif // SINGLETON_CONSTRUCTIBLE_HXX
