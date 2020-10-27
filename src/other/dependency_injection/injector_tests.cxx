#include <gtest/gtest.h>

#include "greeter.hxx"
#include "writer.hxx"
#include "mock_writer.hxx"

TEST(InjectorTest, CanGreetTheWorld)
{
  EXPECT_NO_FATAL_FAILURE(({
    auto const component = []() -> fruit::Component<writer, greeter> {
      return fruit::createComponent()
          .install(get_writer_component)
          .install(get_greeter_component);
    };

    fruit::Injector<writer, greeter> injector{static_cast<fruit::Component<writer, greeter>(*)()>(component)};
    auto g = injector.get<greeter*>();
    g->greet();
  }));
}

TEST(InjectorTest, WorksWithMock)
{
  auto const component = []() -> fruit::Component<writer, greeter> {
    return fruit::createComponent()
        .install(get_mock_writer_component)
        .install(get_greeter_component);
  };

  fruit::Injector<writer, greeter> injector{static_cast<fruit::Component<writer, greeter>(*)()>(component)};
  auto g = injector.get<greeter*>();
  auto w = dynamic_cast<mock_writer*>(injector.get<writer*>());

  EXPECT_CALL(*w, write("Hello, world!"));
  g->greet();
}
