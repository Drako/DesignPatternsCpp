#include "greeter.hxx"

class greeter_impl final: public greeter {
  writer* w;

public:
  // can't use INJECT() macro because of `explicit` constructor
  using Inject = greeter_impl(writer*);

  explicit greeter_impl(writer* w)
      :w{w}
  {
  }

  void greet() override
  {
    w->write("Hello, world!");
  }
};

fruit::Component<fruit::Required<writer>, greeter> get_greeter_component()
{
  return fruit::createComponent()
      .bind<greeter, greeter_impl>();
}
