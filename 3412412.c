#include <stdio.h>
#define size 6

void reverseArray(int array[]);
void printArray(int array[]);

int main(void){
    int randomArray[size]={2,5,7,8,9,12};
    reverseArray(randomArray);
    printArray(randomArray);
    return 0;
}

void reverseArray(int array[]){
    for(int low = 0, high = size - 1; low < high; low ++, high --){
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
}

void printArray(int* array){
    printf("[");
    for(int i = 0; i < size; i++){
        printf(" %d ", *(array + i));
    }
    printf("]\n");
}