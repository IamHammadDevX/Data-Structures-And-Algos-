#include <iostream>
using namespace std;

void sort(int arr[], int idx, int size) {
    // base case
    if (idx == size)
        return;

    int curr = arr[idx];
    int j = idx - 1;

    while (j >= 0) {
        if (curr < arr[j]) { // found greater value than curr, shift to right
            arr[j + 1] = arr[j];
            j--;
        } else { // smaller element found
            break;
        }
    }
    arr[j + 1] = curr; // place curr element at correct place

    // one part done, recursion will do other work
    sort(arr, idx + 1, size);
}

int main() {
    // Array to be sorted
    int arr[] = {10, 1, 7, 6, 14, 9};
    // size of array
    int size = 6;

    // recursive function call
    sort(arr, 1, size);

    // printing array at end
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
