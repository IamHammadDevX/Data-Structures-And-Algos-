#include<iostream>
using namespace std;


bool isPossibleSol(int arr[], int n, int m, int mid) {
    int std = 1;
    int numPage = 0;
    for (int i = 0; i < n; i++)
    {
        if (numPage + arr[i] <= mid)
        {
            numPage += arr[i];
        }
        else {
            std++;
            if (std > m || arr[i] > mid)
            {
                return false;
            }
            numPage = arr[i];

        }

    }

    return true;
}

// Book Allocation with Binary Search
int allocateBook(int arr[], int n, int m) {
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossibleSol(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;

        }
        mid = s + (e - s) / 2;

    }



    return ans;
}



int main() {
    int arr[4] = { 10, 20, 30, 40 };
    int numBooks = 4; // Number of books
    int stds = 2; // Number of students

    int ans = allocateBook(arr, numBooks, stds);
    cout << "Answer is: " << ans << endl;

    return 0;
}