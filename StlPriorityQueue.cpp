#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout << " CPP STL Priority-Queue " << endl;
    // Max-Heap
    priority_queue<int> maxi;

    // min-heap
    priority_queue<int, vector<int>, greater<int>> mini;
    cout << "Max-Heap: " << endl;
    for (int i = 0; i <= 20; i += 2)
    {
        maxi.push(i);
    }
    cout << "Size => " << maxi.size() << endl;
    int size = maxi.size();
    for (int i = 0; i < size; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;

    cout << "Min-Heap: " << endl;

    for (int i = 0; i <= 20; i += 2)
    {
        mini.push(i);
    }
    cout << "Size => " << mini.size() << endl;
    int sizeMin = mini.size();
    for (int i = 0; i < sizeMin; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }cout << endl;



    return 0;
}