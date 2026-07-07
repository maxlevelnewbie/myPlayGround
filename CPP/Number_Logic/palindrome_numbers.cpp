// A palindrome number is a number that remains the same when its digits are reversed

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, originalNum, reverse = 0, digit;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    while (num != 0) {
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }

    if (originalNum == reverse)
        cout << originalNum << " is a palindrome." << endl;
    else
        cout << originalNum << " is not a palindrome." << endl;

    return 0;
}