// The Greatest Common Divisor (GCD) or Highest Common Factor (HCF)
// of two numbers is the largest number that divides both numbers exactly.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD (HCF) = " << a << endl;

    return 0;
}