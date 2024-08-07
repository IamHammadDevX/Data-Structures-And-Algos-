#include<iostream>
using namespace std;

void print(int* arr, int s, int e) {

    for (int i = s; i <= e; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;


}


// Recursive Function
bool binarySearch(int* arr, int s, int e, int key) {
    print(arr, s, e);

    // base case
    if (s > e)
    {
        return false;
    }

    int mid = s + (e - s) / 2;
    cout << "Mid of array at this function call => " << arr[mid] << endl;
    if (arr[mid] == key)
    {
        return true;
    }

    // Recursive relations of BS
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, e, key);
    }
    else {
        return binarySearch(arr, s, mid - 1, key);

    }





}



int main() {


    int arr[6] = { 2,4,6,8,10,18 };
    int size = 6;
    int key = 8;
    bool ans = binarySearch(arr, size - size, size - 1, key);
    if (ans)
    {
        cout << endl << "Present!" << endl;
    }
    else {
        cout << endl << "Absent!" << endl;
    }



    return 0;
}