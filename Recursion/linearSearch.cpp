#include<iostream>
using namespace std;

// Recursive Function
bool linearSearch(int* arr, int size, int key) {


    // Base case
    if (size == 0)
    {
        return false;
    }

    // Recursive Relation
    if (key == arr[0])
    {
        return true;
    }
    else
    {
        bool remainingPart = linearSearch(arr + 1, size - 1, key);
        return remainingPart;
    }




}



int main() {


    int arr[5] = { 2,4,6,9,13 };
    int size = 5;
    int key = 100;
    bool ans = linearSearch(arr, size, key);
    if (ans)
    {
        cout << "Element is Present!" << endl;
    }
    else {

        cout << "Element is not Present!" << endl;
    }


    return 0;
}