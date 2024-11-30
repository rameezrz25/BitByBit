/*
    Company Tags  : Flipkart, Amazon, Samsung, MakeMyTrip, Oracle, Adobe
    Question Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/

#include <iostream>
#include <vector>

using namespace std;

bool isCycleUtil(vector<int> g[], int start, vector<bool>& visited, int parent) {
    visited[start] = true;
    
    vector<int>::iterator it;
    for(it = g[start].begin(); it != g[start].end(); it++) {
        if(*it == parent)
            continue;
        if(visited[*it] == true)
            return true;
        if(isCycleUtil(g, *it, visited, start))
            return true;
            
    }
    return false;
}

bool isCyclic(vector<int> g[], int V) {
    vector<bool> visited(V, false);
    
    for(int i = 0; i<V; i++) {
        if(visited[i] == false && isCycleUtil(g, i, visited, -1))
            return true;
    }
    return false;
}

void addEdge(vector<int> &adj , int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main() {
    int V = 4;
    vector<int> adj(4);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << "This is the graph : \n";
    for(int i = 0; i < V; i++) {
        cout << i << " -> ";
        for(int j : adj)
            cout << j << " ";
    }

    
    isCycleUtil(adj, V) ? cout << "Graph contains cycle" : cout << "Graph doesn't contain cycle";

}