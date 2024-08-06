#include<iostream>
using namespace std;

// Recursive Function
int countWaysToReachNthStair(int nStair) {

    // base case
    if (nStair < 0)
    {
        return 0;
    }
    if (nStair == 0)
    {
        return 1;
    }


    // Recursive Relation
    int ans = countWaysToReachNthStair(nStair - 1) + countWaysToReachNthStair(nStair - 2);
    return ans;
}



int main() {

    int num;
    cout << "Enter a number => ";
    cin >> num;
    int ans = countWaysToReachNthStair(num);
    cout << "Steps need to reach " << num << "th stair => " << ans << endl;



    return 0;
}