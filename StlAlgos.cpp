#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    cout << " CPP STL algorithm " << endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "Finding 6 => " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Lower Bound => " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << "Upper Bound => " << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl;

    int a = 3, b = 5;
    cout << "Max -> " << max(a, b) << endl;
    cout << "Min -> " << min(a, b) << endl;
    swap(a, b);
    cout << "a -> " << a << " b -> " << b << endl;
    string str = "Python";
    reverse(str.begin(), str.end());
    cout << "Reverse String -> " << str << endl;

    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "Rotated Vector: " << endl;
    for (auto i : v) {
        cout << i << " ";
    }cout << endl;


    return 0;
}