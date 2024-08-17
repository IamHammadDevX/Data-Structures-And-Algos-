#include<iostream>
#include<math.h>
using namespace std;

// power of 2
bool isPower2(int n) {
    return (n && !(n & n - 1));
}

int main() {
    // Reverse the integer
    int n;
    cout << "Enter the integer: ";
    cin >> n;
    // int ans = 0;
    // while (n > 0)
    // {
    //     int lastDig = n % 10;
    //     if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
    //     {
    //         return 0;
    //     }
    //     ans = (ans * 10) + lastDig;

    //     n = n / 10;
    // }
    // cout << "Reverse: " << ans << endl;



    // Complement of base 10 int
    // int m = n;
    // int mask = 0;
    // // Edge Case
    // if (n == 0)
    //     return 0;

    // while (m > 0)
    // {
    //     // mask = 00010 = 00010 | 1= 00011 = 00110 | 1 = carry on
    //     mask = (mask << 1) | 1;
    //     m = m >> 1;
    // }
    // int ans = (~n) & mask;
    // cout << ans;


    // Power of Two
    // int ans = 1;
    // for (int i = 0; i <= 30; i++)
    // {
    //     if (ans == n)
    //     {
    //         return true;
    //     }
    //     if (ans < INT_MAX / 2)
    //         ans = ans * 2;
    // }
    // return false;


    cout << isPower2(n) << endl;
    return 0;
}
