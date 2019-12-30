void _strncat(char *s, char *t, int n) {
  while (*s != '\0') {
    ++s;
  }
  while (*t != '\0' && n > 0) {
    *s = *t;
    ++s;
    ++t;
    --n;
  }
  *s = '\0';
}

