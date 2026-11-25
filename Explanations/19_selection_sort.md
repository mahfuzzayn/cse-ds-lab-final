# Problem 19: Selection Sort in Ascending Order

## Problem Statement
Sort an array in ascending order using selection sort.

## How It Works
Selection sort splits the array into two zones: a sorted zone on the left that starts empty, and an unsorted zone covering the rest. On every pass it:

1. **Selects** the minimum element of the unsorted zone (scanning it fully, but only remembering *where* the minimum is — index `m`).
2. **Swaps** that minimum with the first element of the unsorted zone, which extends the sorted zone by one.

So after `n - 1` passes the whole array is sorted. Compared to bubble sort, selection sort makes the same O(n²) comparisons but at most **one swap per pass** (and the code skips even that with `if (m != i)` when the minimum is already in place) — much less data movement.

## Step by Step Logic
1. Read the array.
2. For `i = 0` to `n - 2`: assume `m = i`; scan `j` from `i + 1` and update `m` whenever `a[j] < a[m]`; swap `a[i]` with `a[m]` if needed.
3. Print the sorted array.

## Dry Run
Array `29 10 14 37 13` (sorted zone underlined):

| Pass | Minimum found | Swap | Array after |
|------|---------------|------|-------------|
| 1 | 10 (index 1) | 29 ↔ 10 | <u>10</u> 29 14 37 13 |
| 2 | 13 (index 4) | 29 ↔ 13 | <u>10 13</u> 14 37 29 |
| 3 | 14 (already at index 2) | none | <u>10 13 14</u> 37 29 |
| 4 | 29 (index 4) | 37 ↔ 29 | <u>10 13 14 29 37</u> |

## Code File
[19_selection_sort.cpp](../Problems/19_selection_sort.cpp)

## Input
```
5
29 10 14 37 13
```

## Output
```
Enter the size of the array:
Enter 5 elements:
Array after selection sort: 10 13 14 29 37
```

## Edge Case Test
An array where every element is equal (`5 5 5`). The strict `<` comparison never finds anything smaller than `a[m]`, `m` never changes, and thanks to the `m != i` guard not a single swap happens — the array stays as it is, correctly sorted.

Input:
```
3
5 5 5
```

Output:
```
Enter the size of the array:
Enter 3 elements:
Array after selection sort: 5 5 5
```
