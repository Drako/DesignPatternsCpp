#include "circle.hxx"
#include "shape_visitor.hxx"

circle::circle(int r) noexcept
    :r{r}
{
}

void circle::visit(shape_visitor& visitor) const
{
  visitor.visit(*this);
}
