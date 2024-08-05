#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    int r = 1;
    // while (r <= n)
    // {
    //     // space print karo
    //     int space = n - r;
    //     while (space)
    //     {
    //         cout << " ";
    //         space--;
    //     }

    //     // * asteris print kerlo ab!
    //     int c = 1;
    //     while (c <= r)
    //     {
    //         cout << "*";
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }


    // while (r <= n)
    // {
    //     int star = n - r + 1;
    //     while (star) {
    //         cout << "*";
    //         star--;
    //     }
    //     cout << endl;
    //     r++;

    // }

    // while (r<=n)
    // {
    //     // space print kerlo
    //     int space = r-1;
    //     while (space)
    //     {
    //         cout<<" ";
    //         space--;
    //     }

    //     // star print kerlo
    //     int star = n - r + 1;
    //     while (star) {
    //         cout << "*";
    //         star--;
    //     }
    //     cout << endl;
    //     r++;

    // }


    // while (r <= n)
    // {
    //     // space kerlo
    //     int space = r - 1;
    //     while (space)
    //     {
    //         cout << " ";
    //         space--;
    //     }

    //     // number print kerdena
    //     int count = n - r + 1;
    //     while (count)
    //     {
    //         cout << r;
    //         count--;
    //     }
    //     cout << endl;
    //     r++;

    // }


    // while (r <= n)
    // {
    //     // space kerlo print
    //     int space = n - r;
    //     while (space)
    //     {
    //         cout << " ";
    //         space--;
    //     }


    //     // number print kerlo
    //     int c = 1;
    //     while (c <= r)
    //     {
    //         cout << r;
    //         c++;
    //     }
    //     cout << endl;
    //     r++;

    // }

    // while (r <= n) {
    //     // Print leading spaces
    //     int space = r - 1;
    //     while (space) {
    //         cout << " ";
    //         space--;
    //     }

    //     // Print numbers starting from r to n
    //     int c = r;
    //     while (c <= n) {
    //         cout << c;
    //         c++;
    //     }
    //     cout << endl;
    //     r++;
    // }

    int count = 1;
    while (r <= n)
    {
        // space
        int space = n - r;
        while (space)
        {
            cout << " ";
            space--;
        }
        // number print
        int c = 1;
        while (c <= r)
        {
            cout << count;
            count++;
            c++;
        }
        cout << endl;
        r++;
    }


    return 0;
}