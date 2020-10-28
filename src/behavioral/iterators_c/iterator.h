#pragma once

#ifndef ITERATORS_C_ITERATOR_H
#define ITERATORS_C_ITERATOR_H

#include <stdbool.h>

typedef struct iterator {
  bool (* has_next)(struct iterator const*);
  void* (* next)(struct iterator*);
  void (* release)(struct iterator*);

  void* data_;
} iterator_t;

#define for_each(type, name, iterable, code)      \
  do {                                            \
    iterator_t it = iterable.iterator(&iterable); \
    while (it.has_next(&it)) {                    \
      type name = *(type*)(it.next(&it));         \
      code;                                       \
    }                                             \
    it.release(&it);                              \
  } while (false);

#endif // ITERATORS_C_ITERATOR_H
