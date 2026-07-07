// A Harshad Number (or Niven Number) is a number that is divisible by the sum of its digits.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, temp, digit, sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    temp = num;

    // Find the sum of digits
    while (temp != 0) {
        digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    // Check if the number is divisible by the sum of its digits
    if (num % sum == 0)
        cout << num << " is a Harshad Number.";
    else
        cout << num << " is not a Harshad Number.";

    return 0;
}