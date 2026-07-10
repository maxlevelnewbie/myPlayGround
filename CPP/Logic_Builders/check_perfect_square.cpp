#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int root = sqrt(n);

    if (root * root == n)
        cout << "Perfect Square";
    else
        cout << "Not a Perfect Square";

    return 0;
}