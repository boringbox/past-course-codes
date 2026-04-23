#include <stdio.h>
#define SIZE 5  // Declare a macro


int main(void){
    int sum = 0;
    double avg = 0;
    int grades[] = {7,8,3,1,6};  
    for (int index = 0; index < SIZE; index ++) {
        sum = sum + grades[index];
    }
    avg = (double) sum / SIZE; 
    printf("%lf", avg);
    return 0;
}
