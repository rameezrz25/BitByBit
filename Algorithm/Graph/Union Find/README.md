# 🌟 Union Find Algorithm 🌟

The Union Find algorithm is an efficient way to manage and merge disjoint sets. By using path compression and union by rank, the operations can be performed in nearly constant time.

## 📚 Overview

Union Find is a data structure that keeps track of a set of elements partitioned into disjoint (non-overlapping) subsets. It supports two primary operations:
- **Find**: Determine which subset a particular element is in.
- **Union**: Join two subsets into a single subset.

## 🛠️ Implementation

Below is a C++ implementation of the Union Find algorithm using two vectors: `parent` and `rank`.

### 📋 Data Structures

- `vector<int> parent`: This vector holds the parent of each element. Initially, each element is its own parent.
- `vector<int> rank`: This vector holds the rank (or depth) of each tree. It helps in keeping the tree flat.

### 🔍 Functions

#### 🔎 Find

The `find` function returns the root of the set containing element `x`. It uses path compression to flatten the structure, making future queries faster.

```cpp
int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}
```

#### 🔗 Union

The `Union` function merges the sets containing elements `x` and `y`. It uses union by rank to attach the smaller tree under the root of the larger tree.

```cpp
void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent])
        parent[y_parent] = x_parent;
    else if (rank[x_parent] < rank[y_parent])
        parent[x_parent] = y_parent;
    else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
```

### 🚀 Usage

1. **Initialization**: Initialize the `parent` and `rank` vectors. Each element is its own parent, and the rank is initially zero.

    ```cpp
    int n = /* number of elements */;
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    ```

2. **Union and Find Operations**: Use the `Union` and `find` functions to perform union and find operations on the elements.

    ```cpp
    Union(0, 1);
    Union(1, 2);
    int root = find(2); // root will be the representative of the set containing element 2
    ```

### 📈 Applying Union Find on Graph Representations

#### Adjacency List

To apply Union Find on a graph represented by an adjacency list, iterate through each edge and perform union operations.

```cpp
void unionFindAdjList(int n, const vector<vector<int>>& adjList) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            Union(u, v);
        }
    }
}
```

#### Adjacency Matrix

To apply Union Find on a graph represented by an adjacency matrix, iterate through the matrix and perform union operations for each edge.

```cpp
void unionFindAdjMatrix(int n, const vector<vector<int>>& adjMatrix) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (adjMatrix[u][v] == 1) {
                Union(u, v);
            }
        }
    }
}
```

#### Edge List

To apply Union Find on a graph represented by an edge list, iterate through the list and perform union operations for each edge.

```cpp
void unionFindEdgeList(int n, const vector<pair<int, int>>& edgeList) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (const auto& edge : edgeList) {
        Union(edge.first, edge.second);
    }
}
```

## 🏁 Conclusion

## 🔍 LeetCode Problems

Here are some LeetCode problems that can be solved using the Union Find algorithm:

1. [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
2. [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)
3. [Redundant Connection](https://leetcode.com/problems/redundant-connection/)
4. [Accounts Merge](https://leetcode.com/problems/accounts-merge/)
5. [Friend Circles](https://leetcode.com/problems/friend-circles/)
6. [Smallest String With Swaps](https://leetcode.com/problems/smallest-string-with-swaps/)
7. [Earliest Moment When Everyone Become Friends](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)
8. [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
9. [Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/)
10. [Optimize Water Distribution in a Village](https://leetcode.com/problems/optimize-water-distribution-in-a-village/)

These problems will help you practice and understand the Union Find algorithm better.

The Union Find algorithm is an efficient way to manage and merge disjoint sets. By using path compression and union by rank, the operations can be performed in nearly constant time.
