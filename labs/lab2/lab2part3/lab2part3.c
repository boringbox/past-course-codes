#include <stdio.h>
#include <math.h>

int main(void){
    const double k = 8.9875e9; // Coulomb's Law Constant usually written as k in equations 
    double Charge1, Charge2, DistMetre, ElectrostaticForce; // Variables used for calculations
    char Unit1, Unit2, Unitcoulomb1, Unitcoulomb2; // Unit 1 and 2 are used to record the units while unitcoulomb are used to record the c. 

    // Input for program 
    printf("Enter the value of the two charges separated by a space: "); 
    scanf("%lf%c%c%lf%c%c", &Charge1, &Unit1, &Unitcoulomb1, &Charge2, &Unit2, &Unitcoulomb2);
    printf("Enter distance between charges in metres: ");
    scanf("%lf", &DistMetre);

    // Condition checking if the units are in microcoulombs then it is converted to the equivalent in coulombs, else it is converted to the equivalent in coulombs
    if (Unit1 == 'u') {
        Charge1 = Charge1 * 1e-6;
    } else {
        Charge1 = Charge1 * 1e-9; 
    }
    if (Unit2 == 'u') {
        Charge2 = Charge2 * 1e-6;
    } else {
        Charge2 = Charge2 * 1e-9; 
    }

    // Calculation once units are converted
    ElectrostaticForce = k * fabs(Charge1*Charge2) / pow(DistMetre, 2); 

    // Condition checking to display output in appropriate units of Newtons
    if (ElectrostaticForce < 1e-6) {
        ElectrostaticForce = ElectrostaticForce / 1e-9;
        printf("The force between charges is %.2lfnN (less than 1uN) \n", ElectrostaticForce);
    } else if (ElectrostaticForce < 1e-3) {
        ElectrostaticForce = ElectrostaticForce / 1e-6;
        printf("The force between charges is %.2lfuN (less than 1mN) \n", ElectrostaticForce);
    } else if (ElectrostaticForce < 1.0) {
        ElectrostaticForce = ElectrostaticForce / 1e-3;
        printf("The force between charges is %.2lfmN (less than 1N) \n", ElectrostaticForce);
    } else {
        printf("The force between charges is %.2lfN (1N or greater) \n", ElectrostaticForce);
    }
    return 0;
}