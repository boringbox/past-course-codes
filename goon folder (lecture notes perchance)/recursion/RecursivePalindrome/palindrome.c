#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindromeRecursive(char *s, int low, int high){
    if(low >= high){
        return true; 
    }
    else if(s[low] != s[high]){
        return false;
    }
    else{
        return isPalindromeRecursive(s, low+1, high -1);
    }
}

bool isPalindrome(char *s){
    return isPalindromeRecursive(s, 0, strlen(s) - 1);
}

int main(void){
    printf("%d\n", isPalindrome("stats"));
    return 0;
}