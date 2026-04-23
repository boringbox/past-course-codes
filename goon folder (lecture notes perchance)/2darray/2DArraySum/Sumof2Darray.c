#include <stdio.h>
#include <stdlib.h>

int sumArr(int cols, int row, int arr2D[][cols]);

int sumArr(int Cols, int Rows, int arr2D[][Cols]){
    int sum = 0;
    for (int row = 0; row < Rows; row++){
        for(int col = 0; col < Cols; col ++){
            sum += arr2D[row][col];

        }
    }
    return sum;
}

int main(void){
    int arr2D[][3] = {1,2,3,4,5,6};
    int summation = sumArr(3,2,arr2D);
    printf("%d\n", summation);
    return 0;
}