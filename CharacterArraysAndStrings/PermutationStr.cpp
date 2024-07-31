#include<iostream>
using namespace std;

// Function to check if two frequency arrays are equal
bool checkEquals(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// Function to check if any permutation of s1 is a substring of s2
bool permutationStringInclusion(string s1, string s2) {
    // Edge case: if s1 is longer than s2, s2 cannot contain any permutation of s1
    if (s1.length() > s2.length()) {
        return false;
    }

    // Store character count for s1
    int arrCount1[26] = { 0 };
    for (int i = 0; i < s1.length(); i++) {
        int index = s1[i] - 'a';
        arrCount1[index]++;
    }

    // Traverse s2 string in window size of s1 string length
    int windowSize = s1.length();
    int arrCount2[26] = { 0 };

    // Initialize the first window
    for (int i = 0; i < windowSize; i++) {
        int index = s2[i] - 'a';
        arrCount2[index]++;
    }

    // Check if the first window matches
    if (checkEquals(arrCount1, arrCount2)) {
        return true;
    }

    // Slide the window over s2
    for (int i = windowSize; i < s2.length(); i++) {
        int newIndex = s2[i] - 'a';
        arrCount2[newIndex]++;

        int oldIndex = s2[i - windowSize] - 'a';
        arrCount2[oldIndex]--;

        if (checkEquals(arrCount1, arrCount2)) {
            return true;
        }
    }

    return false;
}

int main() {
    string s1, s2;
    s1 = "kl";
    s2 = "eidbaooo";
    bool permu = permutationStringInclusion(s1, s2);

    cout << permu << endl;
    if (permu) {
        cout << s2 << " => contains one permutation of => " << s1 << endl;
    }
    else {
        cout << s2 << " => doesn't contain one permutation of => " << s1 << endl;
    }

    return 0;
}
