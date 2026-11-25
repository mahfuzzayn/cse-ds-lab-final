# Problem 09: Reverse a Queue Using a Stack

## Problem Statement
Reverse the order of the elements of a queue, and the reversal must be done using a stack.

## How It Works
This problem is actually a nice demonstration of how opposite the two structures are:

- A **queue** is FIFO — elements come out in the same order they went in.
- A **stack** is LIFO — elements come out in the opposite order they went in.

So if we pour a whole queue into a stack and then pour the stack back into the queue, the order flips once coming out of the stack — and never flips back. That is exactly the trick:

1. **Round 1:** dequeue every element from the front of the queue and push it into the stack. The stack now holds the queue upside-down.
2. **Round 2:** pop the stack one by one and enqueue each value at the rear of the (now empty) queue.

Because popping gives the values back-to-front, the rebuilt queue comes out reversed.

In the code, the queue is `q` with `front`/`rear` indices, and `st` is the stack with `top`. After round 1, `front` and `rear` are reset so the same array can be refilled from index 0.

## Step by Step Logic
1. Read the queue and set `front = 0`, `rear = n - 1`, `top = -1`.
2. Print the queue (before reverse).
3. While `front <= rear`: push `q[front]` onto the stack, `front++`.
4. Reset: `front = 0`, `rear = -1`.
5. While `top != -1`: `q[++rear] = st[top--]`.
6. Print the queue (after reverse).

## Dry Run
Queue `10 20 30 40 50`:

| Action | Stack (top on right) | Queue |
|--------|----------------------|-------|
| Dequeue 10 → push | 10 | 20 30 40 50 |
| Dequeue 20 → push | 10 20 | 30 40 50 |
| Dequeue 30 → push | 10 20 30 | 40 50 |
| Dequeue 40 → push | 10 20 30 40 | 50 |
| Dequeue 50 → push | 10 20 30 40 50 | (empty) |
| Pop 50 → enqueue | 10 20 30 40 | 50 |
| Pop 40 → enqueue | 10 20 30 | 50 40 |
| ... continue ... | — | **50 40 30 20 10** |

## Code File
[09_reverse_queue_with_stack.cpp](../Problems/09_reverse_queue_with_stack.cpp)

## Input
```
5
10 20 30 40 50
```

## Output
```
Enter the size of the queue:
Enter 5 elements:
Queue before reverse: 10 20 30 40 50
Queue after reverse: 50 40 30 20 10
```

## Edge Case Test
The smallest non-empty queue, `5 9`. It reverses to `9 5` — showing the mechanism works even with two elements (and with one element the queue would simply stay the same).

Input:
```
2
5 9
```

Output:
```
Enter the size of the queue:
Enter 2 elements:
Queue before reverse: 5 9
Queue after reverse: 9 5
```
