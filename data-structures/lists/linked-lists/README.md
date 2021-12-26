# Linked Lists

## What is a linked list?
A linked list is a sequentially connected nodes that are holding datas and the next node's address.

```
Node               Node
-----------        -----------        
|Data     |        |Data     |
|Next Node|------->|Next Node|-------> NULL
-----------        -----------
```

We generally use linked lists for implementing lists, queue and stack structures.

We call the first node as **head**, the last node as **tail**. It is not a compulsory thing but is a little terminology and convention.

## Singly vs Doubly Linked Lists
Singly linked lists only contains the data and next node's address, however doubly linked lists contains the data, the next node and the previous node's address.

They has pros and cons to each other. 

Singly linked lists use less memory but it takes more time to traverse the list.

Doubly linked lists use more memory but it takes less time to traverse through the previous node.

## Complexities

| Operation | Complexity |
|-----------|------------|
| Access    | O(n)       |
| Insertion | O(n)       |
| Deletion  | O(n)       |
| Search    | O(n)       |
