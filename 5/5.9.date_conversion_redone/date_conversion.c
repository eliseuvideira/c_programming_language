static int daytab[][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
  int *p;
  int leap;
  if (year < 0) {
    return -1;
  }
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  if (month < 1 || month > 12 || day < 1 || day > daytab[leap][month]) {
    return -1;
  }
  p = &daytab[leap][1];
  for (; month > 1; month--, p++) {
    day += *p;
  }
  return day;
}

void month_day(int year, int year_day, int *month, int *day) {
  int *p, *max;
  int leap;
  if (year < 0) {
    *month = -1;
    *day = -1;
    return;
  }
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  p = &daytab[leap][1];
  max = &daytab[leap][12];
  for (; year_day > *p && p <= max; p++) {
    year_day -= *p;
  }
  if (year_day > 31) {
    *month = -1;
    *day = -1;
    return;
  }
  *month = p - daytab[leap];
  *day = year_day;
}

