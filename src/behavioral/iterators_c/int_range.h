#pragma once

#ifndef ITERATORS_C_INT_RANGE_H
#define ITERATORS_C_INT_RANGE_H

#include "iterator.h"

typedef struct int_range {
  int from;
  int to;

  iterator_t (* iterator)(struct int_range const*);
} int_range_t;

int_range_t make_int_range(int from, int to);

#endif // ITERATORS_C_INT_RANGE_H
