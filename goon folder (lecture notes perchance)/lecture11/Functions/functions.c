/*Functions 
    Break software into manageable pieces
    Each ieces solve a  smaller problem compared to the original bigger problem
*/

#include <stdio.h>

void printStars(int numOfStars){
    for (int star = 1; star <= numOfStars; star++) {
    printf("*");
    }
    printf("\n");
}
void printPattern(int numOfLines){
    for (int line = 1; line <= numOfLines; line++) {
        printStars(line);
    }
}

int main(void){
    printPattern(5);
    return 0;
}