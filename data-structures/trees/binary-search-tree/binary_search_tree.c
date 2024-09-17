#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct bst {
    node *root;
} bst;

void init_bst(bst **tree);
node *create_node(int data);
void insert(bst *tree, int data);
node *search(bst *tree, int key);
void in_order_traversal(node *root);
void print_bst(bst *tree);

int main(void) {

    bst *tree;
    init_bst(&tree);

    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 70);
    insert(tree, 60);
    insert(tree, 80);

    print_bst(tree);

    node *found_node = search(tree, 40);
    if (found_node != NULL) {
        printf("Node with value 40 found in the tree.\n");
    } else {
        printf("Node with value 40 not found in the tree.\n");
    }

    return 0;
}

void init_bst(bst **tree) {
    *tree = (struct bst *)malloc(sizeof(bst));
    (*tree)->root = NULL;
}

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(bst *tree, int data) {
    node *new_node = create_node(data);

    if (tree->root == NULL) {
        tree->root = new_node;
        return;
    }

    node *current = tree->root;
    node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            free(new_node);
            return;
        }
    }

    if (data < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

node *search(bst *tree, int key) {
    node *current = tree->root;

    while (current != NULL) {
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL;
}

void in_order_traversal(node *root) {
    if (root != NULL) {
        in_order_traversal(root->left);
        printf("%d ", root->data);
        in_order_traversal(root->right);
    }
}

void print_bst(bst *tree) {
    printf("BST In-order Traversal: ");
    in_order_traversal(tree->root);
    printf("\n");
}
