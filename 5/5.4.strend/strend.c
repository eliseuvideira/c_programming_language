int strend(char *s, char *t) {
  char *x = s;
  char *y = t;
  while (*x != '\0') {
    ++x;
  }
  while (*y != '\0') {
    ++y;
  }
  for (; *x == *y && x != s && t != y; x--, y--);
  if (*x == *y && t == y) {
    return 1;
  } else {
    return 0;
  }
}

