//An Automorphic Number is a number whose square ends with the number itself.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num, square, temp, digits = 0;

    cout << "Enter a number: ";
    cin >> num;

    square = num * num;
    temp = num;

    // Count digits in the number
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    // Calculate 10^digits without using pow()
    int divisor = 1;
    for (int i = 1; i <= digits; i++) {
        divisor *= 10;
    }

    if (square % divisor == num)
        cout << num << " is an Automorphic Number.";
    else
        cout << num << " is not an Automorphic Number.";

    return 0;
}