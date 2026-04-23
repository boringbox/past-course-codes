//
// Author: Yujie Seah
//

#include "lab8part1.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define validcons board,  n,  row,  col,  colour,  deltaRow,  deltaCol

void SwapPlayer(char PlayerTurn, char* PplayerTurn);
void clearBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
void EnterMove(char board[][26], int n, char colour, bool* invalidmove);
void FlipBoard(char board[][26],int n,int rowcoords,int colcoords,char colour);
void DecidePlayer(char botSide, char* PplayerSide);
void ComputerMove(char board[][26], int n, char colour);
int SimulatedFlipScore(char board[][26], int n, int rowcoords, int colcoords, char colour);
int CountEmptyPosition(char board[][26], int n);

bool CheckMove(char board[][26], int n, char input[4], char colour);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool isAdjacentNotEmpty(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool IsAdjacentColourOther(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool CheckFlipDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
bool ShowAvailableMoves(char board[][26], int n, char colour);

int main(void) {
  int nLimit;
  char gameboard[26][26];
  char Player = 'W';
  char Bot = 'B';
  char CurrentTurn = 'B';
  bool isGameOver = false;
  bool skipturn = false;
  bool invalidmove = false;

  // Setup for board size and what colour bot is playing for 
  printf("Enter the board dimension: ");
  scanf("%d", &nLimit);

  printf("Computer plays (B/W): ");
  scanf(" %c", &Bot);

  // Setup for board 
  DecidePlayer(Bot, &Player);
  clearBoard(gameboard, nLimit);
  printBoard(gameboard, nLimit);

  // Game Starts
  while(isGameOver == false){
    if(CurrentTurn == Bot){
      ComputerMove(gameboard, nLimit, Bot);
      skipturn = false;
    }
    else{
      EnterMove(gameboard, nLimit, Player, &invalidmove);
      skipturn = false;
      if(invalidmove){
        break;
      }
    }
    SwapPlayer(CurrentTurn, &CurrentTurn);
    if(CountEmptyPosition(gameboard, nLimit) == 0){
        break;
    }
    if(ShowAvailableMoves(gameboard, nLimit, CurrentTurn) == false){
      printf("%c player has no valid move.\n", CurrentTurn);
      if(skipturn == true){
        isGameOver == true;
        break;
      }
      if(skipturn == false){
        skipturn = true;
      }
      SwapPlayer(CurrentTurn, &CurrentTurn);
    }
    
  }
  if(invalidmove == true){
    SwapPlayer(CurrentTurn, &CurrentTurn);
    printf("%c player wins.\n", CurrentTurn);
  }
  else{
    int blackScore = 0, whiteScore = 0; 
    for(int row = 0; row < nLimit; row++){
      for(int col = 0; col < nLimit; col++){
        if(gameboard[row][col] == 'W'){
          whiteScore += 1;
        }
        if(gameboard[row][col] == 'B'){
          blackScore += 1;
        }
      }
    }
    if(whiteScore == blackScore){
      printf("Draw!\n");
    }
    if(whiteScore < blackScore){
      printf("B player wins.\n");
    }
    if(whiteScore > blackScore){
      printf("W player wins.\n");
    }
  }

  return 0; 
}



/* 

------------------------------------------------------------------------------------------------------------------- 


*/


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
bool ShowAvailableMoves(char board[][26], int n, char colour){
  int deltaRow, deltaCol;
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
          return true;
        }
      }
    }
  }
  return false;
}

// Function to enter move and pass the input to CheckMove
void EnterMove(char board[][26], int n, char colour, bool* invalidmove){
  char input[4];
  printf("Enter move for colour %c (RowCol): ", colour);
  scanf("%s", input);
  if(CheckMove(board, n, input, colour)){ //Swap back to colour
    printBoard(board, n);
  }
  else{
    printf("Invalid move.\n");
    *invalidmove = true;
  }
}

// Function to validate if its a valid move or not
bool CheckMove(char board[][26], int n, char input[4], char colour){
  int rowcoords = input[0] - 'a';
  int colcoords = input[1] - 'a';
  int deltaCol, deltaRow;
  if(!positionInBounds(n, rowcoords, colcoords)){
    return false;
  }
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

void FlipBoard(char board[][26],int n,int rowcoords,int colcoords,char colour){
  int deltaCol, deltaRow;
  int tempRow = rowcoords; int tempCol = colcoords;
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

void SwapPlayer(char PlayerTurn, char* PplayerTurn){
  if(PlayerTurn == 'W'){
    *PplayerTurn = 'B';
  }
  if(PlayerTurn == 'B'){
    *PplayerTurn = 'W';
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

void DecidePlayer(char botSide, char* PplayerSide){
    if(botSide == 'W'){
        *PplayerSide = 'B';
    }
    if(botSide == 'B'){
        *PplayerSide = 'W';
    }
}

void ComputerMove(char board[][26], int n, char colour){
  int score = 0, tempScore = -676767;
  int BestMoveCol = 0; int BestMoveRow = 0;

  for(int row = 0; row < 26; row++){
    for(int col = 0; col < 26; col++){
        tempScore = SimulatedFlipScore(board, n, row, col, colour);
        if(score < tempScore){
          BestMoveCol = col;
          BestMoveRow = row;
          score = tempScore;
        }
      }
    }

    //Actually flipboard based on highest score 
    FlipBoard(board, n, BestMoveRow, BestMoveCol, colour);
    printf("Computer places %c at %c%c.\n", colour, ('a'+BestMoveRow), ('a'+BestMoveCol));
    printBoard(board, n);
  }

int SimulatedFlipScore(char board[][26], int n, int rowcoords, int colcoords, char colour){
  int deltaCol, deltaRow, score = 0;
  int tempRow = rowcoords; int tempCol = colcoords;
  for(int i = 0; i < 8; i++){
    tempRow = rowcoords;
    tempCol = colcoords;
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

      if(positionInBounds(n, tempRow, tempCol) && isAdjacentNotEmpty(board, n, tempRow, tempCol, colour, deltaRow, deltaCol) && CheckFlipDirection(board, n, tempRow, tempCol, colour, deltaRow, deltaCol)){
        tempRow += deltaRow, tempCol += deltaCol;
        while(board[tempRow][tempCol] != colour){
          if(board[tempRow][tempCol] != colour){
            score += 1;
            tempRow += deltaRow, tempCol += deltaCol;
          }
          if(board[tempRow][tempCol] == colour){
          
            break;
          }
        }
      }
    }
  }
  return score;
}

int CountEmptyPosition(char board[][26], int n){
    int unoccupiedcounter = 0;
    for(int row = 0; row < n; row++){
      for(int col = 0; col < n; col++){
        if(board[row][col] == 'U'){
            unoccupiedcounter += 1;
        }
      }
    }
    return unoccupiedcounter;
}