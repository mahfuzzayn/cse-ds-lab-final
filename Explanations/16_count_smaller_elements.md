# Problem 16: Count Elements Smaller Than a Given Value Using Binary Search

## Problem Statement
Given a sorted (ascending) array and a value `x`, count how many elements of the array are smaller than `x` — using binary search rather than a loop.

## How It Works
The key observation: in a sorted array, all the elements smaller than `x` sit together at the **front**. So the answer is not a count we build up — it is the **index of the first element that is not smaller than x** (the first element `>= x`).

Binary search finds that index quickly. During the search we maintain an `ans` variable, and the comparison is:

- If `a[mid] < x`: elements smaller than `x` extend at least up to `mid`, so the cut point is further right — `low = mid + 1`.
- If `a[mid] >= x`: the cut point is at `mid` **or somewhere left of it**, so save `ans = mid` as the best candidate so far and keep searching left with `high = mid - 1`.

When the loop ends, `ans` holds the first index with a value `>= x` — which is exactly the number of elements before it. `ans` starts at `n` to cover the case where *every* element is smaller than `x` (then no such index exists, and the answer stays `n`).

## Step by Step Logic
1. Read the sorted array and `x`.
2. `low = 0`, `high = n - 1`, `ans = n`.
3. While `low <= high`: if `a[mid] < x` move `low` right; else save `ans = mid` and move `high` left.
4. Print `ans`.

## Dry Run
Array `3 8 15 20 25 30 45`, x = 20:

| low | high | mid | a[mid] | Decision |
|-----|------|-----|--------|----------|
| 0 | 6 | 3 | 20 | 20 >= 20 → ans = 3, go left |
| 0 | 2 | 1 | 8 | 8 < 20 → go right, low = 2 |
| 2 | 2 | 2 | 15 | 15 < 20 → go right, low = 3 |
| 3 | 2 | — | — | loop ends |

`ans = 3` → the elements 3, 8, 15 (indices 0, 1, 2) are smaller than 20. ✓

## Code File
[16_count_smaller_elements.cpp](../Problems/16_count_smaller_elements.cpp)

## Input
```
7
3 8 15 20 25 30 45
20
```

## Output
```
Enter the size of the array:
Enter 7 elements in ascending order:
Enter the value:
Number of elements smaller than 20 = 3
```

## Edge Case Test
x = 50, which is larger than every element. No element ever satisfies `a[mid] >= 50`, `ans` never gets overwritten from its starting value `n`, and the answer is all 7 elements.

Input:
```
7
3 8 15 20 25 30 45
50
```

Output:
```
Enter the size of the array:
Enter 7 elements in ascending order:
Enter the value:
Number of elements smaller than 50 = 7
```
