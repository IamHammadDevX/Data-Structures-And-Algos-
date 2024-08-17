#include<iostream>
using namespace std;

// number of ones
int numberOfOnes(int n) {
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }

    return cnt;
}

int main() {
    // Subtract the Product and Sum of an integer
    int n;
    cout << "Enter the number: ";
    cin >> n;
    // int pro = 1;
    // int sum = 0;
    // while (n > 0)
    // {
    //     int lastDig = n % 10;
    //     pro = pro * lastDig;
    //     sum = sum + lastDig;
    //     n = n / 10;
    // }
    // int ans = pro - sum;
    // cout << ans << endl;

    // Last digit
    // cout<<(n&1)<<endl;



    // Number of 1 bits = 5bit 101 = 1bit = 2times
    int count = 0;
    while (n > 0)
    {
        // Checking the last digit
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << "Number of 1 bits in: " << count << endl;
    cout << "Number of 1 bits in: " << numberOfOnes(19) << endl;



    return 0;
}