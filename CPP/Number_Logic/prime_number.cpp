#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool isPrime = true;

    if(n <= 1){
        isPrime = false;
    }else{
        for(int i = 2;i < n;i++){
            if (n % i == 0){
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime){
        cout << n << " is prime number" << endl;
    }else{
        cout << n << " is not a Prime number" << endl;
    }
return 0;
}