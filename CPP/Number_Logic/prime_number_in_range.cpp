#include <bits/stdc++.h>
using namespace std;

int main() {
    int start, end;

    cout << "Enter starting number: ";
    cin >> start;
    cout << "Enter ending number: ";
    cin >> end;

    cout << "Prime numbers between " << start << " and " << end << " are:\n";

    for (int i = start; i <= end; i++) {
        if (i < 2)
            continue;

        bool isPrime = true;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
            cout << i << " ";
    }

    return 0;
}