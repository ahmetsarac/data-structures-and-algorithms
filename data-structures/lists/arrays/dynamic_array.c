#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} dynamic_array;

void print_array(dynamic_array array);
void dynamic_array_init(dynamic_array *array);
void dynamic_array_add(dynamic_array *array, int item);
void dynamic_array_delete(dynamic_array *array, int index);
void dynamic_array_free(dynamic_array *array);

int main() {

    dynamic_array array;

    dynamic_array_init(&array);
    for (int i = 0; i < 10; i++) {
        dynamic_array_add(&array, i);
    }

    print_array(array);

    dynamic_array_delete(&array, 1);
    dynamic_array_delete(&array, 2);

    print_array(array);

    dynamic_array_add(&array, 27);

    array.array[4] = 25;

    print_array(array);

    dynamic_array_free(&array);

    return 0;
}

void print_array(dynamic_array array) {
    printf("---Array start---\n");
    for (int i = 0; i < array.size; i++) {
        printf("Value: %i\n", array.array[i]);
    }
    printf("Size: %i\n", array.size);
    printf("---Array end---\n");
}

void dynamic_array_init(dynamic_array *array) {

    int *int_pointer = (int *)malloc(sizeof(int));

    if (int_pointer != NULL) {
        array->array = int_pointer;
        array->size = 0;
    } else {
        printf("Memory allocation error.");
        free(int_pointer);
        exit(0);
    }
}

void dynamic_array_add(dynamic_array *array, int item) {

    int *int_pointer = (int *)realloc(array->array, ++(array->size) * sizeof(int));

    if (int_pointer != NULL) {
        array->array = int_pointer;
        array->array[array->size - 1] = item;
    } else {
        printf("Memory allocation error.");
        free(int_pointer);
        array->size--;
        exit(0);
    }
}

void dynamic_array_delete(dynamic_array *array, int index) {
    dynamic_array temp;
    int *int_pointer;

    dynamic_array_init(&temp);

    for (int i = index; i < array->size; i++) {
        array->array[i] = array->array[i + 1];
    }

    array->size--;

    for (int i = 0; i < array->size; i++) {
        dynamic_array_add(&temp, array->array[i]);
    }

    int_pointer = (int *)realloc(temp.array, temp.size * sizeof(int));

    if (int_pointer != NULL) {
        array->array = int_pointer;
    } else {
        printf("Memory allocation error.");
        free(int_pointer);
        exit(0);
    }
}

void dynamic_array_free(dynamic_array *array) {
    free(array->array);
    array->array = NULL;
    array->size = 0;
}
