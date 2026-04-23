#include <stdio.h>
#include <string.h>


int main(void){
    char s[] = "Note: Enjoy APS105";
    char find[] = "Enjoy";
    printf("%s", strstr(s, find));
    return 0;
}