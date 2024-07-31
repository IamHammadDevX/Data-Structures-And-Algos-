#include<iostream>
using namespace std;


// Row Wise Sum
void printRowWiseSum(int arr[][100], int row, int col) {

    cout << "Sum Row Wise: " << endl;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << " ";

    }
    cout << endl;

}
// Row Wise Sum
void printColWiseSum(int arr[][100], int row, int col) {

    cout << "Sum Col Wise: " << endl;
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << sum << " ";

    }
    cout << endl;

}

// Largest row Sum
int largestRowSum(int arr[][100], int row, int col) {
    int rowIdx = -1;
    int maxi = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum = sum + arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIdx = i;
        }
    }

    cout << "Largest Sum in the row is: " << maxi << endl;

    return rowIdx;
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

    printRowWiseSum(arr, row, col);
    printColWiseSum(arr, row, col);

    int large = largestRowSum(arr, row, col);
    cout << "Index of Largest Row Sum: " << large << endl;


    return 0;
}