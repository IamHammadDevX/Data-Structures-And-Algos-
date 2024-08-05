#include<iostream>
using namespace std;

// Square Root using Binary Search
long long int squareRoot(int num) {
    long long int s = 0;
    long long int e = num;
    long long int mid = s + (e - s) / 2;

    long long int ans = -1;
    while (s <= e)
    {
        long long int sqrt = mid * mid;
        if (sqrt == num)
        {
            return mid;
        }
        else if (sqrt < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;

    }

    return ans;

}

double morePrecision(int num, int precision, int sqrtTempSol) {
    double factor = 1;
    double ans = sqrtTempSol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < num; j = j + factor)
        {
            ans = j;
        }

    }
    return ans;

}

int main() {
    int num;
    cout << "Enter the num to search: ";
    cin >> num;
    long long int sqrtTempSol = squareRoot(num);
    cout << "Square root of " << num << " is " << sqrtTempSol << endl;
    cout << "Precise answer is: " << morePrecision(num, 3, sqrtTempSol) << endl;
    return 0;
}