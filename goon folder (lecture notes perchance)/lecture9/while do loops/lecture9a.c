#include <stdio.h>

/*Write a loop that promopts the user to enter a number between 1 and 100 (Inclusive). 
If the entered number is within the range, exit the loop. 
Otherwise, reprompt the user until the enter a number between the range*/

int main(void){
    int num;
    do {
        printf("Enter a number between 1 and 10: ");
        scanf("%d", &num);  
    } while (num < 1 || num > 10);
    return 0;
}