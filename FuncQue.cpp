#include<iostream>
using namespace std;


// A . P = Arithmetic Progression
// int ArithPro(int n) {

//     int Ap = 3 * n + 7;

//     return Ap;
// }

// Total number of set bits
// int TotalNumberOfSetBits(int a, int b) {
//     int count = 0;
//     while (a > 0 || b > 0) {
//         if ((a & 1) == 1) {
//             count++;
//         }
//         if ((b & 1) == 1) {
//             count++;
//         }
//         a = a >> 1;
//         b = b >> 1;
//     }
//     return count;
// }

// Fabonacci Series
// int Fabonacci(int num) {
//     if (num <= 0) {
//         return 0;
//     }
//     else if (num == 1) {
//         return 1;
//     }
//     int a = 0, b = 1;
//     int nextDig;
//     for (int i = 1; i <= num; i++)
//     {
//         nextDig = a + b;
//         a = b;
//         b = nextDig;
//     }


//     return b;
// }


// Questions
int update(int a) {
    int ans = a * a;
    return ans;
}


int main() {

    // int n;
    // cout << "Enter a number: ";
    // cin >> n;
    // int ans = ArithPro(n);
    // cout << "Arithmetic Progression is: " << ans << "th" << endl;

    // int a, b;
    // cout << "Enter a and b: ";
    // cin >> a >> b;
    // int ans = TotalNumberOfSetBits(a, b);
    // cout << "Answer is: " << ans << endl;


    // int num;
    // cout << "Enter the number: ";
    // cin >> num;
    // cout << "Fibonacci number at position " << num << " is: " << Fabonacci(num) << endl;
    int a = 14;
    a = update(a);
    cout << a << endl;

    return 0;
}