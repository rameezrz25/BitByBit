# Graph Representation in C++

This document provides a colorful guide to understanding graph representation using adjacency lists and adjacency matrices in C++.

## Code Overview

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to print adjacency list
void printAdjList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// Function to print adjacency matrix
void printAdjMatrix(const vector<vector<int>>& adjMatrix) {
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };

    // Adjacency List Representation
    vector<vector<int>> adjList(V);
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first); // For undirected graph
    }

    // Adjacency Matrix Representation
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    for (auto edge : edges) {
        adjMatrix[edge.first][edge.second] = 1;
        adjMatrix[edge.second][edge.first] = 1; // For undirected graph
    }

    cout << "Adjacency List:" << endl;
    printAdjList(adjList);

    cout << "Adjacency Matrix:" << endl;
    printAdjMatrix(adjMatrix);

    return 0;
}
```

## Explanation

### Adjacency List

An adjacency list is an array of lists. The array size is equal to the number of vertices. Each element of the array is a list that contains the neighbors of the vertex.

**Example:**
```
0: 1 4 
1: 0 2 3 4 
2: 1 3 
3: 1 2 4 
4: 0 1 3 
```

### Adjacency Matrix

An adjacency matrix is a 2D array of size `V x V` where `V` is the number of vertices. A cell `adjMatrix[i][j]` is `1` if there is an edge from vertex `i` to vertex `j`, otherwise `0`.

**Example:**
```
0 1 0 0 1 
1 0 1 1 1 
0 1 0 1 0 
0 1 1 0 1 
1 1 0 1 0 
```

## How to Run

1. Copy the code into a file named `graph_representation.cpp`.
2. Compile the code using a C++ compiler:
   ```sh
   g++ -o graph_representation graph_representation.cpp
   ```
3. Run the executable:
   ```sh
   ./graph_representation
   ```

This will print the adjacency list and adjacency matrix for the given graph.
