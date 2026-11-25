# Problem 20: Display Array After Each Pass of Selection Sort

## Problem Statement
Sort an array using selection sort and print the state of the array after **every pass**, so the progress of the algorithm can be seen step by step.

## How It Works
This is the same selection sort as Problem 19 — select the minimum of the unsorted zone, swap it to the front — with one extra line: right after each pass finishes (and the possible swap is done), the whole array is printed with a pass counter.

Reading the output shows the algorithm converging: in each printed line, the underlined-style sorted prefix on the left grows by one element, and eventually the last line shows the fully sorted array.

One interesting detail visible in the sample output: **Pass 3 looks identical to Pass 2**. That is not a bug — on that pass the minimum (14) was already sitting at the right index, the `m != i` check skipped the swap, so the array simply did not change. The pass still prints, because a pass happened.

Also note: with a single-element array the pass loop `i < n - 1` never runs at all, so no "Pass" lines print and only the final (trivially sorted) array appears — which is exactly the right behaviour, since one element is always sorted.

## Step by Step Logic
1. Read the array.
2. For each pass `i`: find the minimum index `m` in the rest of the array; swap if `m != i`; print "Pass i+1: " and the array.
3. Print the final sorted array.

## Dry Run
Array `29 10 14 37 13`:

| Pass | Action | Array printed |
|------|--------|---------------|
| 1 | swap 29 ↔ 10 | 10 29 14 37 13 |
| 2 | swap 29 ↔ 13 | 10 13 14 37 29 |
| 3 | 14 already in place, no swap | 10 13 14 37 29 |
| 4 | swap 37 ↔ 29 | 10 13 14 29 37 |

## Code File
[20_selection_sort_passes.cpp](../Problems/20_selection_sort_passes.cpp)

## Input
```
5
29 10 14 37 13
```

## Output
```
Enter the size of the array:
Enter 5 elements:
Pass 1: 10 29 14 37 13
Pass 2: 10 13 14 37 29
Pass 3: 10 13 14 37 29
Pass 4: 10 13 14 29 37
Sorted array: 10 13 14 29 37
```

## Edge Case Test
A one-element array. The pass loop condition `i < n - 1` is false from the start, so no passes are printed — a single element is already sorted, and only the final line appears.

Input:
```
1
7
```

Output:
```
Enter the size of the array:
Enter 1 elements:
Sorted array: 7
```
