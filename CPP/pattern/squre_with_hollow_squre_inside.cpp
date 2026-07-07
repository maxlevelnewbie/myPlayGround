#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int spaces = 0;
    for(int i = 0;i < n; i++){
        for (int j = 1; j<= n -i; j++)
        {
            cout << "*";
        }
        for(int j = 0;j<spaces;j++){
            cout << " ";
        }

        for (int j = 1; j<= n -i; j++)
        {
            cout << "*";
        }
        spaces += 2;
        cout <<endl;
    }
    spaces = 8;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j<= i; j++)
        {
            cout << "*";
        }
        for(int j = 0;j<spaces;j++){
            cout << " ";
        }

        for (int j = 1; j<= i; j++)
        {
            cout << "*";
        }
        spaces -= 2;
        cout <<endl;
    }
}