#include <stdarg.h>
#include <stdio.h>
int sum(int count, ...) {
  va_list ap;
  int i, sum = 0;;

  va_start(ap, count);
  for (i = 0; i < count; ++i) {
    sum += va_arg(ap, int);
  }
  va_end(ap);
  return sum;
}
int main() {
  printf("%d\n", sum(3, 1, 3, 4));
  printf("%d\n", sum(4, 3, 20, 3, 4));
  return 0;
}
