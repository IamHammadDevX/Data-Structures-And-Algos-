#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool isSafe(int newX, int newY, int size, vector<vector<int>>& visited, vector<vector<int>>& matrix) {

    if ((newX >= 0 && newX < size) && (newY >= 0 && newY < size) && visited[newX][newY] == 0 && matrix[newX][newY] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}


// main logic
void solve(vector<vector<int>>& matrix, int size, vector<string>& ans, int srcX, int srcY, vector<vector<int>>& visited, string path) {

    // You have reached X,Y so
    // base case
    if (srcX == size - 1 && srcY == size - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[srcX][srcY] = 1;

    // D | L | R | U = 4 choices

    // Down
    int newX = srcX + 1;
    int newY = srcY;
    if (isSafe(newX, newY, size, visited, matrix))
    {
        path.push_back('D');
        solve(matrix, size, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // Left
    newX = srcX;
    newY = srcY - 1;
    if (isSafe(newX, newY, size, visited, matrix))
    {
        path.push_back('L');
        solve(matrix, size, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // Right
    newX = srcX;
    newY = srcY + 1;
    if (isSafe(newX, newY, size, visited, matrix))
    {
        path.push_back('R');
        solve(matrix, size, ans, newX, newY, visited, path);
        path.pop_back();
    }
    // Up
    newX = srcX - 1;
    newY = srcY;
    if (isSafe(newX, newY, size, visited, matrix))
    {
        path.push_back('R');
        solve(matrix, size, ans, newX, newY, visited, path);
        path.pop_back();
    }


    visited[srcX][srcY] = 0;
}

vector<string> findPath(vector<vector<int>>& matrix, int size) {

    vector<string> ans;

    if (matrix[0][0] == 0)
    {
        return ans;
    }

    // source axis
    int srcX = 0;
    int srcY = 0;

    // make a visited array
    vector<vector<int>> visited = matrix;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            visited[i][j] = 0;
        }

    }

    string path = "";
    solve(matrix, size, ans, srcX, srcY, visited, path);
    sort(ans.begin(), ans.end());


    return ans;

}

int main() {

    vector<vector<int>> matrix = { {1, 0, 0, 0},
                                   {1, 1, 0, 1},
                                   {1, 1, 0, 0},
                                   {0, 1, 1, 1} };

    int size = 4;
    vector<string> result = findPath(matrix, size);
    cout << "Possible ways for a RAT to reach the MAZE destination are => { ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    cout << "}" << endl;


    return 0;
}
