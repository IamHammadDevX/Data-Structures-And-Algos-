#include<iostream>
using namespace std;

// Recursive Function
int power(int n) {

    // Base Case
    if (n == 0)

        return 1;


    // Recursive Relation
    int smallProb = power(n - 1);
    int bigProb = 2 * smallProb;


    return bigProb;
}




int main() {

    int num;
    cout << "Enter a number to find Power of 2 => ";
    cin >> num;
    int ans = power(num);
    cout << "2 ki power " << num << " is => " << ans << endl;



    return 0;
}