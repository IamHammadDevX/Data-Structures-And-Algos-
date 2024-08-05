#include<iostream>
using namespace std;




int main() {

    int row, col;
    cout << "Enter the row size => ";
    cin >> row;
    cout << "Enter the colomn size => ";
    cin >> col;

    // 2'D dynamic creation
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i] = new int[col];
        }

    }

    // Creation Done

    // taking i/p
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the row " << i + 1 << " col " << j + 1 << " index values: ";
            cin >> arr[i][j];
        }

    }

    // printing
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;

    }

    // Releasing row part
    for (int i = 0; i < row; i++)
    {
        delete[]arr[i];
    }



    // pointer part
    delete[]arr;




    return 0;
}