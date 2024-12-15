#include<iostream>
using namespace std;


// Power(2,i)
// int power(int num1, int num2) {
//     int ans = 1;
//     for (int i = 0; i < num2; i++)
//     {
//         ans = ans * num1;
//     }
//     return ans;
// }


// Even & Odd
// bool isEven(int a) {
//     if (a % 2 == 0)
//     {
//         return 1;
//     }
//     else {
//         return 0;
//     }

// }

// Factorial
// int factorial(int n) {
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         fact = fact * i;
//     }
//     return fact;

// }

// nCr
// int nCr(int n, int r) {
//     int num = factorial(n);
//     int deno = factorial(r) * factorial(n - r);
//     int ncr = num / deno;
//     return ncr;
// }

// 1 -> Prime 0 -> Not Prime
bool isPrime(int num) {
    for (int i = 2; i*i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }

    }
    return 1;

}


int main() {
    // int a, b;
    // cout << "Enter the a and b value: ";
    // cin >> a >> b;
    // int ans = power(a, b);
    // cout << "Answer is: " << ans << endl;

    // int num;
    // cout << "Enter a number: ";
    // cin >> num;
    // if (isEven(num))
    // {
    //     cout << "Number is Even!";
    // }
    // else {
    //     cout << "Number is Odd!";
    // }

    // int n, r;
    // cout << "Enter the value of n & r: ";
    // cin >> n >> r;
    // cout << "Answer is: " << nCr(n, r) << endl;


    int num;
    cout << "Enter the number: ";
    cin >> num;
    if (isPrime)
    {
        cout << " is a Prime!";
    }
    else {
        cout << " not a Prime!";
    }


    return 0;
}