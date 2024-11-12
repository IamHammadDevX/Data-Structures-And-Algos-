#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class trieNode {

public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    int childCount;

    trieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }

};

class Trie {
public:
    trieNode* root;

    Trie(char ch) {
        root = new trieNode(ch);
    }

    // insertion
    void insertUtil(trieNode* root, string word) {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode* child;
        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string firstStr, string& ans) {
        for (int i = 0; i < firstStr.length(); i++)
        {
            char ch = firstStr[i];

            if (root->childCount == 1) {
                ans.push_back(ch);
                // agay bhejo
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;

        }

    }

};

string longestCommonPrefix(vector<string>& arr, int n) {
    Trie* t = new Trie('\0');

    // insert all string into trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}


int main()
{

    vector<string> arr;
    arr.push_back("ninja");
    arr.push_back("night");
    arr.push_back("nil");
    int size = arr.size();
    string ans = longestCommonPrefix(arr, size);
    cout << "Longest Common Prefix: " << ans << endl;

    return 0;
}