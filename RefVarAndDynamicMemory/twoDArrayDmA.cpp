#include<iostream>
using namespace std;

void print2DArr(int** arr2D, int row, int col) {

    cout << "Printing the matrix: " << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{

    int row, col;
    cout << "Enter the row and coloumn size: ";
    cin >> row >> col;

    int** arr2D = new int* [row];

    for (int i = 0; i < col; i++)
    {
        arr2D[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the row's " << i + 1 << " value and col's " << j + 1 << " value: ";
            cin >> arr2D[i][j];
        }
    }

    print2DArr(arr2D, row, col);


    // deallocate
    for (int i = 0; i < row; i++)
    {
        // first de-allocate the corresponding arrays to pointers
        delete[] arr2D[i];
    }

    delete[] arr2D;


    return 0;
}