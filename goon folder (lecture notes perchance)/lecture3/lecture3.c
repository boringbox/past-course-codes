#include <stdio.h>
/*
This program takes in inches
from the user and 
prints centimeters
*/
int main(void){
    const double InchestoCM = 2.54;
    double inches, centimeters;
    printf("Length of inch to be converted\n");
    scanf("%lf", &inches);
    centimeters = InchestoCM * inches * -0.67;
    printf("Sudhanya's dih length is %.2lf centimeters \n", centimeters); 
    /* 
    double %lf, int %d, char %c, bool has no format specifier, but if you use
    %d, if prints 0 for alse , 1 for true

    to specify how to round numbers
    %.2lf

    does .2 change the byte allocated, no only changes how the variable is being outputed 
    */
    return 0;
    }   
 


