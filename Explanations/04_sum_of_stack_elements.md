# Problem 04: Calculate the Sum of Stack Elements

## Problem Statement
Push some elements into a stack and calculate the sum of all the stack elements.

## How It Works
The stack is an array with a `top` pointer. `top = -1` means the stack is empty. Every element we read is **pushed** the proper way: increase `top` first, then store the value at `st[top]`. So after reading `n` elements, they occupy `st[0]` to `st[n - 1]` and `top` is `n - 1`.

For the sum, we simply walk through the array from the bottom (`i = 0`) to the top and keep adding into `sum`. Addition does not care about order, so going bottom to top is fine — we are not popping anything, the stack stays intact.

The empty-stack check (`top == -1`) is done first, because summing an empty stack has no meaning and the program should say so rather than print a random 0.

## Step by Step Logic
1. Read `n`.
2. For each element: `top++` then `st[top] = x` (push operation).
3. If `top == -1`, print "Stack is empty." and stop.
4. Add up `st[0]` to `st[top]` into `sum`.
5. Print the sum.

## Dry Run
Stack `10 20 30 40 50` (top is 50):

sum = 0 + 10 = 10 → +20 = 30 → +30 = 60 → +40 = 100 → +50 = **150**

## Code File
[04_sum_of_stack_elements.cpp](../Problems/04_sum_of_stack_elements.cpp)

## Input
```
5
10 20 30 40 50
```

## Output
```
Enter the number of elements:
Enter 5 elements:
Sum of stack elements = 150
```

## Edge Case Test
Zero elements. Nothing is ever pushed, so `top` stays `-1` and the program correctly reports an empty stack instead of printing a meaningless sum.

Input:
```
0
```

Output:
```
Enter the number of elements:
Enter 0 elements:
Stack is empty.
```
