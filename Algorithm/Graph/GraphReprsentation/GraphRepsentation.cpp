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