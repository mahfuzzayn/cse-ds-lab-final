# Problem 05: Calculate the Average of Stack Elements

## Problem Statement
Push elements into a stack, then calculate both the sum and the average of the stack elements.

## How It Works
Same as the sum problem, but with one extra step at the end: divide the sum by the number of elements, which is `top + 1` (because `top` is an index, so the count is one more than it).

One small trap here. If we write `sum / (top + 1)` with both sides being `int`, C++ does **integer division** and throws away the decimal part (31 / 3 would give 10, not 10.33). So the sum is cast to `double` before dividing:

```
avg = (double)sum / (top + 1);
```

Now the division happens in floating point and the decimal part survives. The empty-stack check is done first, so we never divide by zero.

## Step by Step Logic
1. Read `n` and push each element onto the stack (`top++`, then `st[top] = x`).
2. If `top == -1`, print "Stack is empty." and stop.
3. Add `st[0]` to `st[top]` into `sum`.
4. Divide: `avg = (double)sum / (top + 1)`.
5. Print the sum and the average.

## Dry Run
Stack `7 10 14` (top is 14, count = 3):

sum = 7 + 10 + 14 = 31, average = 31 / 3 = **10.3333**

## Code File
[05_average_of_stack_elements.cpp](../Problems/05_average_of_stack_elements.cpp)

## Input
```
3
7 10 14
```

## Output
```
Enter the number of elements:
Enter 3 elements:
Sum of stack elements = 31
Average of stack elements = 10.3333
```

## Edge Case Test
Zero elements. With an empty stack there is nothing to average, and the program exits with the empty message before any division happens — so there is no divide-by-zero situation.

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
