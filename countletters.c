#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countLetters(char* string, int count[]){
    for(int i = 0; i < strlen(string); i++){
        for(int j = 0; j < 26; j++){
            if(string[i] == 'a' + j){
            count[j]++;
            }
        }
    }
}

int main(void){
    int count[26] = {0};
    char* s = "kazuha";
    countLetters(s, count);
    for(int i = 0; i < 26; i++){
        if(count[i] > 0){
            printf("%c: %d \n", 'a'+i, count[i]);
        }
    }
    return 0;
}