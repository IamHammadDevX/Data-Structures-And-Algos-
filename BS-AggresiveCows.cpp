#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int stalls[], int n, int c, int minDist) {
    int cowsPlaced = 1; // Place the first cow in the first stall
    int lastPos = stalls[0]; // The position of the last placed cow

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            // Place the next cow here
            cowsPlaced++;
            lastPos = stalls[i]; // Update the position of the last placed cow
            if (cowsPlaced == c) {
                return true; // All cows are placed successfully
            }
        }
    }
    return false; // Not all cows can be placed with at least minDist between them
}

int aggressiveCows(int stalls[], int n, int c) {
    sort(stalls, stalls + n); // Sort the stalls

    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, n, c, mid)) {
            result = mid; // Update result
            low = mid + 1; // Try for a bigger distance
        }
        else {
            high = mid - 1; // Try for a smaller distance
        }
    }
    return result;
}

int main() {
    int stalls[] = { 1, 2, 4, 8, 9 };
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int cows = 3;

    int result = aggressiveCows(stalls, n, cows);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
