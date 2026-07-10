#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int freq[256] = {0};

    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << char(i) << " : " << freq[i] << endl;
        }
    }

    return 0;
}