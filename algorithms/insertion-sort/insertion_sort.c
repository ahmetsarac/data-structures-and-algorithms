#include <stdio.h>

void insertion_sort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = arr[j];
      j--;
    }

    array[j + 1] = key;
  }
}

int main() {
  int array[] = {12, 11, 13, 5, 6};
  int size = sizeof(array) / sizeof(arr[0]);

  insertion_sort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
