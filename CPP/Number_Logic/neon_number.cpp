// A Neon Number is a number where the sum of the digits of its square is equal to the number itself.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, square, sum = 0, digit;

    cout << "Enter a number: ";
    cin >> num;

    square = num * num;

    while (square != 0) {
        digit = square % 10;
        sum += digit;
        square /= 10;
    }

    if (sum == num)
        cout << num << " is a Neon Number.";
    else
        cout << num << " is not a Neon Number.";

    return 0;
}