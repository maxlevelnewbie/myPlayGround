#include <iostream>
using namespace std;

int main() {
    int num, firstDigit, lastDigit;

    cout << "Enter a number: ";
    cin >> num;

    lastDigit = num % 10;

    while (num >= 10) {
        num /= 10;
    }

    firstDigit = num;

    cout << "First digit = " << firstDigit << endl;
    cout << "Last digit = " << lastDigit << endl;

    return 0;
}