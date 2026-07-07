// The Least Common Multiple (LCM) is the smallest positive number that is divisible by both given numbers.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, x, y;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    x = a;
    y = b;

    // Find GCD using Euclid's algorithm
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    int lcm = (a * b) / x;

    cout << "LCM = " << lcm << endl;

    return 0;
}