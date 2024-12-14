#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Topological Sort using Kahn's Algo
vector<int> kahnAlgoTopoSort(vector<vector<int> >& edges, int vertex, int e) {
    // create adj List
    unordered_map<int, list<int> > adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // find all nodes indegrees
    vector<int> indeg(vertex);
    for (auto i : adj) {
        for (auto j : i.second) {
            indeg[j]++;
        }
    }

    // 0 wali indegree ko push to queue
    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }

    }

    // do bfs now
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // save to answer
        ans.push_back(front);

        // neighbour indeg update
        for (auto neighbour : adj[front]) {
            indeg[neighbour]--;
            if (indeg[neighbour] == 0)
            {
                q.push(neighbour);
            }

        }
    }

    return ans;
}


int main()
{




    return 0;
}