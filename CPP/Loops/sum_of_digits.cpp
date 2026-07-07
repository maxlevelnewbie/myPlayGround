#include <bits/stdc++.h>
using namespace std;

int main(){
    int num,mult = 1;
    cin >> num;

    while (num != 0) {
        int digit = num % 10;      // Get the last digit
        mult = mult * digit;
        num = num / 10;            // Remove the last digit
    }

    cout << mult << endl;
return 0;
}