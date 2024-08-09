#include<iostream>
#include<vector>
using namespace std;

// main logic
void solve(string digits, string output, int idx, vector<string>& ans, string mapping[]) {

    // base case
    if (idx >= digits.length())
    {
        ans.push_back(output);
        return;
    }


    int number = digits[idx] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, idx + 1, ans, mapping);
        output.pop_back();
    }


}

vector<string> letterCombinations(string digits) {

    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }

    string output = "";
    int idx = 0;
    string mapping[10] = { "", "", "abc", "def", "ghi", "jkl","mno", "pqr", "stu", "vwxyz" };
    solve(digits, output, idx, ans, mapping);

    return ans;

}

int main() {
    string str = "23";  // Example input
    vector<string> result = letterCombinations(str);

    // Printing the subsets
    cout << "Corresponding Phone Keypad Combination for the " << str << " are = ";
    cout << "{ ";
    for (int i = 0; i < result.size(); i++) {
        cout << "' ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "";
        }
        cout << "', ";
    }
    cout << "}";




    // Maping to exclude number on a keypad
    // string digits = "23";
    // int idx = 0;
    // string mapping[10] = { "", "", "abc", "def", "ghi", "jkl","mno", "pqr", "stu", "vwxyz" };
    // int number = digits[idx] - '0';
    // string value = mapping[number];
    // cout << value << endl;





    return 0;
}
