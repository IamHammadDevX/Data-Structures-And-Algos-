#include<iostream>
using namespace std;


// Merge Sorted Arrays
// void mergeSortedArrays(int arr1[], int n, int arr2[], int m, int arr3[]) {
//     int i = 0, j = 0, k = 0;
//     while (i < n && j < m)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr3[k] = arr1[i];
//             k++;
//             i++;
//         }
//         else
//         {
//             arr3[k] = arr2[j];
//             k++;
//             j++;

//         }
//     }

//     // Copy arr1 required elems
//     while (i < n)
//     {
//         arr3[k++] = arr1[i++];
//     }
//     while (j < m)
//     {
//         arr3[k++] = arr2[j++];
//     }

// }

// Merging into 1 array
void mergeSortedArrays(int arr1[], int n, int arr2[], int m) {
    int i = n - m - 1;
    int j = 0;
    int k = i + 1;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr1[k] = arr2[j];
            k++;
            j++;
        }
        else {
            arr1[k] = arr1[i];
            k++;
            i++;
        }

    }
    while (j < m)
    {
        arr1[k++] = arr2[j++];
    }

}


// Print Array 3
void printArray(int ans[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}



int main() {

    // int arr1[5] = { 1,3,5,7,9 };
    // int arr2[3] = { 2,4,6 };
    // int arr3[8] = { 0 };

    // mergeSortedArrays(arr1, 5, arr2, 3, arr3);
    // cout << "Merged Sorted Array: " << endl;
    // printArray(arr3, 8);
    int arr1[6] = { 1,2,3,0,0,0 };
    int arr2[3] = { 7,8,9 };
    mergeSortedArrays(arr1, 6, arr2, 3);
    cout << "Merged Sorted Array: " << endl;
    printArray(arr1, 6);

    return 0;
}