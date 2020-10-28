#include "int_range.h"

#include <stdio.h>

int main(void)
{
  int_range_t range = make_int_range(10, 20);
  for_each(int, n, range, ({
    printf("%d\n", n);
  }));

  return 0;
}
