#include "rectangle.hxx"
#include "shape_visitor.hxx"

rectangle::rectangle(int w, int h) noexcept
    :w{w}, h{h}
{
}

void rectangle::visit(shape_visitor& visitor) const
{
  visitor.visit(*this);
}