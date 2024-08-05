#include<iostream>
using namespace std;


inline int getSum(int& a, int& b) {

    return (a < b) ? a : b;

}


int main() {

    int a = 13, b = 45;
    int ans = 0;
    ans = getSum(a, b);
    cout << "Answer is => " << ans << endl;
    a = a + 5;
    b = b + 9;
    ans = getSum(a, b);
    cout << "Answer is => " << ans << endl;

    return 0;
}