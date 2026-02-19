#include <stdio.h>

void swap(int *a, int *b);
int partition(int array[], int low, int high);
void quick_sort(int array[], int low, int high);

int main() {

  int array[] = {10, 7, 8, 9, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);
  
  quick_sort(array, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return i + 1;
}

void quick_sort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);

    quick_sort(array, low, pi - 1);
    quick_sort(array, pi + 1, high);
  }
}