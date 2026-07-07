#include <stdio.h>

int isPrime(int num) {
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;
    
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int arr[] = {10, 2, 15, 7, 23, 13, 4, 19, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nPrime numbers in the array: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    
    return 0;
}
