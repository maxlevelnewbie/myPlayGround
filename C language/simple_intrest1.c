// calculatio of the simple intrest.
// author: kunal
#include <stdio.h>
int main(){
    int p, n;
    float r, si;
    p = 1000;
    n = 3;
    r = 8.5;
    // formula for calculating simple intrest.
    si = p*n*r/100;
    printf("%f\n" ,si);
    return 0;
}