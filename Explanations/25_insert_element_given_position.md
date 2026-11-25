# Problem 25: Insert an Element into an Array at a Given Position

## Problem Statement
Insert a new element into an array at a position given by the user and print the new array.

## How It Works
This is the same task as Problem 01, but solved with a **different technique** — instead of shifting elements inside the original array, we build the result in a second array `b`:

1. Copy the elements that come **before** the insertion position straight into `b`: `b[0..pos-2] = a[0..pos-2]`.
2. Put the new element `x` at `b[pos - 1]`.
3. Copy the rest of `a`, but each one step further right than it was: `b[i + 1] = a[i]` for `i = pos - 1 .. n - 1`.

So `b` ends up with `n + 1` elements and `a` is never touched.

The position is validated before anything is copied: it must be between `1` and `n + 1` (insertion at `n + 1` means appending at the very end). An invalid position stops the program with a message instead of reading or writing outside the arrays.

Comparing the two versions: Problem 01 works in place with a backwards shift (no extra array, but a bit more care with the loop direction), while this version uses an extra array but the copying is very easy to reason about. Both are standard student approaches to the same problem.

## Step by Step Logic
1. Read `n`, the array, the value `x` and the position `pos`.
2. Validate `pos` (1 to `n + 1`).
3. Copy the prefix into `b`, place `x`, copy the suffix shifted one step right.
4. Print `b` — it has `n + 1` elements now.

## Dry Run
Array `10 20 30 40`, insert 99 at position 1:

| Step | b |
|------|---|
| Copy prefix (nothing before position 1) | — |
| Place 99 at b[0] | 99 |
| Copy 10, 20, 30, 40 shifted right | 99 10 20 30 40 |

## Code File
[25_insert_element_given_position.cpp](../Problems/25_insert_element_given_position.cpp)

## Input
```
4
10 20 30 40
99
1
```

## Output
```
How many elements?
Enter 4 elements:
Enter the value to insert:
Enter the position:
New array: 99 10 20 30 40
```

## Edge Case Test
Trying to insert at position 10 in an array of size 4 — only positions 1 to 5 exist. The program rejects the request and exits before copying anything, so no out-of-range write ever happens.

Input:
```
4
10 20 30 40
55
10
```

Output:
```
How many elements?
Enter 4 elements:
Enter the value to insert:
Enter the position:
Invalid position!
```
