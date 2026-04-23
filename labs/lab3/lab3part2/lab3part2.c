#include <stdio.h>
#include <math.h>

int main(void){
    const double RobotHeight = 2; //variable declaration 
    const double GravityConst = 9.81;
    const double Pi = 3.14159265;
    double InitialSpeed = 20, HorizontalDistance = 0, VerticalHeight = 0, TimeTravel = 0, AngleAlpha = (0), VerticalDisplacement = 0, Difference = 0;
    
    do {
        printf("Please enter the horizontal distance from the wall between 3 and 30 m:\n"); // Repeat till user inputs valid number
        scanf("%lf", &HorizontalDistance); // this will be run by the computer at least once
    } while (!((HorizontalDistance >= 3) && (HorizontalDistance <= 30)));

    do {
        printf("Please enter the target height between 3 and 6 m:\n"); // Repeat till user inputs valid number
        scanf("%lf", &VerticalHeight);
    } while (!((VerticalHeight >= 3) && (VerticalHeight <= 6)));

    do {
        AngleAlpha = AngleAlpha + (Pi/180);
        TimeTravel = HorizontalDistance / (InitialSpeed * cos(AngleAlpha));
        VerticalDisplacement = RobotHeight + (InitialSpeed * sin(AngleAlpha) * TimeTravel) - (0.5 * GravityConst * TimeTravel * TimeTravel);
        Difference = fabs(VerticalDisplacement - VerticalHeight); // formula specified in lab 
    } while (Difference >= 0.3); // repeat calculations with an increment of equivalent of 1 degree while differennce of height and displacement is larger than 0.3
    
    AngleAlpha = AngleAlpha * (180 / Pi); // Converting radians to degrees 
    printf("The angle should be %.2lf\n", AngleAlpha); 
    return 0;
}
