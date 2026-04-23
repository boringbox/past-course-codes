#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 7
#define HEIGHT 6
#define CONNECT 4
#define P1 'X'
#define P2 'O'
#define EMPTY '-'

void clearBoard(char board[][WIDTH]);
void printBoard(char board[][WIDTH]);
int getPlayerColumnChoice(char board[][WIDTH], char p);
void makeMove(char board[][WIDTH], char p, int col);

int main(void){
    int inputColumn;
    char activePlayer = P1;
    char gameboard[HEIGHT][WIDTH];
    clearBoard(gameboard);
    printBoard(gameboard);
    inputColumn = getPlayerColumnChoice(gameboard, activePlayer);
   
    while(inputColumn >= 0){
        makeMove(gameboard, activePlayer, inputColumn);
        printBoard(gameboard);
        if(activePlayer == P1){
            activePlayer = P2;
        } 
        else{
            activePlayer = P1;
        }
        inputColumn = getPlayerColumnChoice(gameboard, activePlayer);
    }
}

void clearBoard(char board[][WIDTH]){
    for(int row = 0; row < HEIGHT; row ++){
        for(int col = 0; col < WIDTH; col ++){
            board[row][col] = EMPTY;
        }
    }
}

void printBoard(char board[][WIDTH]){
    printf("0 1 2 3 4 5 6\n");
    for(int row = 0; row < HEIGHT; row ++){
        for(int col = 0; col < WIDTH; col ++){
            printf("%c ", board[row][col]);
        }
         printf("\n");
    }
}

int getPlayerColumnChoice(char board[][WIDTH], char p){
    bool isValid = false;
    bool isEmpty = false;
    int positionCol = 0;

    while(isValid == false || isEmpty == false){
         printf("Player %c enter column: ", p);
         scanf("%d", &positionCol);
         if(positionCol < 0){
            return positionCol;
         }
         for(int i = 0; i < HEIGHT && isEmpty == false; i++){
            if(board[5-i][positionCol] == EMPTY){
                isEmpty = true;
            }
         }
         if(positionCol <= 6){
            isValid = true;
         }
    }
    return positionCol;
}

void makeMove(char board[][WIDTH], char p, int col){
    bool hasInserted = false;
    for(int i = 0; i < HEIGHT && hasInserted == false; i++){
        if(board[5-i][col] == EMPTY){
            board[5-i][col] = p;
            hasInserted = true;
        }
    }
}

        