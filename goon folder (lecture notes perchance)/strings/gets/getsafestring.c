#include <stdio.h>

char* getStrSafe(char* s, int size){
    int i = 0; 
    char c;
    while((c = getchar()) != '\n' && i < size-1){
        s[i] = c;
        i ++;
    }
    s[i] = '\0';
    return s;
}

int main(void){
    char st[67];
    int charsize = 67;
    printf("Get string: %s\n", getStrSafe(st, charsize));
    return 0;
}