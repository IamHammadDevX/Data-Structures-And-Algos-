#include<iostream>
using namespace std;

// Recursive Function
void printCounting(int n) {

    // Base case
    if (n == 0)
    {
        return;
    }

    // Head Recursion
    // recursive relation
    printCounting(n - 1);

    cout << n << endl;

    // Tail Recursion
    // recursive relation
    // printCounting(n - 1);


}


int main() {

    int num;
    cout << "Enter a number to find factorial => ";
    cin >> num;
    printCounting(num);


    return 0;
}