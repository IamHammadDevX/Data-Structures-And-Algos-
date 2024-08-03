#include <iostream>
using namespace std;


int main() {
    int arr[100][100];
    int row, col;

    cout << "Enter the number of rows and cols: ";
    cin >> row >> col;

    // Taking input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element of idx row: " << i + 1 << " & col " << j + 1 << ": ";
            cin >> arr[i][j];
        }
    }

    // Printing the 2D Array
    cout << "2D Array is: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            int tempArr = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = tempArr;
        }

    }

    cout << " Transpose of a 2D Array is: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
