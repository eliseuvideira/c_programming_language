int _strncmp(char *s, char *t, int n) {
  while (*s == *t && n >= 0) {
    if (*s == '\0' || n == 0) {
      return 0;
    }
    ++s;
    ++t;
    --n;
  }
  return *s - *t;
}

