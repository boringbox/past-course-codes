#include <stdio.h>

/* A loop that prints 15 stars on the screen
int count = 1;
while(count<=15){
    print("*")
    count = count + 1;
    }


We can rewrite this while loop into a for loop (fixed # of iterations)
*/

int main(){
    for (int count = 1; count<=15; count = count + 1){
        printf("*");
    }
    return 0;
}