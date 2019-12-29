#include <stdio.h>

void print_arr(int [], int);
void quick_sort(int [], int, int);

int main() {
  int v[] = {1, 5, 3, 2, 0, 9, 6, 150, 20, -5, 8, 15};

  quick_sort(v, 0, 11);

  return 0;
}

void print_arr(int v[], int len) {
  int i;
  for (i = 0; i < len; ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void quick_sort(int v[], int left, int right) {
  print_arr(v, 12);
  int i, last;
  void swap(int [], int, int);

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  print_arr(v, 12);
  last = left;
  for (i = left + 1; i <= right; ++i) {
    if (v[i] < v[left]) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  quick_sort(v, left, last - 1);
  quick_sort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

