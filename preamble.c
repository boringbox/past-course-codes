#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* preamble(char* str, int n);

char* preamble(char* str, int n){
    char* text = (char*) malloc((n+1) * sizeof(char));
    int index = 0;
    while(index < n){
        text[index] = str[index];
        index ++;
    }
    text[index] = '\0';
    return text;
}

int main(void){
    char* string = "Toronto";
    int n = 3;
    char* preamb = preamble(string, n);
    printf("%s\n", preamb); 
    free(preamb);
    preamb = NULL;
    return 0;
}

