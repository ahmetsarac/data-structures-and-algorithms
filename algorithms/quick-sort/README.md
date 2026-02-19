# What is Quick Sort?
Quick Sort is a divide-and-conquer sorting algorithm. It selects a pivot element, partitions the array around it, and recursively sorts the subarrays.

## How Quick Sort Works
1. Choose a pivot element.
2. Rearrange the array so that:
    * Elements smaller than pivot go to the left.
    * Elements greater than pivot go to the right.
3. The pivot is now in its correct sorted position.
4. Recursively apply Quick Sort to:
    * Left subarray
    * Right subarray

## Time Complexity
Best Case: O(n log n)
* Pivot splits array evenly.
* Recursion depth = log n
* Each level processes n elements.

Average Case: O(n log n)
* Random pivot distribution.

Worst Case: O(n²)
* Pivot is always smallest or largest.
* Example: already sorted array + last-element pivot.
* Recursion depth becomes n.

## Space Complexity
Average Case: O(log n)
* Due to recursion stack.
Worst Case: O(n)
* If recursion becomes linear (unbalanced partitions).
