#include<iostream>
using namespace std;
int main() {
    int num;
    cout << "Enter the num:";
    cin >> num;
    // int i = 1;
    // while (i <= num)
    // {
    //     int j = 1;
    //     while (j <= num)
    //     {
    //         cout << i << " ";
    //         j++;

    //     }
    //     cout << endl;
    //     i++;
    // }


    // while (i <= num)
    // {
    //     int j = 1;
    //     while (j <= num)
    //     {
    //         cout << j << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;

    // }
    // while (i <= num)
    // {
    //     int j = 1;
    //     while (j <= num)
    //     {
    //         cout << num - j + 1 << " ";
    //         j++;
    //     }
    //     cout << endl;
    //     i++;

    // }

    // int count = 1;
    // while (i <= num)
    // {
    //     int j = 1;
    //     while (j <= num)
    //     {
    //         cout << count << " ";
    //         count++;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;

    // }


    // Triangle Pattern
    int row = 1;
    while (row <= num)
    {
        int col = 1;
        while (col <= row)
        {
            cout << " * ";
            col++;
        }
        cout << endl;
        row++;

    }

}
