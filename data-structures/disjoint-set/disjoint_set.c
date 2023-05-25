#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rank;
    int parent;
} set_element;

typedef struct {
    int size;
    set_element *elements;
} disjoint_set;

void init_set(disjoint_set **set, int n);
int find(disjoint_set *set, int index);
void union_sets(disjoint_set *set, int index_1, int index_2);

int main() {

    disjoint_set *set;

    init_set(&set, 10);

    union_sets(set, 1, 2);
    union_sets(set, 4, 5);
    union_sets(set, 8, 9);
    union_sets(set, 2, 4);

    if (find(set, 1) == find(set, 4)) {
        printf("Element 1 and Element 4 belong to the same set.\n");
    } else {
        printf("Element 1 and Element 4 don't belong to the same set.\n");
    }

    free(set->elements);
    free(set);

    return 0;
}

void init_set(disjoint_set **set, int n) {
    *set = (disjoint_set *)malloc(sizeof(disjoint_set));
    (*set)->size = n;
    (*set)->elements = (set_element *)malloc(n * sizeof(set_element));

    for (int i = 0; i < n; i++) {
        (*set)->elements[i].parent = i;
        (*set)->elements[i].rank = 0;
    }
}

int find(disjoint_set *set, int index) {
    int root = index;

    while (set->elements[root].parent != root) {
        root = set->elements[root].parent;
    }

    while (set->elements[index].parent != root) {
        int parent = set->elements[index].parent;
        set->elements[index].parent = root;
        index = parent;
    }

    return root;
}

void union_sets(disjoint_set *set, int index_1, int index_2) {
    int root_1 = find(set, index_1);
    int root_2 = find(set, index_2);

    if (set->elements[root_1].rank < set->elements[root_2].rank) {
        set->elements[root_1].parent = root_2;
    } else if (set->elements[root_1].rank > set->elements[root_2].rank) {
        set->elements[root_2].parent = root_1;
    } else {
        set->elements[root_2].parent = root_1;
        set->elements[root_1].rank++;
    }
}