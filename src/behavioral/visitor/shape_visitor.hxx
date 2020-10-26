#pragma once

#ifndef VISITOR_SHAPE_VISITOR_HXX
#define VISITOR_SHAPE_VISITOR_HXX

struct shape;
class circle;
class rectangle;

struct shape_visitor {
  virtual ~shape_visitor() = default;

  virtual void visit(circle const&) = 0;
  virtual void visit(rectangle const&) = 0;
};

float circumference(shape const& s);
float area(shape const& s);

#endif // VISITOR_SHAPE_VISITOR_HXX
