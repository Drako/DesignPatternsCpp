#include <ddic.hxx>

#include <data_converter.hxx>

struct noop_converter: public data_converter {
  void convert(package& data) override
  {
    // No Operation
  }
};

DDIC_REGISTER_TYPES(c)
{
  c->register_type<
          noop_converter,
          ddic::creation_policy::always_same
      >()
      .as<data_converter>();

  return true;
}
