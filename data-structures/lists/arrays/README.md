# Arrays

## What is an array?
If we say arrays are the probably the most used data structures that wouldn't be wrong. We can say arrays are containers for our elements that has the same data type.
In some languages you can store the different data type in the same array. They are lines up on memory contiguously. Moreover, we can seperate arrays as static array and dynamic array.

## What is static array?
Static array is a fixed length array. We can only contain elements that much we chose before, we can't change the size of static arrays.

## What is dynamic array?
Dynamic array is variable length array. We can change the size after you created the array. We can add or remove element from the array. It is not possible on static array. 
While static arrays' size is fixed dynamic arrays' size can be changed by adding or removing element. 

Both arrays are indexable.

### What do you mean by indexable?
I mean indexes are referencing one element in the array. I think it is more clear with an example.

Let's say we have an array like this.
```
[2, 5, 7, 8, 10, 20]
```
Indexable means this : 
```
[2, 5, 7, 8, 10, 20]
 |  |  |  |   |   |
 0  1  2  3   4   5
```
`array[0]` refers to 2, `array[1]` refers to 5, `array[5]` refers to 20. I think you got this now. Indexes stars with 0 because it is the start point in the memory.

## Complexities

|          | Static Array | Dynamic Array |
| -------- | ------------ | ------------- |
| Access   | O(1)         | O(1)          |
| Adding   | X            | O(1)          |
| Deletion | X            | O(n)          |
| Search   | O(n)         | O(n)          |



You can view the example source codes from the links below.

[static_array.c](static_array.c)

[dynamic_array.c](dynamic_array.c)
