#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    printf("%d", rand()%6+1);
    return 0;
}

/* 
To generate a number between:
0 -> 5: x % 6
1 -> 6: (x % 6) + 1

MIN -> MAX :(x % (MAX-MIN + 1)) + MIN
*/