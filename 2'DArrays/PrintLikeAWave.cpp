#include<iostream>
using namespace std;


// Print Like A Wave = 1 3 2 4
// 1     2   
//    3     4
void printLikeWave(int arr[][100], int row, int col) {
    cout << "Print like a wave: ";
    for (int c = 0; c < col; c++)
    {
        if (c & 1)
        {
            // ODD Approach 1,3 => Bottom to top
            for (int r = row - 1; r >= 0; r--)
            {
                cout << arr[r][c] << " ";
            }

        }
        else {
            for (int r = 0; r < row; r++)
            {
                cout << arr[r][c] << " ";
            }

        }

    }


}

int main() {

    int arr[100][100];
    int row, col;
    cout << "Enter the number of rows and cols: ";
    cin >> row >> col;

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the " << i << " " << j << " index values: ";
            cin >> arr[i][j];
        }

    }

    // Printing
    cout << "Original 2'D Array is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;

    }

    printLikeWave(arr, row, col);


    return 0;
}