# Problem 06: Copy Elements from One Stack to Another Stack

## Problem Statement
Push elements into one stack, then copy them into a second stack so that both stacks hold the same elements in the same order, using stack operations only.

## How It Works
The catch of this problem: a stack is LIFO. If we simply pop from Stack 1 and push each value straight into Stack 2, Stack 2 ends up **reversed**.

The fix is a temporary stack. Two rounds of popping fix each other:

1. Pop everything from Stack 1 and push it into `temp`. Now `temp` holds the elements in reverse order.
2. Pop everything from `temp`. Values now come out in the original order. Push each one into **both** Stack 1 (restoring it) and Stack 2 (the copy).

After this, Stack 1 is back to exactly what it was, and Stack 2 is an identical copy. Both are displayed top-to-bottom so they can be compared.

## Step by Step Logic
1. Read `n` elements and push them into `s1`.
2. While `s1` is not empty: pop from `s1`, push into `temp`.
3. While `temp` is not empty: pop into `x`, push `x` into `s1` and into `s2`.
4. Display both stacks from top to bottom.

## Dry Run
Stack 1 = 1 2 3 4 5 (5 is the top):

| Round | temp | s1 | s2 |
|-------|------|----|----|
| Pop 5, 4, 3, 2, 1 → push into temp | 1 2 3 4 5 (top = 1) | empty | empty |
| Pop 1 → push to both | 2 3 4 5 | 1 | 1 |
| Pop 2 → push to both | 3 4 5 | 1 2 | 1 2 |
| ... continue ... | — | 1 2 3 4 5 | 1 2 3 4 5 |

Both stacks show top-to-bottom: `5 4 3 2 1`.

## Code File
[06_copy_stack_to_stack.cpp](../Problems/06_copy_stack_to_stack.cpp)

## Input
```
5
1 2 3 4 5
```

## Output
```
Enter the number of elements:
Enter 5 elements:
Stack 1 (top to bottom): 5 4 3 2 1
Stack 2 (top to bottom): 5 4 3 2 1
```

## Edge Case Test
A stack with a single element (7). The temp-stack rounds still work — the value goes over to temp and comes straight back — and both stacks end up holding the same single element.

Input:
```
1
7
```

Output:
```
Enter the number of elements:
Enter 1 elements:
Stack 1 (top to bottom): 7
Stack 2 (top to bottom): 7
```
