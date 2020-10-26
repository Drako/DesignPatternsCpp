#pragma once

#ifndef VISITOR_SHAPE_HXX
#define VISITOR_SHAPE_HXX

class shape_visitor;

struct shape {
  virtual ~shape() = default;

  virtual void visit(shape_visitor& visitor) const = 0;
};

#endif // VISITOR_SHAPE_HXX
