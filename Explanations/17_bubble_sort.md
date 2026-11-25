# Problem 17: Bubble Sort in Ascending Order

## Problem Statement
Sort an array in ascending order using bubble sort.

## How It Works
Bubble sort repeatedly walks through the array comparing **neighbours**. Whenever a pair is in the wrong order (`a[j] > a[j+1]`), the two values are swapped. With every full pass, the largest remaining element "bubbles up" to its final place at the end of the array.

That is why the inner loop shrinks after each pass: after pass `i` (counting from 0), the last `i + 1` positions are already final, so comparing them again would be wasted work. The inner loop condition `j < n - 1 - i` cuts them off.

Two nested loops give the well-known O(n²) comparisons. The name comes from the way big values bubble to the surface.

## Step by Step Logic
1. Read the array.
2. For `i = 0` to `n - 2` (each pass):
   - For `j = 0` to `n - 2 - i`: if `a[j] > a[j + 1]`, swap them.
3. Print the sorted array.

## Dry Run
Array `64 34 25 12 22`:

| Pass | Comparisons | Array after pass |
|------|-------------|------------------|
| 1 | 64>34 swap, 64>25 swap, 64>12 swap, 64>22 swap | 34 25 12 22 **64** |
| 2 | 34>25 swap, 34>12 swap, 34>22 swap | 25 12 22 **34 64** |
| 3 | 25>12 swap, 25>22 swap | 12 22 **25 34 64** |
| 4 | 12 < 22, no swap | **12 22 25 34 64** |

## Code File
[17_bubble_sort.cpp](../Problems/17_bubble_sort.cpp)

## Input
```
5
64 34 25 12 22
```

## Output
```
Enter the size of the array:
Enter 5 elements:
Array after bubble sort: 12 22 25 34 64
```

## Edge Case Test
An array with duplicate values (`5 2 5 1 2`). Because the swap only happens on a **strict** `>` comparison, equal neighbours are never swapped — the sort still finishes correctly, with duplicates kept side by side.

Input:
```
5
5 2 5 1 2
```

Output:
```
Enter the size of the array:
Enter 5 elements:
Array after bubble sort: 1 2 2 5 5
```
