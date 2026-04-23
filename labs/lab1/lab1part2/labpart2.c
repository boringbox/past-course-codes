#include <stdio.h>

int main(void){
    double DailyRate;
    int RentalPeriod;
    const double HSTRate = 1.13;

    printf("Enter the daily rate: ");
    scanf("%lf", &DailyRate);
    printf("Enter the rental period (in days): ");
    scanf("%d", &RentalPeriod);

    int FreeDays = RentalPeriod/ 4;
    int ChargeDays = RentalPeriod - FreeDays;
    double Charge = (ChargeDays * DailyRate) * HSTRate;

    printf("Your total free day(s) in this rental is: %d \n", FreeDays);
    printf("Your total charge including taxes is: %.2lf \n", Charge);
    return 0;
}