# Problem 21: Quick Sort in Ascending Order

## Problem Statement
Sort an array in ascending order using quick sort.

## How It Works
Quick sort is a divide-and-conquer algorithm. One function, `partition`, does the real work for a range `low..high`:

1. **Pick a pivot** — here the last element of the range (`a[high]`).
2. **Partition:** move every element smaller than the pivot to the left side, everything else to the right side. The code walks with index `j` and keeps index `i` pointing at the end of the "smaller than pivot" zone; whenever `a[j] < pivot`, `i` advances and swaps `a[i]` with `a[j]` to pull that element into the zone.
3. Finally the pivot is swapped to position `i + 1` — its **final sorted position**, because everything left of it is smaller and everything right of it is not.

Then `quickSort` calls itself on the two sides: `quickSort(low, p - 1)` and `quickSort(p + 1, high)`. The recursion stops when a range has fewer than two elements (`low >= high`), since one element (or none) is always sorted.

The array is declared **global** so that `main`, `partition` and `quickSort` all share it without passing it around — a common style for recursive programs in lab work.

## Step by Step Logic
1. Read the array.
2. Call `quickSort(0, n - 1)`.
3. `quickSort` partitions the range, then recurses on both halves.
4. Print the sorted array.

## Dry Run
First partition of `38 27 43 10 82 12 5 63` (pivot = 63):

- Elements smaller than 63 get pulled left one by one: 38, 27, 43, 10, 12, 5.
- Array becomes `38 27 43 10 12 5 82 63`, then the pivot swaps with 82:
- `38 27 43 10 12 5 63 82` — 63 is now at its final index 6.
- The same process then runs on the left part `[38 27 43 10 12 5]` recursively.

## Code File
[21_quick_sort.cpp](../Problems/21_quick_sort.cpp)

## Input
```
8
38 27 43 10 82 12 5 63
```

## Output
```
Enter the size of the array:
Enter 8 elements:
Array after quick sort: 5 10 12 27 38 43 63 82
```

## Edge Case Test
An array with duplicate values (`7 2 7 1`). The partition uses a strict `< pivot` comparison, so duplicates of the pivot end up safely on the right side — duplicates never break the sort.

Input:
```
4
7 2 7 1
```

Output:
```
Enter the size of the array:
Enter 4 elements:
Array after quick sort: 1 2 7 7
```
