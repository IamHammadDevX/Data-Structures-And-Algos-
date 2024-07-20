#include<iostream>
using namespace std;

int main() {
    // For Loop
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    // int sum = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     sum += i;
    // }
    // cout << sum << endl;

    // Fabonacci Series
    // int a = 0, b = 1;
    // cout<<"Fabonacci Series of " << n << " th number: ";
    // cout << a << " " << b;
    // for (int i = 1; i <= n; i++)
    // {
    //     int nextNum = a + b;
    //     cout << nextNum << " ";
    //     // Swaping
    //     a = b;
    //     b = nextNum;
    // }

    // !Prime Number
    // bool isPrime = 1;
    // for (int i = 2; i < n; i++)
    // {
    //     // Not a prime if rem=0
    //     if (n % i == 0)
    //     {
    //         isPrime = 0;
    //         break;
    //     }

    // }

    // if (isPrime == 0)
    // {
    //     cout << "Not a Prime!";
    // }
    // else
    // {
    //     cout << "Prime!";
    // }

    // continue 
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Hi" << endl;
    //     cout << "Hey" << endl;
    //     continue;
    //     cout << "Reply......????";
    // }


    for (int i = 0; i <= n; i++)
    {
        cout << i << " ";
        i++;
    }



    return 0;
}