# Problem 15: Binary Search in Descending Order

## Problem Statement
Search for an element in an array sorted in **descending** order (largest to smallest) using binary search.

## How It Works
The overall plan is the same as binary search on an ascending array: keep an interval `low..high`, check the middle element, and throw away the half that cannot contain the target.

The only thing that changes is the direction logic, because the array now "grows" the other way:

- Ascending array: `a[mid] < x` → search the **right** half.
- Descending array: `a[mid] > x` → search the **right** half (the smaller values live on the right).

So the two branches simply swap places:

| Case | Ascending array | Descending array |
|------|-----------------|------------------|
| a[mid] == x | found | found |
| a[mid] < x | low = mid + 1 | high = mid - 1 |
| a[mid] > x | high = mid - 1 | low = mid + 1 |

Everything else — the `low <= high` loop condition, the not-found detection, the 1-based position print — stays identical.

## Step by Step Logic
1. Read the descending array and `x`.
2. `low = 0`, `high = n - 1`, `pos = -1`.
3. While `low <= high`: `mid = (low + high) / 2`; if equal, record and break; if `a[mid] > x` go right, else go left.
4. Print the position or the not-found message.

## Dry Run
Array `38 23 16 12 8 5`, searching for 12:

| low | high | mid | a[mid] | Decision |
|-----|------|-----|--------|----------|
| 0 | 5 | 2 | 16 | 16 > 12 → go right, low = 3 |
| 3 | 5 | 4 | 8 | 8 < 12 → go left, high = 3 |
| 3 | 3 | 3 | **12** | Found at index 3 → position 4 |

## Code File
[15_binary_search_descending.cpp](../Problems/15_binary_search_descending.cpp)

## Input
```
6
38 23 16 12 8 5
12
```

## Output
```
Enter the size of the array:
Enter 6 elements in descending order:
Enter the element to search:
12 is found at position 4.
```

## Edge Case Test
Searching for 40, which is larger than every element in the array. Every comparison sends the search left until `high` drops below `low`, and the not-found branch runs.

Input:
```
6
38 23 16 12 8 5
40
```

Output:
```
Enter the size of the array:
Enter 6 elements in descending order:
Enter the element to search:
40 is not found in the array.
```
