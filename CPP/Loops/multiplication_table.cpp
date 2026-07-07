#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;

    int n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cout << num << "x" << i << " = " << num * i<< endl;
    }
    
return 0;
}