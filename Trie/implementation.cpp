#include<iostream>
using namespace std;

// Trie implementation
class trieNode {

public:
    // character will come after root node
    char data;
    // every character has 26 letters to lean down
    trieNode* childNode[26];
    // terminating node which indicate that whether string ends or not
    bool isTerminal;
    // constructor
    trieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            childNode[i] = NULL;
        }
        isTerminal = false;
    }
};

// insertion & searching
class Trie {

public:
    trieNode* root;

    Trie() {
        root = new trieNode('\0');
    }
    // insertion Util
    void insertUtil(trieNode* root, string word) {

        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // index nikalo corresponding character ka
        int idx = word[0] - 'A';
        trieNode* child;

        if (root->childNode[idx] != NULL)
        {
            // present
            child = root->childNode[idx];
        }
        else
        {
            // absent
            child = new trieNode(word[0]);
            root->childNode[idx] = child;
        }

        // RECUSIVE CASE
        insertUtil(child, word.substr(1));

    }
    void insertWord(string word) {
        insertUtil(root, word);
    }

    // Searching
    bool searchUtil(trieNode* root, string word) {

        // base case
        if (word.length() == 0)
        {
            return root->isTerminal; // if terminal reach then 1 otherwise 0
        }

        int idx = word[0] - 'A';
        trieNode* child;

        // present
        if (root->childNode[idx] != NULL)
        {
            child = root->childNode[idx];
        }
        // absent
        else {
            return false;
        }

        // RECURSIVE CASES
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // Deletion
    bool removeUtil(trieNode* root, string word) {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return true;
        }

        if (searchUtil(root, word))
        {
            root->isTerminal = false;
            return true;
        }
        else
            return false;
    }
    bool removeWord(string word) {
        return removeUtil(root, word);
    }

};

int main()
{

    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("ARE");
    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("TIS");
    cout << "Present or Not: " << t->searchWord("ARM") << endl;
    cout << "Remove or not: " << t->removeWord("DO") << endl;
    cout << "Remove or not: " << t->removeWord("WOW") << endl;
    return 0;
}