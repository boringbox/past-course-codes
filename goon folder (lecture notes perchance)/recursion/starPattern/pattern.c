#include <stdio.h>

void printPattern(int nRow);
void printRow(int nStars);

int main(void){
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    printPattern(n);
    return 0;
}

void printRow(int nStars){
    if(nStars == 1){
        printf("*\n");
    }
    else{
        printf("*");
        printRow(nStars - 1);
    }
}

void printPattern(int nRow){
    if(nRow > 0){
        printRow(nRow);
        printPattern(nRow - 1);
        printRow(nRow);
    }
}