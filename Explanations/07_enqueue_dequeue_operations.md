# Problem 07: Perform Enqueue and Dequeue Operations in a Queue

## Problem Statement
Implement both basic queue operations — enqueue (insert at rear) and dequeue (remove from front) — on an array-based queue, with proper overflow and underflow checking.

## How It Works
The queue uses two indices on one array:

- `front` — index of the element that will leave next,
- `rear` — index of the last element that joined.

**Enqueue:** if `rear == cap - 1`, the array is full → *Queue Overflow*. Otherwise increase `rear` and store the new element there.

**Dequeue:** if `front > rear`, both pointers have crossed, meaning the queue is empty → *Queue Underflow*. Otherwise print `q[front]` and increase `front`.

**Display:** print everything from `q[front]` to `q[rear]`.

This is a simple linear queue (no circular wrap-around): slots freed at the front are not reused. That keeps the code short, which is fine for this lab.

## Step by Step Logic
1. Read capacity, set `front = 0`, `rear = -1` (empty).
2. Loop the menu: enqueue, dequeue, display, or exit.
3. Enqueue → overflow check, then `q[++rear] = x`.
4. Dequeue → underflow check, then take `q[front++]`.
5. Display → loop from `front` to `rear`.

## Dry Run
Capacity 3 — enqueue 10, enqueue 20, dequeue, enqueue 30, try to enqueue again:

| Operation | front | rear | Queue |
|-----------|-------|------|-------|
| Enqueue 10 | 0 | 0 | 10 |
| Enqueue 20 | 0 | 1 | 10 20 |
| Dequeue (10 leaves) | 1 | 1 | 20 |
| Enqueue 30 | 1 | 2 | 20 30 |
| Enqueue again | 1 | 2 | **Overflow!** (rear = cap − 1) |

## Code File
[07_enqueue_dequeue_operations.cpp](../Problems/07_enqueue_dequeue_operations.cpp)

## Input
```
3
1 10
1 20
2
1 30
1
3
2
2
2
4
```

## Output
```
Enter the capacity of the queue:
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Enter the element:
10 enqueued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Enter the element:
20 enqueued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
10 dequeued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Enter the element:
30 enqueued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Queue Overflow!
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Queue: 20 30
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
20 dequeued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
30 dequeued.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Queue Underflow!
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
```

## Edge Case Test
Calling dequeue on a queue that was never filled. `front (0) > rear (−1)`, so the program reports **Queue Underflow** instead of printing some garbage value, and an empty display follows.

Input:
```
2
2
3
4
```

Output:
```
Enter the capacity of the queue:
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Queue Underflow!
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
Queue is empty.
1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
```
