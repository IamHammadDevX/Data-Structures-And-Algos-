#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;



// cycle detection in undirected graph with BFS
bool isCycleBFS(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int> >& adj) {

    unordered_map<int, int> parent;
    parent[node] = -1;
    vis[node] = 1;
    queue<int> q;
    q.push(node);


    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (vis[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }
            else if (!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour] = 1;
                parent[neighbour] = front;
            }


        }
    }
    return false;
}
bool isCycleDFS(int node, int parent, unordered_map<int, bool>& vis, unordered_map<int, list<int> >& adj) {

    vis[node] = true;

    for (auto neighbour : adj[node]) {
        if (!vis[neighbour])
        {
            bool cycleDetected = isCycleDFS(neighbour, node, vis, adj);
            if (cycleDetected)
                return true;

        }
        else if (neighbour != parent)
        {
            return true;
        }

    }
    return false;
}


string cycleDetection(vector<vector<int> >& edges, int n, int m) {
    // prepare adjlist
    unordered_map<int, list<int> > adj;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // handle disconnected graph also
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans = isCycleBFS(i, visited, adj);
            bool ans = isCycleDFS(i, -1, visited, adj);
            if (ans == 1)
            {
                return "Yes";
            }
        }
    }
    return "No";

}


int main()
{

    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int> > edges(m, vector<int>(2));
    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string result = cycleDetection(edges, n, m);
    cout << "Graph contains cycle: " << result << endl;



    return 0;
}