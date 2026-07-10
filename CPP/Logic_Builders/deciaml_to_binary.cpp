#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int binary = 0, place = 1;

    while (n > 0) {
        int rem = n % 2;
        binary += rem * place;
        place *= 10;
        n /= 2;
    }

    cout << binary;
    return 0;
}