//calculation of simple intrest for 3 sets of p,n,r
#include<stdio.h>
int main(){
    int p,n,count;
    float r,si;
    count=1;
    while (count<=3)
    {
        printf("\nEnter value fo p,n,r");
        scanf("%d%d%f",&p,&n,&r);
        si=p*n*r/100;
        printf("Simple intrest=Rs.\n%f",si);
        count=count+1;
    }
    return 0;
}