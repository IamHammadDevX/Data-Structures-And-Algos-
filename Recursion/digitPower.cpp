#include<iostream>
using namespace std;


// Recursive Function
int digitRaisePower(int a, int b) {

    // base case
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }


    // recursive call
    int ans = digitRaisePower(a, b / 2);

    if (b % 2 == 0)
    {
        // even case
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }


}


int main() {

    int a, b;
    cout << "Enter a & b => ";
    cin >> a >> b;
    int ans = digitRaisePower(a, b);
    cout << "Answer is => " << ans << endl;



    return 0;
}