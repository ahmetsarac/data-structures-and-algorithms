#include <stdio.h>

int linear_search(int array[], int size, int target);

int main() {

  int array[] = {2, 10, 24, 3, 8, 1};
  int size = sizeof(array) / sizeof(array[0]);
  int target = 24;

  int result = linear_search(array, size, target);

  if (result != -1) {
    printf("Found at index %d\n", result);
  } else {
    printf("Not found\n");
  }


  return 0;
}

int linear_search(int array[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (array[i] == target) {
      return i;
    }
  }

  return -1;
}
