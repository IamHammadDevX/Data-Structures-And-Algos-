#include<iostream>
#include<vector>
using namespace std;


void solve(vector<int> nums, vector<vector<int>>& ans, int idx) {

    // base case
    if (idx >= nums.size())
    {
        ans.push_back(nums);
        return;
    }


    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        solve(nums, ans, idx + 1);
        // backtrack
        swap(nums[idx], nums[i]);
    }



}



vector<vector<int>> permutation(vector<int>& nums) {

    vector<vector<int>> ans;
    int idx = 0;
    solve(nums, ans, idx);


    return ans;

}

int main() {

    vector<int> nums = { 1, 2, 3 };  // Example input
    vector<vector<int>> result = permutation(nums);

    // Printing the subsets
    for (int i = 0; i < result.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }



    return 0;
}
