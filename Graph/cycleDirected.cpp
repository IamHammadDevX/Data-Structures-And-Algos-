#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;


bool checkCycleDfs(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adjList) {
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour]) {
            bool cycleDetected = checkCycleDfs(neighbour, visited, dfsVisited, adjList);
            if (cycleDetected)
                return true;
        }
        else if (dfsVisited[neighbour]) {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

//  Cycle Detection in Directed Graph
bool cycleDetectionInDirectedGraph(int n, vector< pair<int, int>>& edges) {
    // adj List
    unordered_map<int, list<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        // Directed Graph
        adjList[u].push_back(v);
    }

    // call dfs functions for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleFound = checkCycleDfs(i, visited, dfsVisited, adjList);
            if (cycleFound)
            {
                return true;
            }

        }

    }
    return false;
}


int main()
{




    return 0;
}