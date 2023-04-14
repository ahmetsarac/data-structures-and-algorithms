# Stack

## What is a stack?
Stack is a data structure that stores the data in linear way. You can think the stack structure like a pile of plates. The new element comes to the top of the stack and the top element is removed when we try to remove an element. You can see the diagram below. The strucuture uses the LIFO(last in first out) behaviour. 
There are two main functions `push()` and `pop()`.  
`push()` adds a new element to the top of the stack.

`pop()` removes the element from the stack and return it.


```

                                                                            
                                                                           
                                   New Data was pushed to the stack       pop() function removed the top element
              First state          by using push() function.              and will return it.
                                   Top points to the new element          Top points to the element that 
                                                                          comes after the removed one.
                                                                           

           +--------------+            +--------------+                              +--------------+      
    Top -> |     Data     |     Top -> |   New Data   |                       Pop -> |   New Data   | 
           +--------------+            +--------------+                              +--------------+ 
           +--------------+            +--------------+                      
           |     Data     |            |     Data     |                      
           +--------------+            +--------------+                              +--------------+
           +--------------+            +--------------+                      Top ->  |     Data     |
           |     Data     |            |     Data     |                              +--------------+
           +--------------+            +--------------+                              +--------------+
                                       +--------------+                              |     Data     |
                                       |     Data     |                              +--------------+
                                       +--------------+                              +--------------+
                                                                                     |     Data     |
                                                                                     +--------------+

```

## What are some common uses of the stack?
A common example for the stack use case can be browser history. Browsers are using the stack the data structure to track browser history. Another example is call stacks for the programs. When you are trying to debug a program it is highly possible to check call stack for a bug. As the name shows that call stack is using the stack data structure.

## Complexities 

| Operation|  Complexity  | 
| -------- | ------------ | 
| Push     | O(1)         | 
| Pop      | O(1)         | 
| Peek     | O(1)         | 
| Search   | O(n)         | 
