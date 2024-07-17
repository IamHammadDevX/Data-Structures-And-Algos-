#include<iostream>
using namespace std;

int main() {
    // int a, b;
    // cout << "Enter a: " << endl;
    // cin >> a;
    // cout << "Enter b: " << endl;
    // cin >> b;
    // // a = cin.get();
    // if (a > b)
    // {
    //     cout << "A is greater";
    // }
    // if (b > a)
    // {
    //     cout << "B is greater";
    // }

    // int num;
    // cout << "Enter a number: ";
    // cin >> num;
    // if (num > 0) {
    //     cout << "Number is +Ve";
    // }
    // else if (num < 0)
    // {
    //     cout << "Number is -Ve";
    // }
    // else
    // {
    //     cout << "Number is 0";
    // }

    // char ch;
    // cout << "Enter any character: " << endl;
    // cin >> ch;
    // if (ch >= 'a' && ch <= 'z')
    // {
    //     cout << "You enter a smallCase letter!";
    // }
    // else if (ch >= 'A' && ch <= 'Z')
    // {
    //     cout << "You enter an UpperCase letter!";

    // }
    // else {

    //     cout << "You enter digit! " << ch;
    // }

    int num, i = 2;
    cout << "Enter the number: " << endl;
    cin >> num;
    // int sum = 0;
    // while (i <= num)
    // {
    //     cout << "the value of i: " << i << endl;
    //     i++;
    // }

    // while (i <= num)
    // {
    //     if ((i % 2) == 0)
    //     {
    //         sum = sum + i;
    //     }
    //         i++;

    // }
    // cout << sum;
    while (i < num)
    {
        if (num % i == 0)
        {
            cout << "Not Prime! for " << i << endl;
        }
        else {

            cout << "Prime! for " << i << endl;
        }
        i++;

    }


}