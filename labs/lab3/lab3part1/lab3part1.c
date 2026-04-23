#include <stdio.h>
#include <math.h>

int main(void){
    // Constants and variables for the program
    const int WaterBoilP = 100;
    const int MercuryBoilP = 357;
    const int CopperBoilP = 1187;
    const int SilverBoilP = 2193;
    const int GoldBoilP = 2660;
    int InputCelsius, ThresholdCelsius, TemperatureDifferenceMax, TemperatureDifferenceMin;

    // Input
    printf("Enter the threshold in Celsius: ");
    scanf("%d", &ThresholdCelsius);
    printf("Enter the observed boiling point in Celsius: ");
    scanf("%d", &InputCelsius);

    // Calculations
    TemperatureDifferenceMax = InputCelsius + ThresholdCelsius;
    TemperatureDifferenceMin = InputCelsius - ThresholdCelsius;

    // Logic
    if (WaterBoilP >= TemperatureDifferenceMin && WaterBoilP <= TemperatureDifferenceMax) {
        printf("The substance you tested is: Water \n");

    } else if (MercuryBoilP >= TemperatureDifferenceMin && MercuryBoilP <= TemperatureDifferenceMax) {
        printf("The substance you tested is: Mercury \n"); 

    } else if (CopperBoilP >= TemperatureDifferenceMin && CopperBoilP <= TemperatureDifferenceMax) {
        printf("The substance you tested is: Copper \n");

    } else if (SilverBoilP >= TemperatureDifferenceMin && SilverBoilP <= TemperatureDifferenceMax) {
        printf("The substance you tested is: Silver \n");

    } else if (GoldBoilP >= TemperatureDifferenceMin && GoldBoilP <= TemperatureDifferenceMax) {
        printf("The substance you tested is: Gold \n");
    } else {
        printf("Substance unknown.\n");
    }
    return 0;
}