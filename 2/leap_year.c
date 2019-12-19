#include <stdio.h>

enum boolean { FALSE, TRUE };

int is_leap_year(int year);

int main() {
  int year = 2019;

  if (is_leap_year(year) == TRUE) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is not a leap year\n", year);
  }

  return 0;
}

int is_leap_year(int year) {
  if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}
