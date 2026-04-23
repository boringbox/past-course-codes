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
bool checkPosition(char board[][WIDTH], int col, int row);
bool checkForWin(char board[][WIDTH]);

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
        if(checkForWin(gameboard)){
            break;
        }
        if(activePlayer == P1){
            activePlayer = P2;
        } 
        else{
            activePlayer = P1;
        }
        inputColumn = getPlayerColumnChoice(gameboard, activePlayer);
    }
    printf("Player %c wins!", activePlayer);
    return 0;
}

//Initalise board to set everything to empty
void clearBoard(char board[][WIDTH]){
    for(int row = 0; row < HEIGHT; row ++){
        for(int col = 0; col < WIDTH; col ++){
            board[row][col] = EMPTY;
        }
    }
}

//Prints board
void printBoard(char board[][WIDTH]){
    printf("0 1 2 3 4 5 6\n");
    for(int row = 0; row < HEIGHT; row ++){
        for(int col = 0; col < WIDTH; col ++){
            printf("%c ", board[row][col]);
        }
         printf("\n");
    }
}

// Get Player Move
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

//
void makeMove(char board[][WIDTH], char p, int col){
    bool hasInserted = false;
    for(int i = 0; i < HEIGHT && hasInserted == false; i++){
        if(board[5-i][col] == EMPTY){
            board[5-i][col] = p;
            hasInserted = true;
        }
    }
}

// Check a given position and see if theres a row, column or diagonal that fits a win position
bool checkPosition(char board[][WIDTH], int col, int row){
    if(board[row][col] == EMPTY){
        return false;
    }
    if(row<=2){
        if(board[row][col] == board[row+1][col] && board[row][col] == board[row+2][col] && board[row][col] == board[row+3][col]){
            return true;
        }
    }
    if(col>=3){
        if(board[row][col] == board[row][col-1] && board[row][col] == board[row][col-2] && board[row][col] == board[row][col-3]){
            return true;
        }
    }
    if(row<=2 && col<=3){
        if(board[row][col] == board[row+1][col+1] && board[row][col] == board[row+2][col+2] && board[row][col] == board[row+3][col+3]){
            return true;
        }
    }
    if(row<=2 && col>=3){
        if(board[row][col] == board[row+1][col-1] && board[row][col] == board[row+2][col-2] && board[row][col] == board[row+3][col-3]){
            return true;
        }
    }
    return false;
}

//Check win condition, loops through the 2D array and using the function above to see if any position triggers win cons
bool checkForWin(char board[][WIDTH]){
    for(int row = 0; row < HEIGHT; row++){
        for(int col = 0; col < WIDTH; col++){
            if (checkPosition(board, col, row)){
                return true;
            }
        }
    }
    return false;
}

