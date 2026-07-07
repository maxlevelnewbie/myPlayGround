/*Insuarance of driver- using logical operators*/
#include<stdio.h>
int main(){
    char sex,ms;//ms=martial status
    int age;
    printf("Enter age,sex,martial status");
    scanf("%d%c%c", &age, &sex, &ms);
    if ((ms=='M')||(ms=='U'&& sex=='M'&& age>30)||(ms=='U'&& sex=='F'&&age>25))
        printf("Driver should be issued\n");
    else
        printf("Driver should not be insured\n");
        return 0;
}