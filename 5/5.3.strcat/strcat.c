void _strcat(char *s, char *t) {
  while (*s != '\0') {
    ++s;
  }
  for (; (*s = *t) != '\0'; s++, t++);
}

