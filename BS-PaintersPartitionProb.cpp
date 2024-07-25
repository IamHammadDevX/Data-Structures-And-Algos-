#include<iostream>
using namespace std;


bool isPossibleSol(int arr[], int n, int painters, int mid) {

    int painter = 1;
    int curr_sum = 0; // Current sum of lengths of boards for the current painter

    for (int i = 0; i < n; i++) {
        if (curr_sum + arr[i] <= mid) {
            curr_sum += arr[i];
        }
        else {
            painter++;
            if (painter > painters || arr[i] > mid) {
                return false;
            }
            curr_sum = arr[i];
        }
    }

    return true;
}

// Painters Partion Prob
int findMinTime(int arr[], int n, int painters) {
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = 0;
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossibleSol(arr, n, painters, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    int arr[] = { 5,5,5,5 };
    int painters = 2;
    int n = sizeof(arr) / sizeof(arr[0]); //int 4bytes * 4element = 16 / int(arr[0th elemt - 4bytes]) = 4

    int result = findMinTime(arr, n, painters);
    cout << "Minimum time required to paint all boards: " << result << endl;

    return 0;
}