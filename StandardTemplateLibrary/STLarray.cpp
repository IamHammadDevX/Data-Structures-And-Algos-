#include<iostream>
#include<array>
using namespace std;

int main() {
    cout << " CPP STL ARRAY " << endl;
    array<int, 4> arr = { 1,2,3,4 };
    int size = arr.size();
    for (int i:arr)
    {
        cout << i << endl;
    }



    return 0;
}