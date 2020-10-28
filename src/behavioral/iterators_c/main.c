#include "int_range.h"

#include <stdio.h>

int main(void)
{
  int_range_t range = make_int_range(10, 20);

#ifdef _MSC_VER

  for_each(int, n, range)
    printf("%d\n", n);
  end_for_each();

#else // !_MSC_VER

  for_each(int, n, range, ({
    printf("%d\n", n);
  }));

#endif

  return 0;
}
