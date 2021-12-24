#include <stdio.h>

#define N 5

void print_array(int array[], int n);

int main(int argc, char *argv[]) {

    int array[N] = {2, 5, 7, 8, 10};

    print_array(array, N);

    array[0] = 5;
    array[2] = 3;

    print_array(array, N);

    return 0;
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%i\n", array[i]);
    }
}
