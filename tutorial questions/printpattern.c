//Generally, printing patterns programming questions requires a nested loop

/*
# of rows = user input
# of cols = user input * 2 - 1 

nestedloops: 1) 
             2)
*/

#include <stdio.h>
/*
int main(void){
    printf("Enter number of lines: ");
    int lines;
    scanf("%d", lines);
    for (int row = 1; row <= lines; row ++){
        for (int cols = 1; cols <= 2*lines - 1; cols ++){
            if (cols == 1 || cols <= 2 * lines - 1 || row ==1 ){
                printf("*"); 
            } else {
                printf("");
            }
        }
    }
    print("\n");
}
*/
int main(void){
    int a = -3 % 2;
    printf("%d",a);
    return 0;
}
