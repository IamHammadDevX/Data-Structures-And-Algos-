#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// maximum frequency number???
int maxFreqNumber(vector<int>& arr) {

    // make a map to store key, value pair and count the integers freq
    unordered_map<int, int> count;

    // maxFreq
    int maxFreq = 0;
    int maxAns = 0;

    // travers and store the count
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }

    }
    return maxAns;
}


int main()
{

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(6);
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);

    int maxFreq = maxFreqNumber(arr);
    cout << "Maximum occuring elem count is: " << maxFreq << endl;

    return 0;
}