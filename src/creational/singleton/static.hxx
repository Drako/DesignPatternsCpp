#pragma once

#ifndef SINGLETON_STATIC_HXX
#define SINGLETON_STATIC_HXX

class static_singleton final {
  static static_singleton instance;

  explicit static_singleton(int answer) noexcept;

  int answer;

public:
  static_singleton(static_singleton const&) = delete;
  static_singleton(static_singleton&&) = delete;
  static_singleton& operator=(static_singleton const&) = delete;
  static_singleton& operator=(static_singleton&&) = delete;

  [[nodiscard]]
  static static_singleton& get_instance() noexcept;

  [[nodiscard]]
  int get_answer() const noexcept;
};

#endif // SINGLETON_STATIC_HXX
