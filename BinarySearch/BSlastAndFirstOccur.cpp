#include<iostream>
using namespace std;


// Print Array func
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

// First Most Occurence
int leftMostOccurrence(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;

    }


    return ans;
}
// Last Most Occurence
int rightMostOccurrence(int arr[], int size, int key) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (key == arr[mid])
        {
            ans = mid;
            s = mid + 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;

    }


    return ans;
}

// First and Last Most positions
pair<int, int> firstAndLastPosition(int arr[], int size, int key) {
    pair<int, int> p;
    p.first = leftMostOccurrence(arr, size, key);
    p.second = rightMostOccurrence(arr, size, key);

    return p;
}

int main() {


    int size;
    cout << "Enter the array Size: ";
    cin >> size;
    int arr[100];
    cout << "Enter the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> arr[i];
    }
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    cout << "Original Array is: ";
    printArray(arr, size);

    pair<int, int> fLp = firstAndLastPosition(arr, size, key);
    cout << "First & Last Most Occurrences of " << key << " is at index: (" << fLp.first << ", " << fLp.second << ")" << endl;


    return 0;
}