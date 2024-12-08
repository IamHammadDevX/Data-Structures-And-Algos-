#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;


// Topological Sort
void topoSort(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, list<int> >& adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, s, adj);
        }
    }


    // back track per stack push
    s.push(node);
}


vector<int> topologicalSort(vector<vector<int> >& edges, int vertex, int e) {
    // adjList
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfsTopoSort for all nodes
    vector<bool> visited(vertex);
    stack<int> s;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i]) {
            topoSort(i, visited, s, adj);
        }
    }
    vector<int> ans;

    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


int main()
{




    return 0;
}