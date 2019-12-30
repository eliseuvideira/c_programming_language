int str_index_of(char *s, char *t) {
  char *x = s;
  char *y = t;
  char *z;
  while (*s != '\0') {
    for (z = s; *z == *t && *t != '\0'; ++z, ++t);
    if (*t == '\0') {
      return s - x;
    }
    ++s;
    t = y;
  }
  return -1;
}

