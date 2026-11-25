# Problem 13: Linear Search and Identify the Element Position

## Problem Statement
Search for an element in an array using linear search and report the position where it is found.

## How It Works
Linear search is the most straightforward searching technique there is: compare the target with the first element, then the second, then the third... until either a match appears or the array ends.

The code uses a `pos` variable initialised to `-1`. That value doubles as a "not found" signal, because no real position can ever be negative. During the scan, the moment `a[i] == x`, we store `pos = i` and `break` — there is no reason to keep searching after the first match.

In the end, `pos == -1` means the element is absent; otherwise the position is `pos + 1`, because users count positions starting from 1 while array indices start from 0.

Linear search needs up to `n` comparisons (O(n)). It does not require the array to be sorted — that is its main advantage over binary search.

## Step by Step Logic
1. Read `n`, the array and the search key `x`.
2. `pos = -1`.
3. Loop `i` from 0 to `n - 1`: if `a[i] == x`, save `pos = i` and break.
4. If `pos == -1` print "not found", else print `pos + 1`.

## Dry Run
Array `12 34 5 78 23 9`, searching for 78:

| i | a[i] | a[i] == 78? |
|---|------|-------------|
| 0 | 12 | No |
| 1 | 34 | No |
| 2 | 5 | No |
| 3 | 78 | **Yes → pos = 3 → position 4** |

## Code File
[13_linear_search.cpp](../Problems/13_linear_search.cpp)

## Input
```
6
12 34 5 78 23 9
78
```

## Output
```
Enter the size of the array:
Enter 6 elements:
Enter the element to search:
78 is found at position 4.
```

## Edge Case Test
Searching for 100, a value that is not in the array. The loop runs to the end, `pos` stays −1, and the not-found branch prints instead of a bogus position.

Input:
```
6
12 34 5 78 23 9
100
```

Output:
```
Enter the size of the array:
Enter 6 elements:
Enter the element to search:
100 is not found in the array.
```
