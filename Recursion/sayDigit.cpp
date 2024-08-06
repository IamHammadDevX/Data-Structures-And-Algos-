#include<iostream>
using namespace std;

// Recursive Function

void sayDigit(int n, string* arr) {

    // base case
    if (n == 0)
    {
        return;
    }


    int digit = n % 10;
    n = n / 10;
    sayDigit(n, arr);
    cout << arr[digit] << " ";

}




int main() {

    string arr[100] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

    int num;
    cout << "Enter a number => ";
    cin >> num;
    sayDigit(num, arr);



    return 0;
}