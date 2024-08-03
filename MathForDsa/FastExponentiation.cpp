#include<iostream>
using namespace std;


// Modular Algo
int fastExponentiation(int x, int n, int m) {
    int res = 1;
    while (n > 0)
    {
        //    Odd case
        if (n & 1)
        {
            res = (1LL * (res) * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1;

    }

    return res;
}


int main() {
    int x, n, m;
    cout << "Enter values for x, n and m: ";
    cin >> x >> n >> m;
    int ans = fastExponentiation(x, n, m);
    cout << "Answer is: " << ans << endl;
    return 0;
}