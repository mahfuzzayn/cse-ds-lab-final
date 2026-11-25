# Problem 12: Count the Total Number of Edges in a Graph Using an Adjacency Matrix

## Problem Statement
Given the adjacency matrix of an undirected graph, count how many edges the graph has.

## How It Works
The tempting idea is "count all the 1s in the matrix". But in an **undirected** graph, one edge appears **twice** in its adjacency matrix — once at `[i][j]` and once at the mirror cell `[j][i]`. For example the edge (1,2) sets both `[0][1] = 1` and `[1][0] = 1`. So counting every 1 would double every edge.

The clean fix: only scan the **upper triangle** of the matrix — the cells where `j > i`. Every edge has exactly one cell in that region, so each edge is counted exactly once. The loop starts the inner `j` at `i + 1` precisely to walk that triangle, and the diagonal (`i == j`) is skipped as well, since a self-loop cell would otherwise also be missed by this count.

## Step by Step Logic
1. Read `v` and then the `v × v` matrix.
2. Set `count = 0`.
3. For `i = 0` to `v - 1`: for `j = i + 1` to `v - 1`: if `g[i][j] == 1`, `count++`.
4. Print the count.

## Dry Run
Matrix of the 4-vertex graph from Problem 11:

```
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

Cells with `j > i`:

| i | j | g[i][j] |
|---|---|---------|
| 0 | 1 | 1 |
| 0 | 2 | 1 |
| 0 | 3 | 0 |
| 1 | 2 | 1 |
| 1 | 3 | 1 |
| 2 | 3 | 1 |

Total = **5 edges** (the whole matrix has ten 1s — exactly double, as expected).

## Code File
[12_count_graph_edges.cpp](../Problems/12_count_graph_edges.cpp)

## Input
```
4
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

## Output
```
Enter the number of vertices:
Enter the adjacency matrix:
Total number of edges = 5
```

## Edge Case Test
A graph with vertices but no edges at all (every matrix cell is 0). The counter never increments, so the answer is 0 — the loop structure handles this naturally without any special case.

Input:
```
3
0 0 0
0 0 0
0 0 0
```

Output:
```
Enter the number of vertices:
Enter the adjacency matrix:
Total number of edges = 0
```
