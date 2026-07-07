#include<stdio.h>
int main(){
    int arr[]={4,7,8,9};
    int n;
    printf("%d\n",arr[0]);
    printf("%d\n",arr[1]);
    n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}