//
// Author: Yujie Seah
//

#include "reversi.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define validcons board,  n,  row,  col,  colour,  deltaRow,  deltaCol

void SwapPlayer(char Player, char* Pplayer);
void clearBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
void BoardConfig(char board[][26]);
void ShowAvailableMoves(char board[][26], int n, char colour);
void EnterMove(char board[][26], int n, char colour);
void FlipBoard(char board[][26],int n,int rowcoords,int colcoords,char colour);

bool CheckMove(char board[][26], int n, char input[4], char colour);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool isAdjacentNotEmpty(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool IsAdjacentColourOther(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool CheckFlipDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);

int main(void) {
  int nLimit;
  char gameboard[26][26];
  char currentPlayer = 'W';

  printf("Enter the board dimension: ");
  scanf("%d", &nLimit);
  clearBoard(gameboard, nLimit);
  printBoard(gameboard, nLimit);
  BoardConfig(gameboard);
  printBoard(gameboard, nLimit);  

  ShowAvailableMoves(gameboard, nLimit, currentPlayer);
  SwapPlayer(currentPlayer, &currentPlayer); //Swap to Black
  ShowAvailableMoves(gameboard, nLimit, currentPlayer);
  
  EnterMove(gameboard, nLimit, currentPlayer);

  return 0; 
}

// Initialise the first phase of the board so that only the center 4 pieces are W or B with the rest being Unoccupied
void clearBoard(char board[][26], int n){
  int midpoint = (n-1)/2;

  for(int row = 0; row < 26; row++){
    for(int col = 0; col < 26; col++){
      board[row][col] = 'U';
    }
  } 
  board[midpoint][midpoint] = 'W';
  board[midpoint+1][midpoint+1] = 'W';
  board[midpoint+1][midpoint] = 'B';
  board[midpoint][midpoint+1] = 'B';
}

// Print board duh
void printBoard(char board[][26], int n){
  char initial = 'a' - 1;
  printf("  ");
  for(int i = 0; i < n; i++){
    printf("%c", 'a' + i);
  }
  printf("\n");

  for(int row = 0; row < n; row++){
    initial = initial + 1;
    printf("%c ", initial);

    for(int col = 0; col < n; col++){
      printf("%c", board[row][col]);
    }
    printf("\n");
  }
}

// Configure board to a point in the game
void BoardConfig(char board[][26]){
  char input[4]; //For the input of a 3 number string including null character
  printf("Enter board configuration:\n");
  while(strcmp(input , "!!!") != 0){
    scanf("%s", &input);
    if(input[0] == 'W'){
      board[input[1]-'a'][input[2]-'a'] = 'W';
    }
    if(input[0] == 'B'){
      board[input[1]-'a'][input[2]-'a'] = 'B';
    }
  }
}

// Check whether the position is inside the bounds of the game
bool positionInBounds(int n, int row, int col){
  if(row < 0 || col < 0){
    return false;
  }
  if(row >= n || col >= n){
    return false;
  }
  else{
    return true;
  }
}

// Generalised form of checking legal direction
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  int tempRow = row, tempCol = col;
  if(board[row][col] != 'U'){
    return false;
  }

  if(IsAdjacentColourOther(validcons) && isAdjacentNotEmpty(validcons)){
    tempRow += deltaRow;
    tempCol += deltaCol;
    while(true){
      tempRow += deltaRow;
      tempCol += deltaCol;
      if(positionInBounds(n, tempRow, tempCol) == false){
        return false;
      }
      if(board[tempRow][tempCol] == 'U'){
         return false;
        }
      if(board[tempRow][tempCol] == colour){
        return true;
      }
    }
  }
  return false;
}

// Helper function to check whether the next immediate position has the opposite colour
bool IsAdjacentColourOther(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  if(positionInBounds(n, row + deltaRow, col + deltaCol) == false){
    return false;
  }
  if(board[row + deltaRow][col + deltaCol] == colour){
      return false;
    }
    else{
      return true;
    }
}

// Helper functio to check whether the next immediate position is empty
bool isAdjacentNotEmpty(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  if(positionInBounds(n, row + deltaRow, col + deltaCol) == false){
    return false;
  }
  if(board[row + deltaRow][col + deltaCol] == 'U'){
    return false;
  }
  else{
    return true;
  }
}

// Function to display available moves for a certain player using functions from above
void ShowAvailableMoves(char board[][26], int n, char colour){
  int deltaRow, deltaCol;
  printf("Available moves for %c:\n", colour);
  for(int row = 0; row < n; row++){
    for(int col = 0; col < n; col++){
      for(int i = 0; i < 8; i++){
        //South
        if(i == 0){
          deltaCol = 0, deltaRow = 1;
        }
        //SouthWest
        if(i == 1){
          deltaCol = -1, deltaRow = 1;
        }
        //SouthEast
        if(i == 2){
          deltaCol = 1, deltaRow = 1;
        }
        //North
        if(i == 3){
          deltaCol = 0, deltaRow = -1;
        }
        //NorthEast
        if(i == 4){
          deltaCol = 1, deltaRow = -1;
        }
        //NorthWest
        if(i == 5){
          deltaCol = -1, deltaRow = -1;
        }
        //West
        if(i == 6){
          deltaCol = -1, deltaRow = 0;
        }
        //East
        if(i == 7){
          deltaCol = 1, deltaRow = 0;
        }
        if(checkLegalInDirection(board, n, row, col,  colour, deltaRow, deltaCol)){
          printf("%c%c\n", row + 'a', col + 'a');
          break;
        }
      }
    }
  }
}

// Function to enter move and pass the input to CheckMove
void EnterMove(char board[][26], int n, char colour){
  char input[4];
  printf("Enter a move:\n");
  scanf("%s", &input);
  if(CheckMove(board, n, input, input[0])){ //Swap back to colour
    printf("Valid move.\n");
  }
  else{
    printf("Invalid move.\n");
  }
  printBoard(board, n);
}

// Function to validate if its a valid move or not
bool CheckMove(char board[][26], int n, char input[4], char colour){
  int rowcoords = input[1] - 'a';
  int colcoords = input[2] - 'a';
  int deltaCol, deltaRow;
  if(!positionInBounds(n, rowcoords, colcoords)){
    return false;
  }
  if(input[0] == colour){
    for(int i = 0; i < 8; i++){
        //South
        if(i == 0){
          deltaCol = 0, deltaRow = 1;
        }
        //SouthWest
        if(i == 1){
          deltaCol = -1, deltaRow = 1;
        }
        //SouthEast
        if(i == 2){
          deltaCol = 1, deltaRow = 1;
        }
        //North
        if(i == 3){
          deltaCol = 0, deltaRow = -1;
        }
        //NorthEast
        if(i == 4){
          deltaCol = 1, deltaRow = -1;
        }
        //NorthWest
        if(i == 5){
          deltaCol = -1, deltaRow = -1;
        }
        //West
        if(i == 6){
          deltaCol = -1, deltaRow = 0;
        }
        //East
        if(i == 7){
          deltaCol = 1, deltaRow = 0;
        }
        if(checkLegalInDirection(board, n, rowcoords, colcoords, colour, deltaRow, deltaCol)){
          FlipBoard(board, n, rowcoords, colcoords, colour);
          return true;
        }
      }
      return false;
  }
}

void FlipBoard(char board[][26],int n,int rowcoords,int colcoords,char colour){
  int deltaCol, deltaRow;
  int tempRow = rowcoords, tempCol = colcoords;
  board[tempRow][tempCol] = colour;
  for(int i = 0; i < 8; i++){
    //South
    if(i == 0){
      deltaCol = 0, deltaRow = 1;
    }
    //SouthWest
    if(i == 1){
      deltaCol = -1, deltaRow = 1;
    }
    //SouthEast
    if(i == 2){
      deltaCol = 1, deltaRow = 1;
    }
    //North
    if(i == 3){
      deltaCol = 0, deltaRow = -1;
    }
    //NorthEast
    if(i == 4){
      deltaCol = 1, deltaRow = -1;
    }
    //NorthWest
    if(i == 5){
      deltaCol = -1, deltaRow = -1;
     }
    //West
    if(i == 6){
      deltaCol = -1, deltaRow = 0;
    }
    //East
    if(i == 7){
      deltaCol = 1, deltaRow = 0;
    }
    tempRow = rowcoords, tempCol = colcoords;
    if(positionInBounds(n, tempRow, tempCol) && isAdjacentNotEmpty(board, n, tempRow, tempCol, colour, deltaRow, deltaCol) && CheckFlipDirection(board, n, tempRow, tempCol, colour, deltaRow, deltaCol)){
      tempRow += deltaRow, tempCol += deltaCol;
      while(board[tempRow][tempCol] != colour){
        if(board[tempRow][tempCol] != colour){
          board[tempRow][tempCol] = colour;
          tempRow += deltaRow, tempCol += deltaCol;
        }
        if(board[tempRow][tempCol] == colour){
          break;
        }
      }
    }
  }
}

void SwapPlayer(char Player, char* Pplayer){
  if(Player == 'W'){
    *Pplayer = 'B';
  }
  if(Player == 'B'){
    *Pplayer = 'W';
  }
}

bool CheckFlipDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){
  int tempRow = row, tempCol = col;

  if(IsAdjacentColourOther(validcons) && isAdjacentNotEmpty(validcons)){
    tempRow += deltaRow;
    tempCol += deltaCol;
    while(true){
      tempRow += deltaRow;
      tempCol += deltaCol;
      if(positionInBounds(n, tempRow, tempCol) == false){
        return false;
      }
      if(board[tempRow][tempCol] == 'U'){
         return false;
        }
      if(board[tempRow][tempCol] == colour){
        return true;
      }
    }
  }
  return false;
}