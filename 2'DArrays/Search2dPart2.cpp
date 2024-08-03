#include<iostream>
using namespace std;


// Search Matrix by Efficient Manner
bool searchMatrix(int arr[][100], int row, int col, int target) {

    int rowIdx = 0, colIdx = col - 1;
    while (rowIdx < row && colIdx >= 0)
    {
        int elem = arr[rowIdx][colIdx];
        if (elem == target)
        {
            return 1;
        }
        else if (elem < target)
        {
            rowIdx++;
        }
        else
        {
            colIdx--;
        }

    }



    return 0;
}

// Print 2'D array
void print2DArray(int arr[][100], int row, int col) {
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;

    }

}

int main() {
    int arr[100][100];
    int row, col;
    cout << "Enter rows & col size: ";
    cin >> row >> col;
    // Taking input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element of idx row: " << i + 1 << " & col " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }
    cout << "2D Array is: " << endl;
    print2DArray(arr, row, col);

    int target;
    cout << "Enter the searched key: ";
    cin >> target;

    bool ans = searchMatrix(arr, row, col, target);
    if (ans)
    {
        cout << "Element is found!";
    }
    else {
        cout << "Element is not found!";
    }



    return 0;
}