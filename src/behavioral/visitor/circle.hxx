#pragma once

#ifndef VISITOR_CIRCLE_HXX
#define VISITOR_CIRCLE_HXX

#include "shape.hxx"
#include "shape_visitor.hxx"

struct circle : shape {
  int r;

  explicit circle(int r) noexcept;

  void visit(shape_visitor& visitor) const override;
};

#endif // VISITOR_CIRCLE_HXX
