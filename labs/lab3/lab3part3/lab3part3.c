#include <stdio.h>
#include <stdbool.h>

int main(void){
    // Variable Initialisation
    int InputDollars, Remainder, HundredAmount = 0, FiftyAmount = 0, TwentyAmount = 0, FivesAmount = 0, SumTotal = 0; 
    
    // Start of input
    printf("Please enter an amount in dollars ($): ");
    scanf("%d", &InputDollars);
    Remainder = InputDollars % 5;

    // Repeats function if dollars entered not in multiples of 5 
    while(Remainder != 0) {
        printf("The amount should be a multiple of $5: ");
        scanf("%d", &InputDollars);
        Remainder = InputDollars % 5;
    }

    // Calculations
    HundredAmount = InputDollars / 100;
    SumTotal = HundredAmount * 100 + FiftyAmount * 50 + TwentyAmount * 20 + FivesAmount * 5;

    FiftyAmount = (InputDollars - SumTotal) / 50;
    SumTotal = HundredAmount * 100 + FiftyAmount * 50 + TwentyAmount * 20 + FivesAmount * 5;

    TwentyAmount = (InputDollars - SumTotal) / 20;
    SumTotal = HundredAmount * 100 + FiftyAmount * 50 + TwentyAmount * 20 + FivesAmount * 5;

    FivesAmount = (InputDollars - SumTotal) / 5; 
    SumTotal = HundredAmount * 100 + FiftyAmount * 50 + TwentyAmount * 20 + FivesAmount * 5;

    // Output
    // Only prints this if value is not 0, if 0 then doesnt print
    if(HundredAmount != 0) {
        printf("$100: %d\n", HundredAmount);
    }
    if(FiftyAmount != 0) {
        printf("$50: %d\n", FiftyAmount);
    }
    if(TwentyAmount != 0) { 
        printf("$20: %d\n", TwentyAmount); 
    }
    if(FivesAmount != 0) {
        printf("$5: %d\n", FivesAmount);
    }

    return 0;
}