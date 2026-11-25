# Problem 23: Find Elements That Changed Positions After Bubble Sort

## Problem Statement
Sort an array with bubble sort, then identify which elements of the original array ended up at a different position after sorting.

## How It Works
To compare "before" and "after", we obviously need both. So the original values are first copied into a second array `b` (line by line, `b[i] = a[i]`, done while reading the input). Then bubble sort rearranges **only `a`**, leaving `b` untouched as a snapshot of the original order.

After sorting, both arrays are compared **position by position**:

- If `a[i] != b[i]`, then the value that used to live at index `i` (that's `b[i]`) must have moved somewhere else — it changed position. We print it from `b`.
- If `a[i] == b[i]`, the same value occupies that slot in both versions, so that element did not move.

A `count` variable tracks how many elements moved. If nothing changed (the array was already sorted), the program prints "None" rather than an empty line.

Note the interpretation used here: the comparison is *value at index* in the original versus the sorted array. An element "changed position" when a different value now sits at its old index.

## Step by Step Logic
1. Read the array into `a` and copy every element into `b`.
2. Bubble sort `a`.
3. Print the sorted array.
4. For each index: if `b[i] != a[i]`, print `b[i]` and count it.
5. If the count is 0, print "None".

## Dry Run
Original `5 1 4 2 8` → sorted `1 2 4 5 8`:

| Index | b[i] (original) | a[i] (sorted) | Changed? |
|-------|-----------------|---------------|----------|
| 0 | 5 | 1 | yes → print **5** |
| 1 | 1 | 2 | yes → print **1** |
| 2 | 4 | 4 | no |
| 3 | 2 | 5 | yes → print **2** |
| 4 | 8 | 8 | no |

4 and 8 never moved — exactly what a trace of the bubble sort passes would show.

## Code File
[23_changed_positions_bubble_sort.cpp](../Problems/23_changed_positions_bubble_sort.cpp)

## Input
```
5
5 1 4 2 8
```

## Output
```
Enter the size of the array:
Enter 5 elements:
Sorted array: 1 2 4 5 8
Elements that changed position: 5 1 2
```

## Edge Case Test
An array that is **already sorted** (`1 2 3`). Bubble sort runs but performs zero swaps, every position matches, the counter stays 0, and the program reports "None".

Input:
```
3
1 2 3
```

Output:
```
Enter the size of the array:
Enter 3 elements:
Sorted array: 1 2 3
Elements that changed position: None
```
