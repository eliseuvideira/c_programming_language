#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("min signed char: %d\n", SCHAR_MIN);
  printf("max signed char: %d\n", SCHAR_MAX);

  printf("min signed short: %d\n", SHRT_MIN);
  printf("max signed short: %d\n", SHRT_MAX);

  printf("min signed int: %d\n", INT_MIN);
  printf("max signed int: %d\n", INT_MAX);

  printf("min signed long: %ld\n", LONG_MIN);
  printf("max signed long: %ld\n", LONG_MAX);

  printf("max unsigned char: %ud\n", UCHAR_MAX);
  printf("max unsigned short: %ud\n", USHRT_MAX);
  printf("max unsigned int: %ud\n", UINT_MAX);
  printf("max unsigned long: %lud\n", ULONG_MAX);

  printf("min float: %f\n", FLT_MIN);
  printf("max float: %f\n", FLT_MAX);

  printf("min double: %f\n", DBL_MIN);
  printf("max double: %f\n", DBL_MAX);
  return 0;
}
