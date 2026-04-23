#include <stdio.h>
int main(void){
    int nPizzas, nSlices;
    printf("How many pizzas do you have?\n");
    scanf("%d", &nPizzas); //scanf takes in input
        //%d means a format specifier for intengers (format specifier)
         // &nPizzas means input will be assigned to nPizzas (address operator)
    nSlices = nPizzas * 8;
    printf("You have %d slices in %d pizzas.\n", nSlices, nPizzas);
    return 0;
}