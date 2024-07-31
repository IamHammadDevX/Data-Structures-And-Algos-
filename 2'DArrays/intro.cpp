#include<iostream>
using namespace std;


// Target Find => Linear Search
bool isPresent(int arr[][100], int target, int row, int col) {

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }

        }

    }




    return 0;
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
    cout << "2'D Array is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;

    }

    int target;
    cout << "Enter the key to search: ";
    cin >> target;

    if (isPresent(arr, target, row, col))
    {
        cout << target << " Element found! " << endl;
    }
    else {
        cout << "Element does'nt exist!";

    }


    return 0;
}