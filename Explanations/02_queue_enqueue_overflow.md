# Problem 02: Queue Enqueue Operation with Overflow Checking

## Problem Statement
Implement the enqueue operation of a queue using an array, and check for overflow before inserting.

## How It Works
A queue is a FIFO (First In First Out) line — new elements join at the **rear** and leave from the **front**.

Here the queue is stored in an array and `rear` works as a counter of how many elements are currently inside (elements sit at index `0` to `rear - 1`). Enqueue is simple:

- **Overflow check first:** if `rear == cap`, the array is already full, so we print an overflow message and refuse the operation. The check happens *before* asking for the element, so a full queue never stores anything outside its limit.
- Otherwise, read the element, store it at `q[rear]`, and increase `rear` by 1.

The program runs in a small menu loop (enqueue / display / exit) so several operations can be tested in one run.

## Step by Step Logic
1. Read the capacity of the queue.
2. Start with `rear = 0` (empty queue).
3. In a loop, read the user's choice.
4. If enqueue: check `rear == cap`. If yes, print overflow. If no, store at `q[rear]` and do `rear++`.
5. If display: print `q[0]` to `q[rear - 1]` (or "Queue is empty." when `rear` is 0).
6. Exit stops the loop.

## Dry Run
Queue of capacity 3, enqueueing 10, 20, 30, 40:

| Operation | rear | Queue |
|-----------|------|-------|
| Enqueue 10 | 1 | 10 |
| Enqueue 20 | 2 | 10 20 |
| Enqueue 30 | 3 | 10 20 30 |
| Enqueue 40 | 3 | 10 20 30 → **Overflow!** |

## Code File
[02_queue_enqueue_overflow.cpp](../Problems/02_queue_enqueue_overflow.cpp)

## Input
```
3
1 10
1 20
1 30
1
2
3
```

## Output
```
Enter the capacity of the queue:
1. Enqueue  2. Display  3. Exit
Enter choice:
Enter the element:
10 enqueued successfully.
1. Enqueue  2. Display  3. Exit
Enter choice:
Enter the element:
20 enqueued successfully.
1. Enqueue  2. Display  3. Exit
Enter choice:
Enter the element:
30 enqueued successfully.
1. Enqueue  2. Display  3. Exit
Enter choice:
Queue Overflow! Cannot enqueue more elements.
1. Enqueue  2. Display  3. Exit
Enter choice:
Queue: 10 20 30
1. Enqueue  2. Display  3. Exit
Enter choice:
```

## Edge Case Test
Displaying a queue that is still empty. `rear` is 0, so the program prints "Queue is empty." instead of printing garbage values.

Input:
```
2
2
3
```

Output:
```
Enter the capacity of the queue:
1. Enqueue  2. Display  3. Exit
Enter choice:
Queue is empty.
1. Enqueue  2. Display  3. Exit
Enter choice:
```
