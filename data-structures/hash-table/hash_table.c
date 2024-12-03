#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct node {
  int key;
  char value[100];
  struct node *next;
} node;

node *hash_table[TABLE_SIZE];

void init_hash_table();
int hash(int key);
void insert(int key, const char *value);
node *search(int key);
void delete(int key);
void print_hash_table();

int main(void) {

  init_hash_table();
  print_hash_table();

  insert(1, "Value1");
  insert(11, "Value11");
  insert(21, "Value21");
  insert(31, "Value31");

  print_hash_table();

  node *result = search(11);
  if (result != NULL) {
      printf("Found: Key %d, Value: %s\n", result->key, result->value);
  } else {
      printf("Key not found.\n");
  }

  delete(11);
  printf("After deleting key 11:\n");
  print_hash_table();

  return 0;
}

void init_hash_table() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }
}

int hash(int key) {
  return (key ^ (key >> 4)) % TABLE_SIZE;
}

void insert(int key, const char *value) {
  int index = hash(key);
  node *new_node = (node *) malloc(sizeof(node));
  new_node->key = key;
  strcpy(new_node->value, value);
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
}

node *search(int key) {
  int index = hash(key);
  node *current = hash_table[index];
  while (current != NULL) {
    if (current->key == key) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void delete(int key) {
  int index = hash(key);
  node *current = hash_table[index];
  node *previous = NULL;

  while (current != NULL) {
    if (current->key == key) {
      if(previous == NULL) {
        hash_table[index] = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      printf("Key %d deleted. \n", key);
      return;
    }
    previous = current;
    current = current->next;
  }
  printf("Key %d not found.", key);
}

void print_hash_table() {
  printf("---Start---\n");
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Index %d: ", i);
    node *current = hash_table[i];
    if (current == NULL) {
      printf("NULL\n");
    } else {
      while (current != NULL) {
        printf("(%d, %s) -> ", current->key, current->value);
        current = current->next;
      }
      printf("NULL\n");
    }
  }
  printf("---End---\n");
}