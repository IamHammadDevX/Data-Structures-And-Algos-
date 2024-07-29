#include<iostream>
#include<vector>
using namespace std;


// Reverse Logic
vector<int> reverse(vector<int> v, int idx) {
    int s = idx + 1, e = v.size() - 1;
    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }


    return v;
}

// Print Vector
void print(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

}


int main() {

    vector<int> v;
    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    int idx;
    cout << "Enter the idx from which you wanna rev it: ";
    cin >> idx;

    cout << "Printing the Original array: " << endl;
    print(v);
    vector<int> ans = reverse(v, idx);
    cout << "Printing the Reverse array: " << endl;
    print(ans);

    return 0;
}