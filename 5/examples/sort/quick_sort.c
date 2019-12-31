void quick_sort(char *s[], int left, int right) {
  int i, last;
  void swap(char *[], int, int);
  int str_compare(char *, char *);
  if (left >= right) {
    return;
  }
  swap(s, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; ++i) {
    if (str_compare(s[i], s[left]) < 0) {
      swap(s, ++last, i);
    }
  }
  swap(s, left, last);
  quick_sort(s, left, last - 1);
  quick_sort(s, last + 1, right);
}

void swap(char *s[], int i, int j) {
  char *temp;
  temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

