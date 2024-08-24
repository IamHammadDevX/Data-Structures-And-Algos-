#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// first Non Repeating character in a stream
string firstNonRepeat(string str) {

    // DS WHICH STORES THE COUNT OF CHARASTERS
    unordered_map<char, int> cnt;
    queue<int> q;
    string ans = "";

    // logic
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        // count ko increase kerdya for first character
        cnt[ch]++;

        // queue me push kerdo buddy!
        q.push(ch);

        // now check the first queu elem whether NR R, OR NOTHING
        while (!q.empty())
        {
            if (cnt[q.front()] > 1)
            {
                // many time repeated hai!
                q.pop();
            }
            else
            {
                // Non-Repeated!
                ans.push_back(q.front());
                break;
            }
        }
        // loop se bahir tab hi ayega jb queue empty hogi yn phr break kerke
        if (q.empty())
        {
            ans.push_back('#');
        }

    }


    return ans;

}


int main()
{


    string str = "aabc";

    string fNR = firstNonRepeat(str);

    cout << fNR << endl;

    return 0;
}