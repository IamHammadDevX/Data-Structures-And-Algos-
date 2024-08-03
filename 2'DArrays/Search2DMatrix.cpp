#include<iostream>
using namespace std;


// Search Matrix
bool searchMatrix(int arr[][100], int row, int col, int target) {
    int s = 0;
    int e = row * col - 1;
    int mid = s + (e - s) / 2; //mid

    while (s <= e)
    {
        // midElem = supose at 6th idx
        // 6/4 = 1 row, 6%4 = 2 col;
        // now apply binary Search
        int midElem = arr[mid / col][mid % col];
        if (midElem == target)
        {
            return 1;
        }
        else if (midElem < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
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