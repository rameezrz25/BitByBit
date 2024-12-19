#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    // Constructor to initialize the Union-Find data structure
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    // Union function with union by rank
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
};

// Function to count the number of connected components in the graph
int countConnectedComponents(UnionFind &uf, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (uf.parent[i] == i) {
            count++;
        }
    }
    return count;
}

// Function to find the number of connected components in a graph using Union-Find
int findConnectedComponents(vector<vector<int>> &adjMatrix) {
    int n = adjMatrix.size();
    UnionFind uf(n);

    // Iterate over the adjacency matrix to perform union operations
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adjMatrix[i][j] == 1) {
                uf.Union(i, j);
            }
        }
    }

    // Count the number of connected components
    return countConnectedComponents(uf, n);
}

int main() {
    // Create a dummy adjacency matrix for the graph
    vector<vector<int>> adjMatrix = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    // Find the number of connected components
    int numComponents = findConnectedComponents(adjMatrix);

    // Output the result
    cout << "Number of connected components: " << numComponents << endl;

    // Example using adjacency list
    vector<vector<int>> adjList = {
        {1},        // Node 0 is connected to Node 1
        {0},        // Node 1 is connected to Node 0
        {3},        // Node 2 is connected to Node 3
        {2}         // Node 3 is connected to Node 2
    };

    // Convert adjacency list to edge list
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < adjList.size(); ++i) {
        for (int j : adjList[i]) {
            if (i < j) { // To avoid duplicate edges
                edgeList.push_back({i, j});
            }
        }
    }

    // Create UnionFind instance
    UnionFind uf(adjList.size());

    // Perform union operations for each edge
    for (auto edge : edgeList) {
        uf.Union(edge.first, edge.second);
    }

    // Count the number of connected components
    numComponents = countConnectedComponents(uf, adjList.size());

    // Output the result
    cout << "Number of connected components (adjacency list): " << numComponents << endl;

    // Example using edge list directly
    vector<pair<int, int>> edges = {
        {0, 1},
        {2, 3}
    };

    // Create UnionFind instance
    UnionFind uf2(4); // Assuming 4 nodes

    // Perform union operations for each edge
    for (auto edge : edges) {
        uf2.Union(edge.first, edge.second);
    }

    // Count the number of connected components
    numComponents = countConnectedComponents(uf2, 4);

    // Output the result
    cout << "Number of connected components (edge list): " << numComponents << endl;

    return 0;
}