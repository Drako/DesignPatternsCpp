#include "shape_visitor.hxx"
#include "circle.hxx"
#include "rectangle.hxx"

#include <cmath>

float circumference(const shape& s)
{
  struct : shape_visitor {
    float value{};

    void visit(circle const& c) override {
      value = M_2_PI * c.r;
    }

    void visit(rectangle const& r) override {
      value = 2.0f * static_cast<float>(r.w + r.h);
    }
  } visitor;

  s.visit(visitor);

  return visitor.value;
}

float area(const shape& s)
{
  struct : shape_visitor {
    float value{};

    void visit(circle const& c) override {
      value = M_PI * c.r * c.r;
    }

    void visit(rectangle const& r) override {
      value = static_cast<float>(r.w * r.h);
    }
  } visitor;

  s.visit(visitor);

  return visitor.value;
}
