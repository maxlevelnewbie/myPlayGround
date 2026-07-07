/*Determine overtime pay for 10 employees*/
#include<stdio.h>
int main(){
    float outpay;
    int hour,i=1;
    while (i<=10)
    {
        printf("\nEnter no.of hours worked:");
        scanf("%d",&hour);
        if (hour>=40)
        {
            outpay=(hour-40)*120;
        }
        else
        {
            outpay=0;
        }
        printf("Hours=%d Overtime pay=Rs.%f\n",hour,outpay);
        i++;
    }
    return 0;
}