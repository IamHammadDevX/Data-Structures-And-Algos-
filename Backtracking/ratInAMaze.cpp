#include<iostream>
#include<vector>
using namespace std;

// DAY 1: Backtracking -> Rat In A Maze Problem

bool isSafe(int newX, int newY, vector< vector< bool > >& vis, vector< vector<int> >& arr, int n) {

    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && vis[newX][newY] != 1 && arr[newX][newY] == 1)
    {
        return true;
    }
    else

        return false;
}

void solve(int x, int y, vector< vector<int> >& arr, int n, vector<string>& ans, vector< vector< bool > >& vis, string path) {

    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // movments 4
    // D -> DOWN, L -> LEFT, R -> RIGHT, U -> UP
    vis[x][y] = 1;

    // DOWN
    if (isSafe(x + 1, y, vis, arr, n))
    {
        solve(x + 1, y, arr, n, ans, vis, path + 'D');
    }
    // LEFT
    if (isSafe(x, y - 1, vis, arr, n))
    {
        solve(x, y - 1, arr, n, ans, vis, path + 'L');
    }
    // RIGHT
    if (isSafe(x, y + 1, vis, arr, n))
    {
        solve(x, y + 1, arr, n, ans, vis, path + 'R');
    }
    // UP
    if (isSafe(x - 1, y, vis, arr, n))
    {
        solve(x - 1, y, arr, n, ans, vis, path + 'U');
    }
    vis[x][y] = 0;
}

vector<string> searchMaze(vector< vector<int> >& arr, int n) {
    vector<string> ans;
    vector< vector< bool > > visited(n, vector<bool>(n, 0));
    string path = "";

    // base case
    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{

    vector< vector< int > >arr = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1},
    };
    int size = 4;
    vector<string> findPath = searchMaze(arr, size);
    cout << "Possible ways for a RAT to reach the MAZE destination are => { ";
    for (int i = 0; i < findPath.size(); i++)
    {
        cout << findPath[i] << " ";
    }

    cout << "}" << endl;

    return 0;
}