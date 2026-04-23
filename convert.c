#include <stdio.h>
#include <math.h>

void getInput(int* outFeet, int* outinches);
void printOutput(int feet, int inches, int metres, int centimetres);
void convert(int feet, int inches, int* outMetres, int* outCentimeres);

int main(void){
    int feet, inches;
    getInput(&feet, &inches);
    int meters, cmeters;
    convert(feet, inches, &meters, &cmeters);
    printOutput(feet, inches, meters, cmeters);
    return 0;
}

void getInput(int* feet, int* inches){
    printf("Please enter the feet and inches to convert: ");
    scanf("%d %d", feet, inches);
}

void convert(int feet, int inches, int* outMetres, int* outCentiMetres){
    double totalFeet =  feet + ((double) inches / 12.0);
    double metres = totalFeet * 0.3048;
    *outMetres = metres;
    *outCentiMetres = rint((metres - *outMetres) * 100);
}

void printOutput(int feet, int inches,int meters,int centimeters){
    printf("%d feet %d inches is %d metres and %d centimetres.\n", feet, inches, meters, centimeters);

}



