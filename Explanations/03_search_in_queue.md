# Problem 03: Search an Element in a Queue

## Problem Statement
Store elements in a queue and search for a given element. If it is present, print its position from the front; otherwise print a not-found message.

## How It Works
The queue is kept in an array where index `0` is the front. Searching a queue is a simple linear walk: start at the front, compare each element with the search value, and stop as soon as a match is found.

A `found` flag is used to remember whether we ever matched. If the loop finishes without matching anything, the flag is still 0 and we print the "not present" message. The `break` makes sure only the **first** occurrence is reported (a queue position only makes sense for the first match).

## Step by Step Logic
1. Read `n` elements into the queue array.
2. Read the element `x` to search.
3. Loop `i` from 0 to `n - 1`.
4. If `q[i] == x`, print `i + 1` as the position (positions are counted 1-based from the front), set `found = 1` and break.
5. After the loop, if `found` is still 0, print the not-present message.

## Dry Run
Queue `12 5 8 20 9`, searching for 8:

| i | q[i] | Match? |
|---|------|--------|
| 0 | 12 | No |
| 1 | 5 | No |
| 2 | 8 | **Yes → position 3** |

## Code File
[03_search_in_queue.cpp](../Problems/03_search_in_queue.cpp)

## Input
```
5
12 5 8 20 9
8
```

## Output
```
Enter the size of the queue:
Enter 5 elements:
Enter the element to search:
8 found at position 3 from the front of the queue.
```

## Edge Case Test
Searching for an element that is not in the queue (100). The loop finishes with `found = 0`, so the program prints the not-present message instead of a wrong position.

Input:
```
5
12 5 8 20 9
100
```

Output:
```
Enter the size of the queue:
Enter 5 elements:
Enter the element to search:
100 is not present in the queue.
```
