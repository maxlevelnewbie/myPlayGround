/*note counter using c*/
#include<stdio.h>
int main(){
    int amount,nofivehun,notwohun,nohun,nofifty,notwenty,noten,nofive,notwo,noone,total;
    printf("Enter the amount:");
    scanf("%d", &amount);
    nofivehun = amount/500;
    amount = amount%500;
    notwohun = amount/200;
    amount = amount%200;
    nohun = amount/100;
    amount = amount%100;
    nofifty = amount/50;
    amount = amount%50;
    notwenty = amount/20;
    amount = amount%20;
    noten = amount/10;
    amount = amount%10;
    nofive = amount/5;
    amount = amount%5;
    notwo = amount/2;
    amount = amount%2;
    noone = amount/1;
    amount = amount%1;
    total = nofivehun+nohun+nofifty+notwenty+noten+nofive+notwo+noone;
    printf("Smallest number of notes = %d\n",total);
    return 0;
}