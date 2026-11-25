# Problem 08: Move the First Element of a Queue to the Rear

## Problem Statement
Take a queue and move its front (first) element to the rear (end), then print the resulting queue.

## How It Works
Moving the front element to the rear is really just a dequeue followed by an enqueue of the same value. With the queue kept in an array, the cleanest way to do this is:

1. Save the first element `q[0]` in `temp` (this is the "dequeue" part).
2. Shift every remaining element one step to the left — each `q[i]` takes the value of `q[i + 1]`. After the shift the old second element is the new front.
3. Put `temp` into the last slot `q[n - 1]` (this is the "enqueue" part).

The queue `10 20 30 40 50` becomes `20 30 40 50 10`.

The `n < 1` check is there because with an empty queue there is no first element to move, and the left-shift loop would touch a negative index.

## Step by Step Logic
1. Read `n` and the elements.
2. If `n < 1`, print "Queue is empty." and stop.
3. `temp = q[0]`.
4. For `i = 0` to `n - 2`: `q[i] = q[i + 1]`.
5. `q[n - 1] = temp`.
6. Print the queue.

## Dry Run
Queue `10 20 30 40 50`:

| Step | Queue |
|------|-------|
| temp = 10 | 10 20 30 40 50 |
| Shift 20 left | 20 20 30 40 50 |
| Shift 30 left | 20 30 30 40 50 |
| Shift 40 left | 20 30 40 40 50 |
| Shift 50 left | 20 30 40 50 50 |
| Put 10 at rear | 20 30 40 50 **10** |

## Code File
[08_move_front_to_rear.cpp](../Problems/08_move_front_to_rear.cpp)

## Input
```
5
10 20 30 40 50
```

## Output
```
Enter the size of the queue:
Enter 5 elements:
Queue after moving the first element to the rear: 20 30 40 50 10
```

## Edge Case Test
A queue with only one element. The single element is both the front and the rear, so after the operation the queue looks exactly the same — the shift loop simply never runs.

Input:
```
1
7
```

Output:
```
Enter the size of the queue:
Enter 1 elements:
Queue after moving the first element to the rear: 7
```
