#include <stdio.h>
#include <stdlib.h>

int main(void){
    int numOfStudents;
    int* marksArray;
    
    printf("Enter number of students: ");
    scanf("%d", &numOfStudents);
    marksArray = (int*) malloc(numOfStudents * sizeof(int));

    if(marksArray == NULL){
        printf("Failed at allocation"); 
        return 1;
    }
    
    for (int index = 0; index < numOfStudents; index++) {
        printf("Enter grades: ");
        scanf("%d", marksArray + index);
    }

    for(int i = 0; i < numOfStudents; i++){
        printf(" %d ", *(marksArray + i));
    }

    printf("\n");
    int sum = 0;
    for(int i = 0; i < numOfStudents; i++){
        sum += *(marksArray + i);
    }
    double avg = (double) sum / numOfStudents;
    printf("The average is: %.2lf \n", avg);

    free(marksArray);
    marksArray = NULL;
    return 0;
}