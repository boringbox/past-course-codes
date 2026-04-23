#include <stdio.h>
#include <stdlib.h>

void getName(char* name){
    printf("Enter name: ");
    scanf("%s", name);
}

int main(void){
    char* n = (char*) malloc(10 * sizeof(char*));
    getName(n);
    printf("%s", n);
    free (n);
    n = NULL;
    return 0;
}

