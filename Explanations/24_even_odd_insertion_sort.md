# Problem 24: Arrange Even Numbers First and Odd Numbers Later Using Insertion Sort

## Problem Statement
Rearrange an array so that all even numbers come first and all odd numbers come later — using the insertion sort technique. The relative order inside each group must stay as it was.

## How It Works
The trick is to look at ordinary insertion sort and change only the **comparison**. In normal insertion sort, `key` is inserted into the sorted left part by shifting every element **greater** than it to the right.

Here, "greater" is replaced by "odd": an even `key` is inserted into the left part by shifting every **odd** element to the right, until we bump into another even element (or the start of the array). So:

- The left part of the array becomes the "even zone" — evens keep arriving in their original order.
- Odd elements simply get pushed right and keep their relative order.

In code terms, the while condition `a[j] % 2 != 0` replaces the usual `a[j] > key`, and the whole insertion block only runs when `key % 2 == 0` — an odd `key` needs no work at all.

The remainder test is safe for negative numbers too: `-4 % 2` is 0 (even), and `-3 % 2` is −1 (non-zero → odd).

## Step by Step Logic
1. Read the array.
2. For `i = 1` to `n - 1`: if `a[i]` is even, save `key = a[i]`; shift the odd elements on its left one step right; drop `key` after the last even.
3. Print the arranged array.

## Dry Run
Array `7 2 9 4 6 1 3 8`:

| i | key | Action | Array |
|---|-----|--------|-------|
| 1 | 2 (even) | shift 7 right, put 2 in front | 2 7 9 4 6 1 3 8 |
| 3 | 4 (even) | shift 9, 7 right | 2 4 7 9 6 1 3 8 |
| 4 | 6 (even) | shift 9, 7 right | 2 4 6 7 9 1 3 8 |
| 7 | 8 (even) | shift 3, 1, 9, 7 right | **2 4 6 8 7 9 1 3** |

Evens `2 4 6 8` (original order), odds `7 9 1 3` (original order).

## Code File
[24_even_odd_insertion_sort.cpp](../Problems/24_even_odd_insertion_sort.cpp)

## Input
```
8
7 2 9 4 6 1 3 8
```

## Output
```
Enter the size of the array:
Enter 8 elements:
Array after arranging: 2 4 6 8 7 9 1 3
```

## Edge Case Test
Negative numbers, including negative evens (`-2 5 -4 3`). The `% 2` checks classify −2 and −4 correctly as even (their remainder is 0), so they still move to the front while the odds stay behind.

Input:
```
4
-2 5 -4 3
```

Output:
```
Enter the size of the array:
Enter 4 elements:
Array after arranging: -2 -4 5 3
```
