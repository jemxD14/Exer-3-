#include<stdio.h>
#include<stdlib.h>

char board[3][3];
const char C1 = 'O', C2 = 'X';

void viewBoard(){
   printf("\nChallenger 1 = 'O' & Challenger 2 = 'X'");
   printf("\n\n %c || %c || %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n===||===||===\n");
   printf(" %c || %c || %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n===||===||===\n");
   printf(" %c || %c || %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}

void resetBoard(){   //i = 1st index and j == 2nd index
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         board[i][j] = ' ';
      }
   }
}

int checkSpace(){
   int space = 9;
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         if(board[i][j] != ' '){
            space--;
         }
      }
   }
   return space;
}

void challenger1Turn(){
   int row, column;
   do{
      printf("\nChallenger 1's Turn\n");
         do{
            printf("Enter Row: ");
            scanf("%d", &row);
            row--;
         }while(row < 0 || row > 2);

         do{
            printf("Enter Column: ");
            scanf("%d", &column);
            column--;
         }while(column < 0 || column > 2);

         if(board[row][column] != ' '){
            printf("Invalid move!\n\n");
         }
         else{
            board[row][column] = C1;
            break;
         }
   }while(board[row][column] != ' '); 
}

void challenger2Turn(){
   int row, column;
   do{
      printf("\nChallenger 2's Turn\n");
         do{
            printf("Enter Row: ");
            scanf("%d", &row);
            row--;
         }while(row < 0 || row > 2);

         do{
            printf("Enter Column: ");
            scanf("%d", &column);
            column--;
         }while(column < 0 || column > 2);

         if(board[row][column] != ' '){
            printf("Invalid move!\n\n");
         }
         else{
            board[row][column] = C2;
            break;
         }
   }while(board[row][column] != ' ');
}

char WinCheck(){
   for(int i = 0; i < 3; i++){
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
         return board[i][0];
      }
   }
   
   for(int i = 0; i < 3; i++){
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
         return board[0][i];
      }
   }
   
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      return board[0][2];
   }

return ' ';
}

void printWin(char winner){
   if(winner == C1){
      printf("\nTHE WINNER IS CHALLENGER 1!");
   }
   else if(winner == C2){
      printf("\nTHE WINNER IS CHALLENGER 2!");
   }
   else{
      printf("\nDRAW! THERE IS NO WINNER!");
   }
}

int main(){
   char winner = ' ';

    printf("=======================================\n");
    printf("             TIC-TAC-TOE            \n");
    printf("=======================================\n");
    resetBoard();
      while(winner == ' ' && checkSpace() != 0){
         viewBoard();
         challenger1Turn();
         winner = WinCheck();
            if(winner != ' ' || checkSpace() == 0){
               break;
            }

         viewBoard();
         challenger2Turn();
         winner = WinCheck();
            if(winner != ' ' || checkSpace() == 0){
               break;
            }
      }

    viewBoard();
    printWin(winner);
    printf("\nTHANK YOU! HOPE YOU ENJOYED!");

   return 0;
}
