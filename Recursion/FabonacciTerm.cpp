#include<iostream>
using namespace std;

// Recursive Function
int fabo(int n) {

    // Base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Recursive Relation

    return fabo(n - 1) + fabo(n - 2);
}




int main() {

    int num;
    cout << "Enter a number to find term => ";
    cin >> num;
    int ans = fabo(num);
    cout << num << "th term is => " << ans << endl;



    return 0;
}