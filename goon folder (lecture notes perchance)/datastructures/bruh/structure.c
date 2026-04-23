#include <stdio.h>
#include <string.h>

// Method 1 to generate data structure 

/*
struct Nstruct{
    int neuronNum;
    double input1, input2, output;
    char name[50];
};


int main(void){
    struct Nstruct neuron1; // Creating a variable 
    neuron1.input1 = 7.3;
    struct Nstruct neuron2;
    neuron2.output = 6.7;
    return 0;
}
*/


//Method 2 

struct Nstruct{
int neuronNum;
double input1, input2, output;
char name[50];
} neuron1, neuron2, neurons[10];

int main(void){
    neuron1.input1 = 7.3;
    strcpy(neurons[2].name, "hippocampus");
    return 0;
}