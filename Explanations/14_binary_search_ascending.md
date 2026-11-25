# Problem 14: Binary Search in Ascending Order

## Problem Statement
Search for an element in a **sorted (ascending)** array using binary search and report its position.

## How It Works
Binary search only works because the array is sorted — the ordering is what lets us throw away half of the remaining elements at every step.

We keep two markers, `low` and `high`, around the part of the array that could still contain the target. Then:

1. Look at the middle element `a[mid]`, where `mid = (low + high) / 2`.
2. If `a[mid] == x` — found.
3. If `a[mid] < x`, the target must be to the **right** (everything at or before `mid` is even smaller), so `low = mid + 1`.
4. If `a[mid] > x`, the target must be to the **left**, so `high = mid - 1`.
5. Repeat while `low <= high`. If the markers cross, the element is not in the array.

For 7 elements this needs at most 3 comparisons, against 7 for linear search. The saving grows fast: a million elements take about 20 steps.

## Step by Step Logic
1. Read the sorted array and `x`.
2. `low = 0`, `high = n - 1`, `pos = -1`.
3. While `low <= high`: compute `mid`, then follow the three cases above.
4. Print found (position `mid + 1`) or not found.

## Dry Run
Array `2 5 8 12 16 23 38`, searching for 16:

| low | high | mid | a[mid] | Decision |
|-----|------|-----|--------|----------|
| 0 | 6 | 3 | 12 | 12 < 16 → go right, low = 4 |
| 4 | 6 | 5 | 23 | 23 > 16 → go left, high = 4 |
| 4 | 4 | 4 | **16** | Found at index 4 → position 5 |

## Code File
[14_binary_search_ascending.cpp](../Problems/14_binary_search_ascending.cpp)

## Input
```
7
2 5 8 12 16 23 38
16
```

## Output
```
Enter the size of the array:
Enter 7 elements in ascending order:
Enter the element to search:
16 is found at position 5.
```

## Edge Case Test
Searching for 15, a value that falls between two array elements (12 and 16) but is not present. The interval keeps shrinking until `low > high`, proving the element is absent.

Input:
```
7
2 5 8 12 16 23 38
15
```

Output:
```
Enter the size of the array:
Enter 7 elements in ascending order:
Enter the element to search:
15 is not found in the array.
```
