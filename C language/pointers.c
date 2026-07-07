// #include<stdio.h>
// void fun(int ,int);
// int main(){
//     int x=5,y=4;
//     fun(x,y);
//     printf("x=%d y=%d",x,y);
//     return 0;
// }
// void fun(int x,int y){
//     x=3;
//     y=6;
//     printf("x=%d y=%d\n",x,y);
// }
#include<stdio.h>
void fun(int *,int *);
int main(){
    int x=5,y=4;
    fun(&x,&y);
    printf("x=%d y=%d",x,y);
    return 0;
}
void fun(int *x,int *y){
    *x=3;
    *y=6;
    printf("x=%d y=%d\n",*x,*y);
}