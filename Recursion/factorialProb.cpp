#include<iostream>
using namespace std;

// Recursive Function
int factorial(int n) {

    // Base Case 0! = 1 stop
    if (n == 0)

        return 1;

    // Recursive Relation
    int smallProb = factorial(n - 1);
    int bigProb = n * smallProb;

    return bigProb;
}




int main() {

    int num;
    cout << "Enter a number to find factorial => ";
    cin >> num;
    int ans = factorial(num);
    cout << "Factorial of " << num << "! is => " << ans << endl;



    return 0;
}