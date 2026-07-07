#include<stdio.h>
int main(){
    int num,a,b,c,sum;
    printf("enter a three digit number");
    scanf("%d",&num);
    a=num/100;
    num=num%100;
    b=num/10;
    num=num%10;
    c=num/1;
    sum=a+b+c;
    printf("sum is %d",sum);
    return 0;
}