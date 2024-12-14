#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

//  Shortest path in undirected graph
vector<int> shortestPath(vector<pair<int, int> > edges, int node, int m, int src, int dest) {

    // create adj list
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    vis[src] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front]) {
            if (!vis[i])
            {
                vis[i] = true;
                parent[i] = front;
                q.push(i);
            }

        }
    }

    // shortest path
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest);

    while (currNode != src)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



int main()
{




    return 0;
}