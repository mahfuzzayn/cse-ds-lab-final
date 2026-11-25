# Data Structures Lab Final — 25 Problems, Explained

This folder holds a short, plain-language explanation for each of the 25 problems of the **CSE 0613-122 Data Structures Lab** final. Every explanation file contains:

- the problem statement,
- how the algorithm works, step by step,
- a dry run on the sample input,
- a link to the code file (all code lives in the [Problems](../Problems) folder, one `.cpp` per problem),
- a **Input** and **Output** section captured from an actual run of the program — ready to be copied into the printable lab report,
- an extra **Edge Case Test** showing how the program behaves on a tricky input (invalid position, empty stack, overflow, duplicates, negatives, and so on).

The programs are written the way a 2-1 student would write them: plain arrays, simple loops, no comments, standard `cin`/`cout` input-output style. No library shortcuts are used — every stack, queue, sort and search is built from scratch, since that is what the course asks for.

## Problem Index

| # | Problem | Topic |
|---|---------|-------|
| 01 | [Insert an element at a specific position](01_insert_element_at_position.md) | Array |
| 02 | [Queue enqueue with overflow checking](02_queue_enqueue_overflow.md) | Queue |
| 03 | [Search an element in a queue](03_search_in_queue.md) | Queue |
| 04 | [Sum of stack elements](04_sum_of_stack_elements.md) | Stack |
| 05 | [Average of stack elements](05_average_of_stack_elements.md) | Stack |
| 06 | [Copy one stack to another](06_copy_stack_to_stack.md) | Stack |
| 07 | [Enqueue and dequeue operations](07_enqueue_dequeue_operations.md) | Queue |
| 08 | [Move the first element of a queue to the rear](08_move_front_to_rear.md) | Queue |
| 09 | [Reverse a queue using a stack](09_reverse_queue_with_stack.md) | Queue + Stack |
| 10 | [Separate even and odd into two queues](10_even_odd_separate_queues.md) | Queue |
| 11 | [Undirected graph as adjacency matrix](11_undirected_graph_matrix.md) | Graph |
| 12 | [Count edges from adjacency matrix](12_count_graph_edges.md) | Graph |
| 13 | [Linear search with position](13_linear_search.md) | Searching |
| 14 | [Binary search — ascending array](14_binary_search_ascending.md) | Searching |
| 15 | [Binary search — descending array](15_binary_search_descending.md) | Searching |
| 16 | [Count elements smaller than a value (binary search)](16_count_smaller_elements.md) | Searching |
| 17 | [Bubble sort](17_bubble_sort.md) | Sorting |
| 18 | [Insertion sort](18_insertion_sort.md) | Sorting |
| 19 | [Selection sort](19_selection_sort.md) | Sorting |
| 20 | [Selection sort, array after each pass](20_selection_sort_passes.md) | Sorting |
| 21 | [Quick sort](21_quick_sort.md) | Sorting |
| 22 | [Merge sort](22_merge_sort.md) | Sorting |
| 23 | [Elements that changed position after bubble sort](23_changed_positions_bubble_sort.md) | Sorting |
| 24 | [Even first, odd later (insertion sort)](24_even_odd_insertion_sort.md) | Sorting |
| 25 | [Insert an element at a given position](25_insert_element_given_position.md) | Array |

## How to Compile and Run

Any problem can be built with g++ the usual way:

```
g++ Problems/01_insert_element_at_position.cpp -o problem01
./problem01
```

Then type the input values (from the Input section of that problem's explanation) and press Enter after each line. The output shown in the explanation files was produced exactly this way, so the values will match.

Note on the Input/Output blocks: the **Input** block lists the values that are typed in; the **Output** block is the actual output the program printed for those values. When running interactively, each prompt appears and waits for its value before the next line shows, so the terminal shows them mixed together — the text itself is identical.

## Small Notes

- Problems **01** and **25** solve the same task with two different techniques (in-place shifting vs. copying into a second array). Both are accepted answers; the report can show either or both.
- Problems **07** and **02** both implement queues with menus — 02 focuses only on enqueue + overflow, while 07 adds dequeue and underflow handling.
- All the sorting programs (17–22) sort ascending, which is the standard requirement in the problem list.

Good luck with the lab final!
