#include<iostream>
#include<vector>
using namespace std;


// Reverse Vector
vector<int> reverse(vector<int> v) {
    int s = 0, e = v.size() - 1;
    while (s < e)
    {
        swap(v[s++], v[e--]);
    }


    return v;
}

// Sum of two arrays
vector<int> sumOfTwoArrays(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n - 1, j = m - 1;
    int carry = 0;
    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    // First Case
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    // Second Case
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    // third Case = carry !=0
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }



    return reverse(ans);
}


int main() {

    vector<int> a = { 9, 9, 9, 9, 9 };
    vector<int> b = { 1 };

    int n = a.size();
    int m = b.size();

    vector<int> result = sumOfTwoArrays(a, n, b, m);

    cout << "Sum of two arrays: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
