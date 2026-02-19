# What is Insertion Sort?
Insertion Sort is a simple comparison-based sorting algorithm. It builds the sorted portion of the array one element at a time, by inserting each new element into its correct position among the already sorted elements.

## How Insertion Sort Works
1. Assume the first element is already sorted.
2. Take the next element (key).
3. Compare the key with elements in the sorted portion.
4. Shift elements that are greater than the key one position to the right.
5. Insert the key into its correct position.
6. Repeat until all elements are processed.

## Time Complexity
* Best Case: O(n) The array is already sorted, so only one comparison per element is needed.
* Average Case: O(n²) Elements are in random order.
* Worst Case: O(n²) The array is sorted in reverse order.

## Space Complexity
* Space Complexity: O(1) Insertion sort is an in-place algorithm and uses constant extra space.
