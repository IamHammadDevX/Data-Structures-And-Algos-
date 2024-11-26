#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
// making a generic code
template <typename T>


class graph {
public:
    unordered_map<T, list<T> > adj;

    void addEdges(T u, T v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed


        // create an edge from u -> v = u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // print list
    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};


int main()
{
    int nodes, Edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> Edges;

    graph<int> g;

    for (int i = 0; i < Edges; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating a undirected graph
        g.addEdges(u, v, 0);
    }

    // print
    g.printAdjList();





    return 0;
}