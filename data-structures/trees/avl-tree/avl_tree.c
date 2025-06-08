#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  int height;
  struct node *left;
  struct node *right;
} node;

typedef struct avl {
  node *root;
} avl;

void init_avl(avl **tree);
node *create_node(int data);
int get_height(node *n);
int get_balance(node *n);
int max(int a, int b);
node *right_rotate(node *y);
node *left_rotate(node *x);
node *avl_insert(node *root, int data);
void insert(avl *tree, int data);
node *search(avl *tree, int key);
void in_order_traversal(node *root);
void print_avl(avl *tree);

int main(void) {
  avl *tree;
  init_avl(&tree);

  insert(tree, 50);
  insert(tree, 30);
  insert(tree, 20);
  insert(tree, 40);
  insert(tree, 70);
  insert(tree, 60);
  insert(tree, 80);

  print_avl(tree);

  node *found_node = search(tree, 40);
  if (found_node != NULL) {
    printf("Node with value 40 found in the tree.\n");
  } else {
    printf("Node with value 40 not found in the tree.\n");
  }

  return 0;
}

void init_avl(avl **tree) {
  *tree = (avl *)malloc(sizeof(avl));
  (*tree)->root = NULL;
}

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->height = 1;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

int get_height(node *n) { return (n == NULL) ? 0 : n->height; }

int max(int a, int b) { return (a > b) ? a : b; }

int get_balance(node *n) {
  return (n == NULL) ? 0 : get_height(n->left) - get_height(n->right);
}

node *right_rotate(node *y) {
  node *x = y->left;
  node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(get_height(y->left), get_height(y->right)) + 1;
  x->height = max(get_height(x->left), get_height(x->right)) + 1;

  return x;
}

node *left_rotate(node *x) {
  node *y = x->right;
  node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(get_height(x->left), get_height(x->right)) + 1;
  y->height = max(get_height(y->left), get_height(y->right)) + 1;

  return y;
}

node *avl_insert(node *root, int data) {
  if (root == NULL)
    return create_node(data);

  if (data < root->data)
    root->left = avl_insert(root->left, data);
  else if (data > root->data)
    root->right = avl_insert(root->right, data);
  else
    return root; // Duplicate

  root->height = 1 + max(get_height(root->left), get_height(root->right));

  int balance = get_balance(root);

  if (balance > 1 && data < root->left->data)
    return right_rotate(root);

  if (balance < -1 && data > root->right->data)
    return left_rotate(root);

  if (balance > 1 && data > root->left->data) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  if (balance < -1 && data < root->right->data) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

void insert(avl *tree, int data) { tree->root = avl_insert(tree->root, data); }

node *search(avl *tree, int key) {
  node *current = tree->root;

  while (current != NULL) {
    if (key == current->data)
      return current;
    else if (key < current->data)
      current = current->left;
    else
      current = current->right;
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

void print_avl(avl *tree) {
  printf("AVL In-order Traversal: ");
  in_order_traversal(tree->root);
  printf("\n");
}
