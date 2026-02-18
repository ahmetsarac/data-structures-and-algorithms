# What is Binary Search?

Binary search is a effecient searching algorithm that works on *sorted* collections. Instead of checking elements one by one like linear search it repeatedly divides the search into half which reduces the comparison amount. It is much faster than linear search for large datasets but it requires the collection to be sorted beforehand.

## How Binary Search Works?

1. Make sure the collection is sorted.
2. Set two pointers: one at the beginning of the collection, one at the end.
3. Find middle element of the current range.
4. Compare the middle element with the target.
5. If the middle element matches the target return the index.
6. If the middle element is smaller than the target continue searching the right half.
7. If the middle element is greater than the target contine searching the left half.
8. Repeat the process until the element is found or the search range becomes empty.
9. If the search range is empty and no match is found, report that the element is not found in the collection (which is returning -1 in our case).

## Time and Space Complexity

- Best Case: O(1)

    The target is found at the middle position in the first comparison.

- Average Case: O(log n)

    The search space is divided in half at each step.

- Worst Case: O(log n)

    The target element is either not present in the collection or is found only after narrowing the search down to the smallest possible range (last possible comparison).

- Space Complexity: O(1)

    Binary search uses a constant amount of memory when implemented iteratively.