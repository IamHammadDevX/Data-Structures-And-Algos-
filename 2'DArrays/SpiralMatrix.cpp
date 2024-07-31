#include <iostream>
#include <vector>
using namespace std;

// Function to generate the spiral matrix
vector<int> spiralOrder(int arr[][100], int row, int col) {
    vector<int> result;
    int count = 0;
    int total = row * col;

    // Index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < total) {
        // Traverse starting row
        for (int c = startingCol; count < total && c <= endingCol; c++) {
            result.push_back(arr[startingRow][c]);
            count++;
        }
        startingRow++;

        // Traverse ending column
        for (int r = startingRow; count < total && r <= endingRow; r++) {
            result.push_back(arr[r][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse ending row
        for (int c = endingCol; count < total && c >= startingCol; c--) {
            result.push_back(arr[endingRow][c]);
            count++;
        }
        endingRow--;

        // Traverse starting column
        for (int r = endingRow; count < total && r >= startingRow; r--) {
            result.push_back(arr[r][startingCol]);
            count++;
        }
        startingCol++;
    }

    return result;
}

int main() {
    int arr[100][100];
    int row, col;

    cout << "Enter the number of rows and cols: ";
    cin >> row >> col;

    // Taking input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "Enter element a" << i + 1 << j + 1 << ": ";
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

    // Generating the spiral order
    vector<int> spiral = spiralOrder(arr, row, col);

    // Printing the spiral order
    cout << "Spiral Matrix is: " << endl;
    for (int val : spiral) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
