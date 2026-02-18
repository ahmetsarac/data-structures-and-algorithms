#include <stdio.h>

int binary_search(int array[], int size, int target);

int main() {

  int array[] = {1, 3, 5, 7, 11, 14, 21};
  int size = sizeof(array) / sizeof(array[0]);
  int target = 14;

  int index = binary_search(array, size, target);

  if (index != -1) {
    printf("Element found at index %d\n", index);
  } else {
    printf("Element not found\n");
  }

  return 0;
}

int binary_search(int array[], int size, int target) {
  int left = 0;
  int right = size - 1;
  int mid;

  while (left <= right) {
    mid = left + (right - left) / 2;

    if (array[mid] == target) {
      return mid;
    } else if (array[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}