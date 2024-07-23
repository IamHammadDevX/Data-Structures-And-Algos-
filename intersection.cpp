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
int intersection(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    int ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans = arr1[i];
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else {
            j++;
        }


    }
    return ans;

}

int main() {


    int size1, size2;
    cout << "Enter the array Size: ";
    cin >> size1 >> size2;
    int arr1[100], arr2[100];
    cout << "Enter the 1st array: " << endl;
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> arr1[i];
    }
    cout << "Enter the 2nd array: " << endl;
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter the " << i << " index value: ";
        cin >> arr2[i];
    }
    cout << "Original Arrays is: ";
    printArray(arr1, size1);
    printArray(arr2, size2);
    int intersect = intersection(arr1, arr2, size1, size2);
    cout << intersect;

    return 0;
}