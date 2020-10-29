#include "foo.hxx"

struct foo_data {
  int answer;

  explicit foo_data(int answer)
      :answer(answer)
  {
  }
};

foo::foo()
    :d_ptr{std::make_unique<foo_data>(42)}
{
}

foo::~foo()
{
  // required for std::unique_ptr<foo_data>
}

foo_data* foo::d()
{
  return d_ptr.get();
}

foo_data const* foo::d() const
{
  return d_ptr.get();
}

int foo::get_answer() const
{
  return d()->answer;
}
