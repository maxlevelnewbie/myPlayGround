//An Armstrong number(also called a narcissistic number) is a number that is equal to the sum of its digits,
//where each digit is raised to the power of the total number of digits.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, originalNum, digit, digits = 0;
    int sum = 0;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    while (num != 0)
    {
        digits++;
        num /= 10;
    }

    num = originalNum;

    while (num != 0)
    {
        digit = num % 10;
        sum = pow(digit, digits);
        cout << sum << endl;
        num /= 10;
    }

    if (sum == originalNum)
    {
        cout << originalNum << " is an Armstrong number." << endl;
    }
    else
    {
        cout << originalNum << " is not an Armstrong number." << endl;
    }

    return 0;
}