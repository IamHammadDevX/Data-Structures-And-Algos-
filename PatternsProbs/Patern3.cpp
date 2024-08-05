#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int r = 1;
    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= n)
    //     {
    //         char ch = 'A' + r - 1;
    //         cout << ch << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }

    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= n)
    //     {
    //         char ch = 'A' + c - 1;
    //         cout << ch << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }

    // int count = 1;
    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= n)
    //     {
    //         char ch = 'A' + count - 1;
    //         cout << ch << " ";
    //         count++;
    //         c++;
    //     }
    //     cout << endl;
    //     r++;
    // }

    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= n)
    //     {
    //         cout << (r + c - 1) << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }

    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= n)
    //     {
    //         char ch = 'A' + r + c - 2;
    //         cout << ch << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }


    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= r)
    //     {
    //         char ch = 'A' + r - 1;
    //         cout << ch << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }


    // int count = 1;
    // char ch = 'A';
    // while (r <= n) {
    //     int c = 1;
    //     while (c <= r) {
    //         cout << ch << " ";  // Print the current character
    //         ch++;  // Move to the next character
    //         c++;
    //     }
    //     cout << endl;
    //     r++;
    // }

    // while (r <= n)
    // {
    //     int c = 1;
    //     while (c <= r)
    //     {
    //         char ch = 'A' + r + c - 2;
    //         cout << ch << " ";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }


    while (r <= n)
    {
        int c = 1;
        char ch = 'A' + n - r;
        while (c <= r)
        {
            cout << ch << " ";
            ch++;
            c++;
        }
        cout << endl;
        r++;

    }

}