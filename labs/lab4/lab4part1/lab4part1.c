#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


double InsidePoints = 0, TotalPoints = 0, Probability = 0;
bool inSafeZone(double x, double y);

double randDouble() { 
  return  ((2*(double)rand() / ((double)RAND_MAX))-1); 
}

int main (void){
    double x, y;
    srand(67);
    int Niterations = 0;
    printf("Number of Monte Carlo iterations: ");
    scanf("%d", &Niterations);
    for (int i = 0; i < Niterations; i++) {
        TotalPoints++;
        x = randDouble();
        y = randDouble();
        if (inSafeZone(x,y))
            InsidePoints ++;
    }
    Probability = InsidePoints / TotalPoints;
    printf("Probability of safe landing: %.4lf \n", Probability);
    return 0;
}

bool inSafeZone(double x, double y){
    if (x*x + y*y <= 1){
        return true;
    }
    else {
        return false;
    }

}
