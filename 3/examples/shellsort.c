#include <stdio.h>

#define LENGTH 10

void shellsort(int arr[], int length);

int main() {
  int length = LENGTH;
  int arr[length];
  int i;

  for (i = 0; i < length; ++i) {
    arr[i] = i * -i * length;
  }

  for (i = 0; i < length; ++i) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  shellsort(arr, length);

  for (i = 0; i < length; ++i) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}

void shellsort(int arr[], int length) {
  int gap, i, j, temp;

  for (gap = length / 2; gap > 0; gap /= 2) {
    for (i = gap; i < length; ++i) {
      for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
        temp = arr[j];
        arr[j] = arr[j + gap];
        arr[j + gap] = temp;
      }
    }
  }
}

