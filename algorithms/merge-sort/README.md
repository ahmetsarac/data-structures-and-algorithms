# What is Merge Sort?
Merge Sort is a divide-and-conquer sorting algorithm. It divides the array into smaller subarrays, sorts them recursively, and then merges the sorted subarrays into one sorted array.

## How Merge Sort Works
1. Divide the array into two halves.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge the two sorted halves into a single sorted array.
5. Repeat until the entire array is sorted.

## Time Complexity
* Best Case: O(n log n) The array is always divided into two halves.
* Average Case: O(n log n) Independent of input order.
* Worst Case: O(n log n) Merge sort always performs the same number of operations.

## Space Complexity
* Space Complexity: O(n) Requires extra memory for temporary arrays during merging.
* Recursive Call Stack: O(log n) Due to recursive depth.
