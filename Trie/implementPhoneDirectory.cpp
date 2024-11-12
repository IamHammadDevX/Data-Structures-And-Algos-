#include<iostream>
#include<vector>
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
        int idx = word[0] - 'a';
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

    // PRINT SUGGESTIONS
    void printSuggestions(trieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            trieNode* next = curr->childNode[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }

        }


    }
    vector<vector<string> > getSuggestions(string str) {

        trieNode* prev = root;
        vector<vector<string> > output;
        string prefix = "";

        for (int i = 0; i < str.size(); i++)
        {
            char lastChar = str[i];

            prefix.push_back(lastChar);

            // check for the last character
            trieNode* curr = prev->childNode[lastChar - 'a'];

            // if not found
            if (curr == NULL)
            {
                break;
            }

            // found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

// implement a CONTACT LIST or phone directory
vector<vector<string> > phoneDirectory(vector<string>& contactList, string& queryStr) {

    // create a trie
    Trie* t = new Trie();

    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->getSuggestions(queryStr);
}


int main() {
    vector<string> contactList = {
    "ada", "alan", "albert", "brendan", "bjarne", "bill", "brian", "charles", "claude",
    "dennis", "donald", "douglas", "edgar", "elon", "eric", "gene", "grace", "guido",
    "james", "john", "ken", "larry", "linus", "marc", "marissa", "martin", "mitch",
    "niels", "niklaus", "peter", "ray", "richard", "robert", "sergey", "sheryl",
    "steve", "tim", "vinton", "whitfield", "yukihiro", "zuse", "linus", "jeff",
    "hans", "andrew", "larry", "guido", "brendan", "johnny", "vint", "cleve",
    "robert", "edgar", "heather", "frank", "margaret", "katherine", "alix", "shafi",
    "subhash", "shree", "julia", "mike", "ron", "vaughan", "janet", "michael",
    "carl", "charles", "fred", "bob", "kent", "david", "anita", "mary", "mohammed",
    "kurt", "kevin", "scott", "stuart", "peter", "stephen", "richard", "marc",
    "ken", "ivan", "jennifer", "barbara", "yann", "geoffrey", "ian", "leslie",
    "mark", "paul", "john", "daniel", "jim", "jordan", "lily", "edward"
    };
    /*
    vector<string> contactList = {
        "sachin", "virat", "ricky", "jacques", "kumar", "chris", "ab", "brian",
        "ms", "mahela", "glenn", "wasim", "shane", "rahul", "muttiah", "viv",
        "allan", "steve", "sunil", "imran", "zaheer", "javed", "sanath", "andy",
        "david", "graeme", "ian", "shoaib", "younis", "brendon", "kane", "ross",
        "kagiso", "pat", "ben", "jofra", "stuart", "james", "ian", "monty",
        "zaheer", "lasith", "shaun", "glenn", "brett", "ravi", "adil", "kevin",
        "graeme", "michael", "sourav", "yuvraj", "gautam", "shikhar", "mohammad",
        "jasprit", "babar", "fakhar", "shaheen", "rashid", "mohammad", "andre",
        "dwayne", "sikandar", "tamim", "mushfiqur", "shakib", "mustafizur",
        "travis", "mitchell", "kyle", "trent", "tim", "aaron", "jason",
        "shubman", "hardik", "kl", "rishabh", "axar", "ravindra", "kuldeep",
        "umesh", "ishant", "washington", "marcus", "marnus", "alex", "usman",
        "mohammed", "faheem", "sarfaraz", "shoaib", "anil", "kapil", "sir",
        "don", "richard", "curtly", "courtney", "andy", "malcolm", "graeme",
        "herath", "rangana", "daniel", "corey", "tom", "lockie", "mark", "darren",
        "shubman", "haris", "ramiz", "saleem", "wasi", "abdul", "jofra", "ollie"
    };
    */

    string queryStr = "bil";

    // Call phone directory function with contact list and query string
    vector<vector<string>> suggestions = phoneDirectory(contactList, queryStr);

    // Output the suggestions
    cout << "Suggestions for query '" << queryStr << "':" << endl;
    for (int i = 0; i < suggestions.size(); i++) {
        cout << "Suggestions for prefix '" << queryStr.substr(0, i + 1) << "': ";
        for (const string& suggestion : suggestions[i]) {
            cout << suggestion << " ";
        }
        cout << endl;
    }

    return 0;
}
