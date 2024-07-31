#include <iostream>
#include <string>
using namespace std;

// String Compression Size
int compression(string& chrs) {
    int i = 0;
    int ansIndex = 0;
    int n = chrs.size();

    while (i < n) {
        int j = i + 1;
        while (j < n && chrs[i] == chrs[j]) {
            j++;
        }

        chrs[ansIndex++] = chrs[i];
        int count = j - i;
        if (count > 1) {
            string cnt = to_string(count);
            for (char ch : cnt) {
                chrs[ansIndex++] = ch;
            }
        }
        i = j;
    }

    return ansIndex;
}

int main() {
    string str;
    cout << "Enter a string to compress: ";
    cin >> str;

    int compressedSize = compression(str);
    cout << "Compressed string: " << str.substr(0, compressedSize) << endl;

    return 0;
}
