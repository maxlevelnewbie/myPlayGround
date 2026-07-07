// calculatio of the simple intrest.
// author: kunal
#include <stdio.h>
int main(){
    int p, n;
    float r, si;
    printf("Enter values of p, n, r");
    scanf("%d%d%f", &p, &n, &r);
    // formula for calculating simple intrest.
    si = p*n*r/100;
    printf("%f\n" ,si);
    return 0;
} 