void str_copy(char *s, char *t) {
  while (*s != '\0') {
    *t = *s;
    ++t;
    ++s;
  }
  *t = '\0';
}

