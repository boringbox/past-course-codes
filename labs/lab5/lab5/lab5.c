#include <stdio.h>
#define ARRAY_SIZE 17 // Array fixed at 17 cells 

// Function Prototypes
void initializeArray(int aliveIndex, int array[]);
int getRuleOutcome(int rule, int left, int center, int right);
void calculateNextState(int currentArray[], int nextArray[], int rule);
void printArray(int array[]);
void simulateGenerations(int iterations, int array[], int newarray[], int rule);

// Main Function
int main(void){
    int iterations, IndexCell, rule; // Variables to cycle generations, where the first alivecell is, and rule number
    int CurrentArray[17]; // Array with size of 17
    int NextArray[17]; // Array with size of 17
    printf("Enter input: ");
    scanf("%d %d %d", &IndexCell, &rule, &iterations);
    initializeArray(IndexCell, CurrentArray);  // Call function to initialize array where IndexCell location is assigned 1
    simulateGenerations(iterations, CurrentArray, NextArray, rule); // Simulate generation as an iteration
     return 0;
}

// Functions
// This is to iterate the generations based on the iterations inputted
void simulateGenerations(int iterations, int array[], int newarray[], int rule){
    for(int i = 0; i < iterations; i++){
        printArray(array);
        calculateNextState(array, newarray, rule);  
    }
}

// Function to intialize array. All elements set to 0 first, then the desired alive cell is assigned 1. 
void initializeArray(int index, int array[]){
   for(int i = 0; i < ARRAY_SIZE; i++){
    array[i] = 0;
   }
   array[index] = 1;
}

// Function to print array, only print if element contains 1. 
void printArray(int array[]){
    for(int i = 0; i < ARRAY_SIZE; i++){
        if (array[i] == 1){
            printf("*"); 
        } else {
            printf(" "); 
        }
    }
    printf("\n");
}

// Function to get rule outcome. I kinda just copy and pasted the code lol
int getRuleOutcome(int rule, int left, int center, int right){
    int decimal = left * 4 + center * 2 + right;
    int bin[8] = {0};
    for(int i = 0; i <= 7; i++){
         bin[i] = rule % 2;
         rule /= 2;
    }
    int outcome = bin[decimal];
    return outcome;
}

// Function passing the new array to current array to print. Edge cases are basically taken out of the loop to make sure that there is no segmentation fault
void calculateNextState(int currentArray[], int nextArray[], int rule){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){
        int left = currentArray[i];
        int center = currentArray[i+1];
        int right = currentArray[i+2];
        nextArray[i+1] = getRuleOutcome(rule, left, center, right);
    }
    nextArray[0] = getRuleOutcome(rule, 0, currentArray[0], currentArray[1]);
    nextArray[16] = getRuleOutcome(rule, currentArray[15], currentArray[16], 0);
    for(int i = 0; i < ARRAY_SIZE; i++){
        currentArray[i] = nextArray[i];
    }
}