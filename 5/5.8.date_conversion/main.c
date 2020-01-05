#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
void assert_equals(int, int);

int main() {
  int day, month;
  day = day_of_year(2020, 1, 4);
  assert_equals(day, 4);
  month_day(2020, 4, &month, &day);
  assert_equals(month, 1);
  assert_equals(day, 4);
  return 0;
}

