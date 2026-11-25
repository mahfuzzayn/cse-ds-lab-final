# Problem 18: Insertion Sort in Ascending Order

## Problem Statement
Sort an array in ascending order using insertion sort.

## How It Works
Insertion sort works the way people usually sort playing cards in their hand: the left part of the array is kept **sorted**, and each new element is picked up and inserted into its correct spot inside that sorted part.

For every position `i` (starting from 1):

1. Pick `key = a[i]` — the card we are about to insert.
2. Walk leftwards through the sorted part. Every element **bigger** than `key` is shifted one step to the right (`a[j+1] = a[j]`), opening a gap.
3. As soon as we reach an element `<= key` (or the array start), drop `key` into the gap.

The shifting is what makes room for the insertion — note that `key` is saved first, because otherwise the shifting would overwrite it.

Also note the loop condition `j >= 0 && a[j] > key`: `j >= 0` must come first. If the two were swapped, C++ would read `a[-1]` when `j` reaches −1 — a classic mistake.

## Step by Step Logic
1. Read the array.
2. For `i = 1` to `n - 1`: save `key = a[i]`; shift bigger elements right; place `key`.
3. Print the sorted array.

## Dry Run
Array `12 45 7 23 9 15` (the sorted left part is underlined):

| i | key | After inserting |
|---|-----|-----------------|
| 1 | 45 | <u>12 45</u> 7 23 9 15 |
| 2 | 7 | <u>7 12 45</u> 23 9 15 |
| 3 | 23 | <u>7 12 23 45</u> 9 15 |
| 4 | 9 | <u>7 9 12 23 45</u> 15 |
| 5 | 15 | <u>7 9 12 15 23 45</u> |

## Code File
[18_insertion_sort.cpp](../Problems/18_insertion_sort.cpp)

## Input
```
6
12 45 7 23 9 15
```

## Output
```
Enter the size of the array:
Enter 6 elements:
Array after insertion sort: 7 9 12 15 23 45
```

## Edge Case Test
A reverse-sorted array — the worst case for insertion sort, since every element must travel all the way to the front. The algorithm still produces the correct ascending result.

Input:
```
5
9 7 5 3 1
```

Output:
```
Enter the size of the array:
Enter 5 elements:
Array after insertion sort: 1 3 5 7 9
```
