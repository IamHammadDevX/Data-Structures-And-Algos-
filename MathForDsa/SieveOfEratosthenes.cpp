#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n) {
    int count = 0;
    // vector<bool> prime(n + 1, true);
    // prime[0] = prime[1] = false;
    int prime[100] = { 0 };

    // Sieve of eratosthenes theorem
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            count++;
            for (int j = 2 * i; j <= n; j = j + i)
            {
                prime[j] = 1;
            }

        }
    }


    return count;
}

int main() {

    int n;
    cout << "Enter the range: ";
    cin >> n;
    int ans = countPrimes(n);
    cout << "Number of primes in range of: " << n << " is: " << ans << endl;
    return 0;
}