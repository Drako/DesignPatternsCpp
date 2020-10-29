#include <gtest/gtest.h>

#include <sstream>
#include <iostream>

class printer {
private:
  std::ostream& strm;

public:
  printer(std::ostream& strm)
      :strm(strm) { }

  void print(char const* str)
  {
    if (!this)
      instance().print(str);
    else
      strm << str;
  }

  static printer& instance()
  {
    static printer inst{std::cout};
    return inst;
  }
};

void say_hello(printer* p)
{
  p->print("Hello world!\n");
}

TEST(ConditionalSingletonTest, CanUseNullptrAsSingleton)
{
  std::ostringstream strm;
  printer p{strm};
  say_hello(&p);

  say_hello(nullptr);
}
