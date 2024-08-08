#include<iostream>
#include<vector>
using namespace std;

// main logic
void solve(string str, string output, int idx, vector<string>& ans) {

    // base case
    if (idx >= str.length())
    {
        if (output.length() > 0)
        {
            ans.push_back(output);
        }

        return;
    }

    // recursive calls
    // Exclude case
    solve(str, output, idx + 1, ans);

    // include case
    char element = str[idx];
    output.push_back(element);
    solve(str, output, idx + 1, ans);

}

vector<string> subsequence(string str) {

    vector<string> ans;
    string output = "";
    int idx = 0;
    solve(str, output, idx, ans);

    return ans;

}

int main() {
    string str = "abc";  // Example input
    vector<string> result = subsequence(str);

    // Printing the subsequences
    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"" << endl;
    }

    return 0;
}
