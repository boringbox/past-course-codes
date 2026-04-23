#include <stdio.h>

int main(void){
    double MetreInput;
    const double CentimetertoInch = 2.54;
    printf("Please provide a distance in metres: ");
    scanf("%lf", &MetreInput);
    double TotalInch = (MetreInput * 100) / CentimetertoInch;
    int YardOutput =  (int) TotalInch / 36;
    int FeetOutput = (int) (TotalInch - (YardOutput * 36 )) / 12;
    int InchOutput = (int) TotalInch - (YardOutput * 36) - (FeetOutput*12);
    double InchRemainder = TotalInch - (YardOutput * 36 ) - (FeetOutput * 12) - InchOutput;
    printf("%d yards, %d feet, %d inches, %.2lf inches remainder \n", YardOutput, FeetOutput, InchOutput, InchRemainder);
    return 0;
}
