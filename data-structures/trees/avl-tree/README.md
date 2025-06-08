# AVL Tree

## What is AVL tree?
The AVL tree is named after its inventors, George Adelson-Velsky and Evgenii Landis. It is a self-balancing binary search tree where the height difference between left and right subtrees is at most one, ensuring O(log(n)) operations via rotations.

## What is Balanced Binary Search Tree?
A balanced binary search tree (BBST) is a binary search tree that keeps its height near logarithmic (O(log(n))) through balancing mechanisms like rotations.

## When and where AVL trees used?
AVL trees are used in applications requiring fast search, insertion, and deletion operations with guaranteed O(log n) performance, such as:

- **Databases**: For indexing and quick data retrieval.
- **Memory Management**: In operating systems for efficient resource allocation.
- **Compilers**: For symbol table management.

## Complexity

| Operation | Average   | Worst      |
| --------- | --------- | ---------- |
| Insert    | O(log(n)) |  O(log(n)) |
| Delete    | O(log(n)) |  O(log(n)) |
| Remove    | O(log(n)) |  O(log(n)) |
| Search    | O(log(n)) |  O(log(n)) |