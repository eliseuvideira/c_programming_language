#include <stdio.h>

#define LENGTH 100

int binsearch(int x, int arr[], int length);

int main() {
  int i;
  int arr[LENGTH];
  for (i = 0; i < LENGTH; ++i) {
    arr[i] = i * 2 + 1;
  }
  int x = 51;
  int pos;
  pos = binsearch(x, arr, LENGTH);
  if (pos != -1) {
    printf("arr contains %d at pos %d\n", x, pos);
  } else {
    printf("arr doesn't contain %d\n", x);
  }
  
  return 0;
}

int binsearch(int x, int arr[], int length) {
  int low, high, mid;

  low = 0;
  high = length - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < arr[mid]) {
      high = mid - 1;
    } else if (x > arr[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return - 1;
}
