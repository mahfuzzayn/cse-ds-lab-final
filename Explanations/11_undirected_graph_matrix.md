# Problem 11: Represent an Undirected Graph Using an Adjacency Matrix

## Problem Statement
Read an undirected graph as a list of edges and represent it as an adjacency matrix.

## How It Works
An adjacency matrix is a `V × V` grid where cell `[i][j]` is 1 if there is an edge between vertex `i` and vertex `j`, and 0 otherwise.

The steps:

1. Read the number of vertices `v` and the number of edges `e`.
2. Fill the whole matrix with 0 first (no edges yet).
3. For every edge `(u, w)`: set **both** `g[u-1][w-1]` and `g[w-1][u-1]` to 1.

Two details worth noticing:

- Because the graph is **undirected**, an edge joins u and w in both directions — that is why we set two cells, and why the final matrix is always symmetric (mirrored along the diagonal).
- The user enters vertices as 1 to `v`, but arrays are indexed from 0, so we subtract 1 when storing.

Before storing an edge, the code checks that both vertex numbers are inside `1..v`. An out-of-range pair is reported and skipped instead of writing outside the matrix.

## Step by Step Logic
1. Read `v` (validated 1–10) and `e`.
2. Initialize `g[i][j] = 0` for all cells.
3. For each edge, read `u w`; if valid, set `g[u-1][w-1] = 1` and `g[w-1][u-1] = 1`.
4. Print the matrix row by row.

## Dry Run
4 vertices, edges (1,2), (1,3), (2,4), (3,4), (2,3):

| Edge | Cells set |
|------|-----------|
| (1,2) | [0][1] and [1][0] |
| (1,3) | [0][2] and [2][0] |
| (2,4) | [1][3] and [3][1] |
| (3,4) | [2][3] and [3][2] |
| (2,3) | [1][2] and [2][1] |

## Code File
[11_undirected_graph_matrix.cpp](../Problems/11_undirected_graph_matrix.cpp)

## Input
```
4
5
1 2
1 3
2 4
3 4
2 3
```

## Output
```
Enter the number of vertices:
Enter the number of edges:
Enter 5 edges (vertex pairs):
Adjacency Matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
```

## Edge Case Test
3 vertices, and one of the three edges uses vertex 4 — which does not exist. The program prints a skip message for that edge and still builds the matrix correctly from the valid two.

Input:
```
3
3
1 2
2 3
1 4
```

Output:
```
Enter the number of vertices:
Enter the number of edges:
Enter 3 edges (vertex pairs):
Invalid edge (1, 4) skipped.
Adjacency Matrix:
0 1 0
1 0 1
0 1 0
```
