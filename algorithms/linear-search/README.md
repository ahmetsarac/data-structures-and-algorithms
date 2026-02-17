# What is Linear Search?

It is a very straightforward algorithm that is used for search. It basically search for the target element in an array or list sequentially until the target is found or reach the end of the collection. It may not be a good solution for large datasets but it is very intuitive and easy to understand.

## How Linear Search Works?

1. Start at the first element of the array.
2. Compare the current element with the target.
3. If the current element matches the target return its index.
4. If the current element doesn't match with the target move to the next element.
5. Repeat the comparison until the end of collection is reached.
6. If the end of the collection is reached and no match found, report that element is not found in the collection (which is returning -1 in our case).

## Time and Space Complexity

- Best Case: O(1)
    
    The target is the first element.
- Average Case: O(n)
    
    The target is somewhere in the middle.
- Worst Case: O(n)
    
    The target is the last element.
- Space Complexity: O(1)
    
    Linear search uses constant amount of memory regardless of input size.