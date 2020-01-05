static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  int i, leap;
  if (year < 0) {
    return -1;
  }
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
    return -1;
  }
  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

void month_day(int year, int year_day, int *month, int *day) {
  int i, leap;
  if (year < 0) {
    *month = -1;
    *day = -1;
    return;
  }
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; year_day > daytab[leap][i]; i++) {
    year_day -= daytab[leap][i];
  }
  if (i > 12 || year_day > 31) {
    *month = -1;
    *day = -1;
    return;
  }
  *month = i;
  *day = year_day;
}

