#include <stdio.h>
#include <stdlib.h>

int borderSum(int mat[][4], int n){
    int sum = 0;
    for(int r = 0; r < n; r++ ){
        for(int c = 0; c < n; c++){
            if(c == 0 || c == n-1 || r == 0 || r == n-1){
              sum += *(*(mat + r) + c);  
            }
        }
    }
    return sum;
}

int main(void){
    int n = 4, output;
    int matrix[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    output = borderSum(matrix, n);
    printf("%d\n", output);
    return 0;
}
