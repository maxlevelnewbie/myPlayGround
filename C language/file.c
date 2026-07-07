// You are using GCC
#include<stdio.h>
int main(){
 int A[3][3],B[3][3],C[3][3];

 for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
 scanf("%d", &A[i][j]);
 }
 }

 for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
 scanf("%d", &B[i][j]);
 }
 }

 for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
 C[i][j] = 0;
 for(int k=0;k<3;k++){
 C[i][j] += A[i][k]*B[k][j];

}
 }
 }

 for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
 printf("%d",C[i][j]);
 }
 if(i<2) printf("\n");
 }
 return 0;
}