#include "int_range.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct int_range_iterator_data {
  int current;
  int to;
} int_range_iterator_data_t;

static bool int_range_iterator_has_next(iterator_t const* self)
{
  assert(self!=NULL);
  assert(self->data_!=NULL);

  int_range_iterator_data_t const* data = (int_range_iterator_data_t const*) (self->data_);

  return data->current<data->to;
}

static void* int_range_iterator_next(iterator_t* self)
{
  assert(self!=NULL);
  assert(self->data_!=NULL);

  int_range_iterator_data_t* data = (int_range_iterator_data_t*) (self->data_);
  ++(data->current);

  assert(data->current<=data->to);

  return (void*) (&(data->current));
}

static void int_range_iterator_release(iterator_t* self)
{
  assert(self!=NULL);

  free(self->data_);
  memset(self, 0, sizeof(iterator_t));
}

static iterator_t int_range_iterator(int_range_t const* self)
{
  assert(self!=NULL);

  int_range_iterator_data_t* data = (int_range_iterator_data_t*) malloc(sizeof(int_range_iterator_data_t));
  data->current = self->from-1;
  data->to = self->to;

  iterator_t it = {
      .has_next = &int_range_iterator_has_next,
      .next = &int_range_iterator_next,
      .release = &int_range_iterator_release,
      .data_ = (void*) data,
  };
  return it;
}

int_range_t make_int_range(int from, int to)
{
  int_range_t result = {
      .from = from,
      .to = to,
      .iterator = &int_range_iterator,
  };
  return result;
}
