#include<iostream>
using namespace std;


// Merge Sorted array logic
long long merge(int* arr, int s, int e) {

    int mid = s + (e - s) / 2;
    long long inv = 0;
    // length of left sorted part
    int leftLen = mid - s + 1;
    // length of right sorted part
    int rightLen = e - mid;

    // Left part array
    int* leftArr = new int[leftLen];
    // right part array
    int* rightArr = new int[rightLen];

    // copy values
    int mainArrayIdx = s;
    // Copy left array values to leftArr
    for (int i = 0; i < leftLen; i++)
    {
        leftArr[i] = arr[mainArrayIdx++];
    }
    mainArrayIdx = mid + 1;
    // Copy right array values to leftArr
    for (int i = 0; i < rightLen; i++)
    {
        rightArr[i] = arr[mainArrayIdx++];
    }


    // merge two sorted arrays
    int idx1 = 0, idx2 = 0;
    mainArrayIdx = s;
    while (idx1 < leftLen && idx2 < rightLen)
    {
        if (leftArr[idx1] <= rightArr[idx2])
        {
            arr[mainArrayIdx++] = leftArr[idx1++];
        }
        else {
            arr[mainArrayIdx] = rightArr[idx2];
            inv += leftLen - idx1;
            mainArrayIdx++;
            idx2++;
        }

    }



    // separate check
    while (idx1 < leftLen)
    {
        arr[mainArrayIdx++] = leftArr[idx1++];
    }
    while (idx2 < rightLen)
    {
        arr[mainArrayIdx++] = rightArr[idx2++];
    }
    // Releasing Heap memory
    delete[]leftArr;
    delete[]rightArr;

    return inv;

}



long long mergeSort(int* arr, int s, int e) {


    // base case
    if (s >= e)

        return 0;

    long long inv = 0;
    int mid = s + (e - s) / 2;


    // Recursive calls
    // left sort part
    inv += mergeSort(arr, s, mid);

    // right sort part
    inv += mergeSort(arr, mid + 1, e);


    // Sort both left & right
    inv += merge(arr, s, e);

    return inv;
}


int main() {

    int arr[6] = { 6,9,3,57,2,7 };
    int size = 6;
    cout << "Original Array => ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    long long ans = mergeSort(arr, 0, size - 1);
    cout << "Inversion Count => " << ans << endl;




    return 0;
}