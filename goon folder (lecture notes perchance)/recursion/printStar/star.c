#include <stdio.h>

void printRow(int nStars){
    if(nStars == 1){
        printf("*\n");
    }
    else{
        printf("*");
        printRow(nStars - 1);
    }
}

int main(void){
    int n;
    printf("Number of stars: ");
    scanf("%d", &n);
    printRow(n);
    return 0;
}