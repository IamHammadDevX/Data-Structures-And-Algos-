#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(int* arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int cur = arr[i];
        while (s.top() != -1 && arr[s.top()] >= cur)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}
vector<int> prevSmallerElement(int* arr, int n) {

    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        while (s.top() != -1 && arr[s.top()] >= cur)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}


// largest area in histogram
int largestRectangleAreaHistogram(int* heights, int n) {


    vector<int> next(n);
    next = nextSmallerElement(heights, n);
    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);

    }

    return area;
}


// MAX AREA OF RECT IN BINARY MATRIX
int maxArea(int M[][100], int n, int m) {

    // compute area for the first row
    int area = largestRectangleAreaHistogram(M[0], m);

    // now for remaining rows
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row's updation by adding values of prev rows
            if (M[i][j] != 0)
            {
                M[i][j] = M[i][j] + M[i - 1][j];
            }
            else
            {
                M[i][j] = 0;
            }
            // entire row update hochuki hogi
            int newArea = largestRectangleAreaHistogram(M[i], m);
            area = max(area, newArea);
        }
    }

    return area;
}

int main()
{

    int matrix[100][100] = { {0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0} };
    int rows = 4, cols = 4;

    int area = maxArea(matrix, rows, cols);
    cout << "Max area of rectangle in a binary matrix is: " << area << endl;


    return 0;
}