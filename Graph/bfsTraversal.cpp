#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<list>
#include<set>
using namespace std;


// BFS TRAVERSAL: Breadth First Search is an algorithm used to visit all nodes of graph
void prepareAdjList(unordered_map<int, list<int> >& adjList, vector<pair<int, int> >& edges) {
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int> >& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    // take a queue
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }

        }

    }

}

vector<int> Bfs(int vertex, vector<pair<int, int> > edges) {
    unordered_map<int, list<int> > adjList;
    // store the answer
    vector<int> ans;
    // visited data structure to avoid from infinite loop & visit all node only for once
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // traverse all components of graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }

    }
    return ans;
}



int main()
{

    int vertex = 5;

    // Define the edges of the graph (undirected)
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {3, 4}
    };

    // Call the BFS function
    vector<int> bfsResult = Bfs(vertex, edges);

    // Print the result
    cout << "BFS Traversal: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}