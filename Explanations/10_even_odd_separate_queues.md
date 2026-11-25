# Problem 10: Separate Even and Odd Elements into Two Queues

## Problem Statement
Read an array of numbers and separate them into two queues — one holding all the even numbers and the other holding all the odd numbers, keeping the original order inside each queue.

## How It Works
A single pass through the input array is enough. For each element we check the remainder of division by 2:

- `a[i] % 2 == 0` → the number is **even** → enqueue into `q1`.
- otherwise → **odd** → enqueue into `q2`.

Enqueueing is just storing at the current rear position and moving the rear counter forward (`r1` and `r2` play that role for the two queues). Since we scan left to right, the relative order of the even numbers among themselves (and the odd ones among themselves) is preserved.

The remainder check also works for negative numbers: `-4 % 2` is 0 (even) and `-3 % 2` is −1, which is non-zero, so it correctly counts as odd.

## Step by Step Logic
1. Read `n` elements into array `a`.
2. Set `r1 = 0` and `r2 = 0` (both queues empty).
3. For each element: if `a[i] % 2 == 0` put it in `q1[r1++]`, else in `q2[r2++]`.
4. Print the even queue (`q1`), or "Even queue is empty." if `r1 == 0`.
5. Print the odd queue (`q2`), or "Odd queue is empty." if `r2 == 0`.

## Dry Run
Input `12 7 9 4 20 15 8`:

| Element | Even / Odd | Even queue | Odd queue |
|---------|-----------|------------|-----------|
| 12 | even | 12 | |
| 7 | odd | 12 | 7 |
| 9 | odd | 12 | 7 9 |
| 4 | even | 12 4 | 7 9 |
| 20 | even | 12 4 20 | 7 9 |
| 15 | odd | 12 4 20 | 7 9 15 |
| 8 | even | 12 4 20 8 | 7 9 15 |

## Code File
[10_even_odd_separate_queues.cpp](../Problems/10_even_odd_separate_queues.cpp)

## Input
```
7
12 7 9 4 20 15 8
```

## Output
```
Enter the size of the array:
Enter 7 elements:
Even queue: 12 4 20 8
Odd queue: 7 9 15
```

## Edge Case Test
An array with no even numbers at all (`3 5 7`). The even queue stays empty, so instead of printing a blank line the program reports "Even queue is empty." — and the odd queue still prints normally.

Input:
```
3
3 5 7
```

Output:
```
Enter the size of the array:
Enter 3 elements:
Even queue is empty.
Odd queue: 3 5 7
```
