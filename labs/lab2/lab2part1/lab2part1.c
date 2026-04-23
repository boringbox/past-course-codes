#include <stdio.h>
#include <math.h>

int main(void){
    const double pi = 3.14159265; //This sets up both the constant and input variables needed for the calculations to begin 
    double LengthA; 
    double LengthB;
    double AngleAlphaDegree; 

    printf("Enter the length of side-A: "); //Asks for user input for LengthA, LengthB and the Degree Alpha in degrees respectively
    scanf("%lf", &LengthA);
    printf("Enter the length of side-B: ");
    scanf("%lf", &LengthB);
    printf("Enter the measure of angle alpha in degrees: ");
    scanf("%lf", &AngleAlphaDegree);

    double AngleAlphaRadian = AngleAlphaDegree * pi / 180; //This converts the input of angle alpha into degree 
    double AngleBetaDegree = asin(LengthB * (sin(AngleAlphaRadian)) / LengthA) * 180/pi; //This calculates the angle beta in degree through rearrangine the sine rule and multipying by 180/pi giving the desired output
    double AngleGammaRadian = pi - AngleAlphaRadian - (AngleBetaDegree*pi/180); //This calculates the final angle since the the total angle is 180 in a triangle
    double LengthC = (LengthA * sin(AngleGammaRadian) / sin(AngleAlphaRadian)); //Using sine rule again to find length C with the inputs of LengthA and Angle Alpha
    double AngleGammaDegree = AngleGammaRadian * 180 / pi; //Since the angle Gamma is in radian, this is converted into angle gamma

    printf("Results: \n"); //Output 
    printf("Side A: %.2lf \n", LengthA);
    printf("Side B: %.2lf \n", LengthB);
    printf("Side C: %.2lf \n", LengthC);
    printf("Angle Alpha: %.2lf degrees \n", AngleAlphaDegree);
    printf("Angle Beta: %.2lf degrees \n", AngleBetaDegree);
    printf("Angle Gamma: %.2lf degrees \n", AngleGammaDegree);    
    return 0;
}


/*
degree to radian = angle * pi/180 


*/