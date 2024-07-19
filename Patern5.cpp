#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        // space print kerlo
        int space = n - row;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }


        // 2nd pattern print kerlo
        int col = 1;
        while (col <= row)
        {
            cout << col;
            col++;
        }

        // 3rd patern print kerlo
        int start = row - 1;
        while (start)
        {
            cout << start;
            start--;
        }
        cout << endl;
        row++;

    }



    return 0;
}