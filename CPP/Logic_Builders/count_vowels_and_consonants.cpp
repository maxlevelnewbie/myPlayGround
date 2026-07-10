#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int vowels = 0, consonants = 0;

    for (char ch : str) {
        ch = tolower(ch);

        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    cout << "Vowels = " << vowels << endl;
    cout << "Consonants = " << consonants << endl;

    return 0;
}