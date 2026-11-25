# Problem 01: Insert an Element into an Array at a Specific Position

## Problem Statement
Take an array, an element and a position from the user. Insert the element at that position and print the updated array.

## How It Works
An array stores its elements side by side in memory. So we cannot just drop a new value into the middle of it — that would overwrite the old element sitting there. First we have to make some room.

To make room at position `pos`, we shift every element from that position onwards one step to the right. The shifting is done **from the end backwards** (`i = n` down to `pos`), because if we shifted from the front instead, each copy would erase the next element before we could move it.

After the shifting, the slot at `pos - 1` (0-based) is free, and we simply put the new element there and increase `n` by 1.

## Step by Step Logic
1. Read the array of size `n`.
2. Read the new element `x` and the position `pos`.
3. Validate the position — it must be between `1` and `n + 1` (we are allowed to insert at the very end too).
4. Shift elements right, from index `n` down to `pos`.
5. Store `x` at index `pos - 1` and increase `n`.
6. Print the array.

## Dry Run
Inserting 25 at position 3 in `10 20 30 40 50`:

| Step | Array |
|------|-------|
| Start | 10 20 30 40 50 |
| Shift 50 right | 10 20 30 40 __ 50 |
| Shift 40 right | 10 20 30 __ 40 50 |
| Shift 30 right | 10 20 __ 30 40 50 |
| Put 25 in the gap | 10 20 **25** 30 40 50 |

## Code File
[01_insert_element_at_position.cpp](../Problems/01_insert_element_at_position.cpp)

## Input
```
5
10 20 30 40 50
25
3
```

## Output
```
Enter the size of the array:
Enter 5 elements:
Enter the element to insert:
Enter the position (1 to 6):
Array after insertion: 10 20 25 30 40 50
```

## Edge Case Test
Trying to insert at position 9 in an array of size 4. Valid positions are 1 to 5 only, so the program rejects it instead of writing outside the array.

Input:
```
4
2 4 6 8
5
9
```

Output:
```
Enter the size of the array:
Enter 4 elements:
Enter the element to insert:
Enter the position (1 to 5):
Invalid position!
```
