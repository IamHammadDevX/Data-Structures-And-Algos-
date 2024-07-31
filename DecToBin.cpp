#include<iostream>
#include<math.h>
using namespace std;

int main() {
    // Dec to Bin
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int ans = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i) + ans);
        n = n >> 1;
        i++;
    }
    cout << "Binary is: " << ans << endl;


    // Binary to Decimal
    // while (n > 0)
    // {
    //     int lastDig = n % 10;
    //     if (lastDig == 1)
    //     {
    //         ans = ans + pow(2, i);
    //     }
    //     n = n / 10;
    //     i++;

    // }
    // cout << "Decimal is: " << ans << endl;




    return 0;
}
