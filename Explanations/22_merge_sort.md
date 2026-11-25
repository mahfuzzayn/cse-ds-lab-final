# Problem 22: Merge Sort in Ascending Order

## Problem Statement
Sort an array in ascending order using merge sort.

## How It Works
Merge sort is divide-and-conquer too, but it works in the opposite direction from quick sort: it **splits first, merges later**.

`mergeSort(low, high)`:

1. Find `mid = (low + high) / 2`.
2. Recursively `mergeSort` the left half and the right half. The recursion bottoms out at ranges of size 1 — and a single element is always sorted.
3. **Merge** the two now-sorted halves into one sorted range.

The merge (`mergeArray`) is the clever part. Both halves are already sorted, so we never search — we only compare the two *front* elements, like two fingers:

- Copy the smaller front into a temporary array `b`, advance that side.
- When one half runs out, copy the leftovers of the other half in one go.
- Finally copy `b` back into `a`, because the merged result was built in the temporary array.

`a` and `b` are global so every recursive call shares them. Merge sort always splits exactly in half, giving O(n log n) — the reason it is preferred over the O(n²) sorts for large data.

## Step by Step Logic
1. Read the array.
2. Call `mergeSort(0, n - 1)`.
3. Split → sort halves → merge, all the way up.
4. Print the sorted array.

## Dry Run
Array `38 27 43 3 9 82`:

```
        [38 27 43 3 9 82]
       /                 \
  [38 27 43]           [3 9 82]
   /      \             /     \
 [38 27]  [43]       [3 9]    [82]
  /   \                /  \
[38]  [27]           [3]  [9]
  \    /               \  /
 [27 38]              [3 9]
    \    /          \     /
  [27 38 43]      [3 9 82]
        \            /
     [3 9 27 38 43 82]
```

## Code File
[22_merge_sort.cpp](../Problems/22_merge_sort.cpp)

## Input
```
6
38 27 43 3 9 82
```

## Output
```
Enter the size of the array:
Enter 6 elements:
Array after merge sort: 3 9 27 38 43 82
```

## Edge Case Test
A reverse-sorted array. For merge sort the input order does not matter at all — the splits are always in half and the merges do the same amount of work either way, so the worst case is still O(n log n).

Input:
```
5
9 7 5 3 1
```

Output:
```
Enter the size of the array:
Enter 5 elements:
Array after merge sort: 1 3 5 7 9
```
