# Disjoint Set

## What is disjoint set?
Disjoint set is a data structure, also called as union-find or merge-find set, that stores a collection of disjoint sets. Let's try to understand with an example.

```
[1, 2, 3]
[4, 5]
[6, 7, 8]
[9, 10]
```

These sets are disjoint because they have no members in common.

Disjoint set supports two basic functionality.

1. ``find(x)``: Determine the parent of the ``x`` and return it. For example if ``[1, 2]`` is a set and ``1`` is parent of ``2`` then ``find(2)`` will return ``1``.
2. ``union(x, y)``: Join two subsets that contains ``x`` and ``y`` into a single subset also this operation can be called as merge. For example, union(4, 9) would combine ``[4, 5]`` and ``[9, 10]`` into a larger set like this ``[4, 5, 9, 10]``. 

## Where are disjoint sets used?

- Kruskal's minimum spanning tree algorithm
- Grid percolation
- Network connectivity
- Image processinga

## Complexities

| Operation             |  Complexity  | 
| --------------------- | ------------ | 
| Construction          | O(n)         | 
| Union                 | α(n)         | 
| Find                  | α(n)         | 

*α(n) amoritized constant time*