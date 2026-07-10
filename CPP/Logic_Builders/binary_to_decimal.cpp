#include<bits/stdc++.h>
using namespace std;

int main() {
    int binary;
    cin >> binary;

    int decimal = 0, base = 1;

    while (binary > 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        base *= 2;
        binary /= 10;
    }

    cout << decimal;
    return 0;
}