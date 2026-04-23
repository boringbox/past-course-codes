#include <stdio.h>


//Write a function that gets the factorial of n recursively

int factorial(int n){
    if( n == 1 || n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}

int main(void){
    int n;
    printf("Enter the n value: ");
    scanf("%d", &n);
    int f = factorial(n);
    printf("Factorial of %d is: %d\n", n, f);
    return 0;
}