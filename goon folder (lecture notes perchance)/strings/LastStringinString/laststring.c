#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lastStringInString(char* s1, char* s2);

int main(void){
    char* s = "This is a sample string";
    char* s1 = "is";
    
    return 0;
}

char* lastStringInString(char* s1, char* s2){
    char* p = s2;
    char* lastfound = NULL;

    while(*p != '\0'){
        if(strncmp(s1, p, strlen(s1)) == 0){
            lastfound = p;
        }
        p++;
    }
    return lastfound;
}