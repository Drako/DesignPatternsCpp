#pragma once

#ifndef PIMPL_FOO_HXX
#define PIMPL_FOO_HXX

#include <memory>

struct foo_data;

class foo {
  std::unique_ptr<foo_data> d_ptr;

  foo_data* d();
  foo_data const* d() const;

public:
  foo();
  ~foo();
  foo(foo&&) = default;
  foo(foo const&) = delete;
  foo& operator=(foo&&) = default;
  foo& operator=(foo const&) = delete;

  int get_answer() const;
};

#endif // PIMPL_FOO_HXX
