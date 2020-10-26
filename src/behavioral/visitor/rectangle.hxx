#pragma once

#ifndef VISITOR_RECTANGLE_HXX
#define VISITOR_RECTANGLE_HXX

#include "shape.hxx"

struct rectangle : shape {
  int w, h;

  rectangle(int w, int h) noexcept;

  void visit(shape_visitor& visitor) const override;
};

#endif // VISITOR_RECTANGLE_HXX
