#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int row = 1;
    // while (row <= n)
    // {

    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << row;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;

    // }

    // int count = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << count << " ";
    //         count++;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // Star Triangle
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << " * ";
    //         col++;
    //     }

    //     cout << endl;
    //     row++;
    // }

    // row numbered triangle
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << row << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;

    // }

    // int count = 1;
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << count << " ";
    //         count++;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;

    // }

    // while (row <= n)
    // {
    //     int col = 1;

    //     while (col <= row)
    //     {
    //         cout << row << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;

    // }
    // Alternative
    // while (row <= n)
    // {
    //     int col = 1;
    //     while (col <= row)
    //     {
    //         cout << (row + col - 1) << " ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;

    // }

    while (row <= n)
    {
        int col = 1;
        while (col <= row)
        {
            cout << (row - col + 1) << " ";
            col++;
        }
        cout << endl;
        row++;

    }

}