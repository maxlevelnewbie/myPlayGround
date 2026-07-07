#include<stdio.h>
// int main(){
//     int n, i, even_count = 0, odd_count = 0;
    
//     printf("Enter the size of array: ");
//     scanf("%d", &n);
    
//     int arr[n];
    
//     printf("Enter the elements of array:\n");
//     for(i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }

//     for(i = 0; i < n; i++){
//         if(arr[i] % 2 == 0){
//             even_count++;
//         }
//         else{
//             odd_count++;
//         }
//     }
    
//     printf("\nCount of even elements: %d\n", even_count);
//     printf("Count of odd elements: %d\n", odd_count);
    
//     return 0;
// }
// int main(){
//     int a[5]={2,1,3,5,6};
//     int ec=0,oc=0;
//     for(int i=0;i<5;i++){   
//         if(a[i]%2==0){
//             ec++;
//         }
//         else{
//             oc++;
//         }
//     }
//     printf("Even count=%d\nOdd count=%d",ec,oc);
//     return 0;
// }

int main(){
    int a[5];
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    int ec=0,oc=0;
    for(int i=0;i<5;i++){   
        if(a[i]%2==0){
            ec++;
        }
        else{
            oc++;
        }
    }
    printf("Even count=%d\nOdd count=%d",ec,oc);
    return 0;
}