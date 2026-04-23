#include <stdio.h>
#define size 6

void reverseArray(int array[]);
void printArray(int array[]);

int main(void){ 
    int array[size]={2,5,7,8,9,12};
    reverseArray(array);
    printArray(array);
    return 0;
}

void reverseArray(int array[]){
    for (int min = 0, max = size - 1; min < max; min ++, max --){
        int temp = array[min];
        array[min] = array[max];
        array[max] = temp;
    }
}

void printArray(int array[]){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}