/* Decision Making with if-statements
A key capability of computers is to take decisions based on a condition

General form of if statement,
if(condition --> either true or false){ 
    statements to evaluate if condition is true 
}
else{
    statements to evaluate if conditions is false
}
*/

#include <stdio.h>

int main(void) {
    int height, width;
    printf("Please enter the height and width of your shape: ");
    scanf("%d %d", &height, &width);

    if (height == width) {
        printf("The shape is a square.");
    } else {
        printf("The shape is a rectangle.");
    }
    return 0;
}