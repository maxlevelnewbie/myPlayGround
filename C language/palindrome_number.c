#include <stdio.h>


int isPalindrome(int num) {
    int original = num;
    int reversed = 0;
    
    if (num < 0)
        return 0;
    
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    int arr[] = {121, 123, 151, 456, 101, 999, 1221, 100, 11, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nPalindrome numbers in the array: ");
    for (int i = 0; i < n; i++) {
        if (isPalindrome(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    
    return 0;
}
