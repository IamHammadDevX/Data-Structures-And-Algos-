#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

// dfs
void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int> >& ajdList, vector<int>& component) {


    component.push_back(node);
    visited[node] = true;

    // corresponding node recursive calls
    for (auto i : ajdList[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, ajdList, component);
        }

    }



}

vector<vector<int> > depthFirstSearch(int vertex, int E, vector<vector<int> >& edges) {

    // prepare adjList
    unordered_map<int, list<int> > ajdList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ajdList[u].push_back(v);
        ajdList[v].push_back(u);
    }

    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, ajdList, component);
            ans.push_back(component);
        }

    }

    return ans;
}



int main() {
    // Define the number of vertices and edges
    int vertex = 5;  // Example: A graph with 5 vertices (0 to 4)
    int E = 4;       // Number of edges

    // Define the edges of the graph (undirected)
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {3, 4}
    };

    // Call the depthFirstSearch function
    vector<vector<int>> dfsResult = depthFirstSearch(vertex, E, edges);

    // Print the result
    cout << "DFS Components: " << endl;
    for (const auto& component : dfsResult) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}