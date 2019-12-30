void _strncpy(char *s, char *t, int n) {
  int i;
  for (i = 0; i < n && *s != '\0'; ++i) {
    *t = *s;
    ++t;
    ++s;
  }
  *t = '\0';
}

