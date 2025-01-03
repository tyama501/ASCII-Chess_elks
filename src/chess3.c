/*Copyright 2012 Parigyan Chandra Goyal & Sharat Shankar*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <unistd.h>
#include "AI.h"

#ifndef ELKS
//Added by Grant for testing:
#include "CuTest.h"
#endif

/* 
  1 = PAWN
  2 = KNIGHT
  4 = BISHOP
  5 = ROOK
  7 = QUEEN
  9 = KING
*/

// Computes if a move is valid and performs it
int compute(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]);

// Checks that the pawn can move
int checkPawnMove(int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]);

int checkKnightMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]);

int checkBishopMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]);

int checkRookMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]);

int checkKingMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]);

int checkQueenMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]);

// Prints the game board & instructions
void printing(char chp [2][8][8]);


int main(int argc, char *argv[])
{
#ifndef ELKS
  // Added by Grant for testing

  if (argc == 2 && strcmp(argv[1], "--test") == 0) {
	  RunAllTests();
  }

  else {

#endif
  //Original program
    char chess[2][8][8]={
                        {
                        {'5','2','4','7','9','4','2','1'},
                        {'1','1','1','1','1','1','1','1'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'1','1','1','1','1','1','1','1'},
                        {'5','2','4','7','9','4','2','5'},
                      },

                        {
                        {'1','1','1','1','1','1','1','1'},
                        {'1','1','1','1','1','1','1','1'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'2','2','2','2','2','2','2','2'},
                        {'2','2','2','2','2','2','2','2'},
                      }
                       };


     const char *ind[8][8]=
                        {                         
                        {"A1","A2","A3","A4","A5","A6","A7","A8"},
                        {"B1","B2","B3","B4","B5","B6","B7","B8"},
                        {"C1","C2","C3","C4","C5","C6","C7","C8"},
                        {"D1","D2","D3","D4","D5","D6","D7","D8"},
                        {"E1","E2","E3","E4","E5","E6","E7","E8"},
                        {"F1","F2","F3","F4","F5","F6","F7","F8"},
                        {"G1","G2","G3","G4","G5","G6","G7","G8"},
                        {"H1","H2","H3","H4","H5","H6","H7","H8"},
                        };

    int checker=1;
    int run = 108;
    while(run > 0)
    {

       printing(chess);
       char ent='0';


/***************************************TAKING THE INPUT**********************************************/
    if(checker%2 ==0)
    {
      sleep(2); 
       AIfunc(chess);
       checker++;
     }
   
    else if(checker%2 !=0)
     {
      printf("PLAYER 1 TYPE IN YOUR MOVE: ");
       

      int whitesp = 0;
      int n =0;
      int ck =0;
      int ik = 0;
      int fk =0;
      char d = '\0';
      char lin1[100];
      char initv[100], finlv[100],help[100];
      
      int par = 0;
      for(par = 0; par<100; par++)
      {  
          lin1[par] = '\0'; 
          initv[par] = '\0';
          help[par] = '\0';
          finlv[par] = '\0';
      }

      scanf(" %[^\n]s", lin1);
      int low=0;
      int len =strlen(lin1) - 1;

      for(low;low<=len;low++)
      {
        lin1[low]=toupper(lin1[low]);
      }

      for(n =0; n <=len ; n++)
      {
           if(lin1[n] == ' ' && n==0)
           continue;

           if(lin1[n] == ' ' && ((lin1[n-1] != ' ') && n!=0)){
                whitesp++;
           }

           if( whitesp == 0 && (n == 0 || lin1[n-1] == ' ') && lin1[n] != ' ')
                d = lin1[n];

           if(whitesp == 0 && lin1[n] != ' '){
                    help[ck] = lin1[n];
                    ck++;
           }

           if(whitesp == 1 && lin1[n] != ' '){
                    initv[ik] = lin1[n];
                    ik++;
            }

           if(whitesp == 2 && lin1[n] != ' '){
                    finlv[fk] = lin1[n];
                    fk++;
           }

      }

/*
      printf("\n");                            The comments have been left
      printf("%c \n", d);                      as such because people who are new
      printf("%s \n", lin1 );                  to the source code can uncomment the
      printf("%sa\n", help);                   statements and understand the significance
      printf("%s \n", initv);                  and working of the variables.
      printf("%s \n", finlv);

*/



/*************************************CALCULATING THE INDICES******************************************/       
       char *quit = "QUIT";
       int dep = 30;
       dep = strcmp(help,quit);
     /*  printf("dep%d",dep) */;

       char *display = "HELP";
       int ped =40;
       ped = strcmp(help, display);

       if(ped == 0)
       {
            printf("\n\n\n\n\n");
            printf("\t1 = PAWN\n\t2 = KNIGHT\n\t4 = BISHOP\n\t5 = ROOK\n\t7 = QUEEN\n\t9 = KING\n\n\n\n\n");

            printf("PRESS ENTER TO ESCAPE HELP:");
            char esc;

            if( (esc = getchar() ) == 'h' || (esc = getchar() )== 'H')
            continue;

       }

       if(dep == 0)
       { 
            printf("ENTER Y TO QUIT:");
            char y;
    
            if( (y = getchar() ) == 'y' || (y = getchar() )== 'Y')
            
            return 0;
       }


       ent = d;
       int error=0;       
       int i,j,k,l=0;
       int check;

       for (i=0;i<=7;i++)
        { check = 100;
          
          for (j=0;j<=7;j++)
           {  check = strcmp(ind[i][j],initv);
             if (check==0)
             break;
           };
	 
         if(check==0)
         break;       
       }    


       if(check!=0)
       {
          error++;
          printf("THERE IS NO INITIAL POSITION AS \"%s\"\n", initv);/*************ERROR ERROR*************/
       } 
      
        
       for (k=0;k<=7;k++)
        { check = 100;

          for (l=0;l<=7;l++)
           { check = strcmp(ind[k][l],finlv);
             if (check==0)
             break;
           };
         
         if(check==0)
         break;            
       }

      if(check!=0)
      {
         error++;
         printf("THERE IS NO FINAL POSITION AS \"%s\"\n", finlv);/*************ERROR ERROR*************/
      }
 
       char king = chess[0][k][l];

       if(checker%2 !=0 && chess[1][i][j]=='2')
       { 
         error=1;
         printf("PLAYER 1 YOU CANNOT ACCESS ARMY OF PLAYER 2\n");
       }  

       else if(checker%2 ==0 && chess[1][i][j]== '1')
       {
         error=1;
         printf("PLAYER 2 YOU CANNOT ACCESS ARMY OF PLAYER 1\n");
       }


 /*  system("clear");*/
     
       if(error ==0)
       {
        error =  compute(ent,i,j,k,l,0,chess);
       }

       if(error==0)
       { 
         checker++;  
       /*  printf("checker:%d  error a:%d\n",checker,error);*/
        }  

       else if( error !=0)
       {
       /*  printf("checker:%d  error b:%d\n",checker,error);*/ 
       }  

       if(king=='9' && error ==0 && checker%2 == 0)
       {printf("PLAYER 1 HAS WON THE GAME\n");
        break;
       }
    
       if(king=='9' && error ==0 && checker%2 != 0)
       {printf("PLAYER 2 HAS WON THE GAME\n");
        break;
       }  
     
      /*  printf("checker:%d  error c:%d\n",checker,error);*/
      
  }

 }
#ifndef ELKS
  }
#endif

   return 0;
}

/*
  Computes results of attempting a move

  printErrors means condition for stopping printf statements
  when printErrors ==1 do not print
*/
int compute(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]) {
  int q=0;

  switch(ent1) {
    case '1': // Piece is a Pawn
      q = checkPawnMove(fromRow, fromCol, toRow, toCol, printErrors, board);
      break;

    case '2': // Piece is a Knight
      q = checkKnightMove(ent1, fromRow, fromCol, toRow, toCol, printErrors, board);
      break;

    case '4': // Piece is a bishop
	     q = checkBishopMove(ent1, fromRow, fromCol, toRow, toCol, printErrors, board);
	     break;

    case '5': // Piece is a rook
      q = checkRookMove(ent1, fromRow,fromCol,toRow,toCol, printErrors, board);
      break;

    case'7': // Piece is a queen
      q = checkQueenMove(ent1, fromRow, fromCol, toRow, toCol, printErrors, board);
      break;

    case'9': // Piece is a king
      q = checkKingMove(ent1, fromRow, fromCol, toRow, toCol, printErrors, board);
      break;

    default: // Piece is not a valid entity
      if(printErrors == 0)
        printf("THERE IS NO ENTITY %c\n", ent1);
      break;
  }
   
    return q; // Return error value

}

// Checks that the pawn can move and performs it
int checkPawnMove(int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]) {
  // Return 1 if an error occurred, 0 if successful
  int error = 0;

  // If the piece belongs to player 1 (top)
  if (board[1][fromRow][fromCol]=='1') {
    // Check if the move would overrun a friendly piece
    if ((board[1][toRow][toCol]== '1' && toCol==fromCol) || (fromRow == 1 && board[1][2][fromCol] == '1' && fromCol==toCol)) {
      error = 1;
      if(printErrors == 0)
        printf("PLAYER 1 YOU CAN NOT OVERRUN YOUR ARMY\n"); /* ===== Error ===== */
    }

    // Check if the move would jump over an opponent piece
    else if (board[1][2][fromCol] == '2') {
      error = 1;
      if(printErrors == 0)
        printf("PLAYER 1 PAWN CAN'T JUMP OVER THE ENEMY\n");  /* ===== Error ===== */
    }

    else {
      // Check if the pawn is at its initial position (allow move forward 2)
      if (fromRow == 1 && (toRow == fromRow + 1 || toRow == fromRow + 2) && toCol == fromCol) {
        // Make the move if the space is empty
        if (board[1][toRow][toCol] == ' ') {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
        // Otherwise, give an error
        else {
          error = 1;
          if (printErrors == 0)
            printf("ILLEGAL MOVE\n");  /* ===== Error ===== */
        }
      }

      // Otherwise use rules for non-starting space moves forward
      else if (toRow==fromRow+1 && toCol==fromCol) {
        // Make the move if the space is empty
        if (board[1][toRow][toCol] == ' ') {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
        // Otherwise give an error
        else {
          error = 1;
          if (printErrors == 0)
            printf("ILLEGAL MOVE\n"); /* ===== Error ===== */
        }
      }

      // If the pawn is moving diagonally, only allow it to take pieces
      else if (toRow == fromRow+1 && (toCol==fromCol-1 || toCol==fromCol+1)) {
        // Make the move if the space has an opponent piece
        if (board[1][toRow][toCol] == '2') {
            board[0][toRow][toCol]=board[0][fromRow][fromCol];
            board[1][toRow][toCol]=board[1][fromRow][fromCol];   
            board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
        // Otherwise give an error
        else {
          error = 1;
          if(printErrors == 0)
            printf("ILLEGAL MOVE\n"); /* ===== Error ===== */
        }
      }

      // Any other moves are illegal
      else
      {    error = 1;
            if(printErrors == 0)
              printf("PLAYER 1 ILLEGAL MOVE\n");  /* ===== Error ===== */

      }
    }
  }

  // Else if piece belongs to player 2 (bottom)
  else if (board[1][fromRow][fromCol]=='2') {
    // Check if the move overruns a friendly piece
    if ((board[1][toRow][toCol]== '2' && toCol == fromCol) || (fromRow==6 && board[1][5][fromCol] == '2' && fromCol == toCol)) {
      error = 1;
      if (printErrors == 0)  
        printf("PLAYER 2 YOU CAN NOT OVERRUN YOUR ARMY\n"); /* ===== Error ===== */
    }
    // Check if the move jumps over an opponent's piece
    else if (board[1][5][fromCol] == '1') {
      error = 1;
      if(printErrors == 0)
        printf("PLAYER 2 PAWN CAN'T JUMP OVER THE ENEMY\n");  /* ===== Error ===== */
    }
    else {
      // Check if the pawn is at its initial position (allow move 2 forward)
      if (fromRow == 6 && (toRow == fromRow - 1 || toRow == fromRow - 2) && toCol == fromCol) {
          // If the space is empty, perform the move
          if(board[1][toRow][toCol] == ' ') {
            board[0][toRow][toCol]=board[0][fromRow][fromCol];
            board[1][toRow][toCol]=board[1][fromRow][fromCol];
            board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
          }
          // Otherwise, give an error
          else {
            error = 1;
            if(printErrors == 0)
              printf("ILLEGAL MOVE\n"); /* ===== Error ===== */
          }
      }

      // If it is anywhere else, do not allow moving 2 spaces forward
      else if (toRow == fromRow - 1 && toCol == fromCol) {
        // If the space is empty, perform the move
        if (board[1][toRow][toCol] == ' ') {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
        // Otherwise, give an error
        else {
          error = 1;
          if(printErrors == 0)
            printf("ILLEGAL MOVE\n"); /* ===== Error ===== */
        }
      }

      // If moving diagonally, only allow pawn to take pieces
      else if (toRow == fromRow - 1 && (toCol == fromCol - 1 || toCol == fromCol + 1)) {
        // If the space has an opponent's piece, move into it and take it
        if (board[1][toRow][toCol] == '1') {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
        // Otherwise, give an error
        else {
          error = 1;
          if(printErrors == 0)
            printf("ILLEGAL MOVE\n"); /* ===== Error ===== */
        }
      }

      // Any other moves are illegal
      else {
        error = 1;   
        if(printErrors == 0)
          printf("YOUR MOVE IS ILLEGAL\n");/************ERROR ERROR***************/
      }
    }
  }
  return error;
}

int checkKnightMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]){
  int q = 0;
  switch(chess[0][fromRow][fromCol])    
    { case '2':/***CHECKS WHETHER KNIGHT IS THERE OR NOT******/
          {     
                if( (toRow == fromRow+2 || toRow == fromRow-2) && (toRow>=0 && toRow<=7) && (toCol == fromCol+1 || toCol == fromCol-1) && (toCol>=0 && toCol<=7) )
                {/*******FOR VERTICAL MOVEMENT*************/
                          if(chess[1][fromRow][fromCol] == chess[1][toRow][toCol] )
                          {
                              q =1;
                              if(printErrors == 0)
                                printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                          }
                      

                          else
                          {
                                chess[0][toRow][toCol]=chess[0][fromRow][fromCol];
                                chess[1][toRow][toCol]=chess[1][fromRow][fromCol];
                                chess[0][fromRow][fromCol]=chess[1][fromRow][fromCol]=' ';

                          }
                    
                }
            
          
              else if( (toRow == fromRow+1 || toRow == fromRow-1) && (toRow>=0 && toRow<=7) && (toCol == fromCol+2 || toCol== fromCol-2) && (toCol>=0 && toCol<=7) )
                {/*********FOR HORIZONTAL MOVEMENT***********/
                          if(chess[1][fromRow][fromCol] == chess[1][toRow][toCol] )
                          {
                              q =1;
                              if(printErrors == 0)
                                printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                          }


                          else
                          {
                                chess[0][toRow][toCol]=chess[0][fromRow][fromCol];
                                chess[1][toRow][toCol]=chess[1][fromRow][fromCol];
                                chess[0][fromRow][fromCol]=chess[1][fromRow][fromCol]=' ';

                          }

                }

                else
                {
                          q =1;
                          if(printErrors == 0)
                            printf("YOUR KNIGHT MOVE IS ILLEGAL\n");/************ERROR ERROR***************/
                }
                
  break;}/*BREAK OF CASE 2*/


  default:
        {
          q =1;
          if(printErrors == 0)
            printf("KNIGHT IS NOT AT THE SPECIFIED POSITION\n");/************ERROR ERROR***************/
        }
  }       
  return q;
}

int checkBishopMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]){

   int q = 0;

   switch(board[0][fromRow][fromCol])
   { case '4': /***CHECKS WHETHER BISHOP IS THERE OR NOT******/
      {    int bis;
	 bis = toRow - fromRow;                                     
	 /*   printf("%d\n",bis);*/
	 if(toCol == bis + fromCol || toCol == (-1)*bis + fromCol)
	 {      
	    int var = bis - 1;
	    if(bis < 0){
	       var = (-1)*bis -1;
	    }
	    for(var; var >0; var--)
	    {    
	       if(bis > 0 && toCol > fromCol)
	       { 
		  if(board[1][fromRow+var][fromCol+var] == ' ')
   						      continue;     

		  else
		  {
		     q =1;
		     if(printErrors == 0)
			printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
		     break;
		  }
	       }

               
	       else if(bis > 0 && toCol < fromCol)
	       {
		  if(board[1][fromRow+var][fromCol-var] == ' ')
		     continue;
		  else
		  {
		     q =1;
		     if(printErrors == 0)
			printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
		     break;
		  }
	       }

	       else if(bis < 0 && toCol > fromCol)
	       {
		  if(board[1][fromRow-var][fromCol+var] == ' ')
		     continue;
		  else
		  {
		     q =1;
		     if(printErrors == 0)
			printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
		     break;

		  }
	       }

                  
	       if(bis < 0 && toCol < fromCol)
	       {
		  if(board[1][fromRow-var][fromCol-var] == ' ')
		     continue;
		  else
		  {
		     q =1;
		     if(printErrors == 0)
			printf("BISHOP CAN'T JUMP\n");/*******ERROR ERROR*********/
		     break;
		  }
	       }

	    }

	    if(board[1][fromRow][fromCol] == board[1][toRow][toCol])
	    {
	       q =1;
	       var = 1;
	       if(printErrors == 0)
		  printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
	    }


	    if(var == 0)
	    {
	       board[0][toRow][toCol]=board[0][fromRow][fromCol];
	       board[1][toRow][toCol]=board[1][fromRow][fromCol];
	       board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';

	    }

	 }

         
	 else
	 {
	    q =1;
	    if(printErrors == 0)
	       printf("INVALID MOVE OF BISHOP\n"); /************ERROR ERROR***************/
	 }
                              

	 break;}/***END OF CASE 4 ***********/


      default:
      {   q =1;
	 if(printErrors == 0)
	    printf("BISHOP IS NOT AT THE SPECIFIED POSITION\n"); /************ERROR ERROR***************/
      }
   }
   
   return q;

}

int checkRookMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char chess[2][8][8]) {
  int q = 0;
  switch(chess[0][fromRow][fromCol]){ 
    case '5':/***CHECKS WHETHER ROOK IS THERE OR NOT******/
            {
                  if(toCol==fromCol)
                  {/*******FOR VERTICAL MOVEMENT*************/
                            int rip;
                            rip = toRow - fromRow;
                            int vap = rip-1;           

                            if(rip <0)
                            {
                                vap = (-1)*rip-1;
                            }

                            for(vap; vap>0; vap--)
                            { 
                                  if(rip>0)
                                  {   
                                      if(chess[1][fromRow + vap][fromCol] == ' ')
                                      continue;

                                      else
                                      {  
                                          q =1; 
                                          if(printErrors == 0)
                                            printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                          break;
                                      }
                                  }

                                  else if(rip<0)
                                  {
                                      if(chess[1][fromRow - vap][fromCol] == ' ')
                                      continue;
            
                                      else
                                      {
                                          q =1;
                                          if(printErrors == 0)
                                            printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                          break;
                                      }
                                  }

                            }

                            if(chess[1][fromRow][fromCol] == chess[1][toRow][toCol] )
                            {
                                q =1;
                                vap = 1;
                                if(printErrors == 0)
                                  printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
                            }


                            if(vap ==0)
                            {
                                  chess[0][toRow][toCol]=chess[0][fromRow][fromCol];
                                  chess[1][toRow][toCol]=chess[1][fromRow][fromCol];
                                  chess[0][fromRow][fromCol]=chess[1][fromRow][fromCol]=' ';

                            }

                  }

                  else if(toRow==fromRow)
                  {/******FOR HORIZONTAL MOVEMENT*************/
                            int rhip;
                            rhip = toCol - fromCol;
                            int vhap = rhip -1 ;

                            if(rhip <0)
                            {  
                                vhap = (-1)*rhip-1;
                            }

                            for(vhap; vhap>0; vhap--)
                            {
                                  if(rhip>0)
                                  {
                                      if(chess[1][fromRow][fromCol + vhap] == ' ')
                                      continue;

                                      else
                                      {   
                                          q =1;
                                          if(printErrors == 0)
                                            printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                          break;
                                      }
                                  }

                                  else if(rhip<0)
                                  {
                                      if(chess[1][fromRow][fromCol - vhap] == ' ')
                                      continue;

                                      else
                                      {
                                          q =1;
                                          if(printErrors == 0)
                                            printf("ROOK CAN'T JUMP\n");/*******ERROR ERROR*********/
                                          break;
                                      }
                                  }


                            }

                            if(chess[1][fromRow][fromCol] == chess[1][toRow][toCol] )
                            {   
                                q =1;
                                vhap = 1;
                                if(printErrors == 0)
                                  printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
                            }


                            if(vhap ==0)
                            {
                                  chess[0][toRow][toCol]=chess[0][fromRow][fromCol];
                                  chess[1][toRow][toCol]=chess[1][fromRow][fromCol];
                                  chess[0][fromRow][fromCol]=chess[1][fromRow][fromCol]=' ';

                            }

                  }
            
                else
                  {
                      q =1;
                      if(printErrors == 0)
                        printf("INVALID MOVE FOR ROOK\n"); /*******ERROR ERROR*********/
                    
                  }


        break;}/***END OF CASE 5 ***********/


    default:
          { 
            q =1;
            if(printErrors == 0)
              printf("ROOK IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
          }

  }/*******************************END OF ROOK**************************************/
  return q;
}

int checkQueenMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]){
 
  int q;

  switch(board[0][fromRow][fromCol]){             /***CHECKS WHETHER QUEEN IS THERE OR NOT******/
    case'7': {                   
      if(toCol==fromCol) {                        /*******FOR VERTICAL MOVEMENT*************/
        int rip;
        rip = toRow - fromRow;
          int vap = rip-1;

          if(rip <0) {  
              vap = (-1)*rip-1;
          }

            for(vap; vap>0; vap--) {
            if(rip>0) {
              if(board[1][fromRow + vap][fromCol] == ' ')
                continue;
              else {   
                q =1;
                if(printErrors == 0)
                  printf("QUEEN CAN'T JUMP\n");       /*******ERROR ERROR*********/
                break;
              }
            }
            else if(rip<0) {
              if(board[1][fromRow - vap][fromCol] == ' ')
                continue;
              else {
                q =1;
                if(printErrors == 0)
                  printf("QUEEN CAN'T JUMP\n");       /*******ERROR ERROR*********/
                  break;
                }
            }
          }

        if(board[1][fromRow][fromCol] == board[1][toRow][toCol] ) {
          q =1;
          vap = 1;

          if(printErrors == 0)
            printf("YOU CANNOT OVERRUN YOUR ARMY\n");/************ERROR ERROR***************/
        }

        if(vap ==0) {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
      }
    
      else if(toRow==fromRow) {                     /******FOR HORIZONTAL MOVEMENT*************/
        int rhip;
        rhip = toCol - fromCol;
        int vhap = rhip -1 ;

        if(rhip <0) {
          vhap = (-1)*rhip-1;
        }

        for(vhap; vhap>0; vhap--) {
          if(rhip>0) {
            if(board[1][fromRow][fromCol + vhap] == ' ')
              continue;
            else {
              q =1;
              if(printErrors == 0)
                printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
            break;
            }
          }
          else if(rhip<0) {
            if(board[1][fromRow][fromCol - vhap] == ' ')
              continue;
            else {
              q =1;
              if(printErrors == 0)
                printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
              break;
            }
          } 
        }

        if(board[1][fromRow][fromCol] == board[1][toRow][toCol] ) {
          q =1;
          vhap = 1;
          if(printErrors == 0)
            printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
        }

        if(vhap ==0) {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
      }

      else {
        int bis;
          bis = toRow - fromRow;
          /*printf("%d\n",bis);*/
        if(toCol == bis + fromCol || toCol == (-1)*bis + fromCol) {
          int var = bis - 1;
          if(bis < 0){
            var = (-1)*bis -1;
          }
          for(var; var >0; var--) {
            if(bis > 0 && toCol > fromCol) {
              if(board[1][fromRow+var][fromCol+var] == ' ')
                continue;
              else {
                q =1;
                if(printErrors == 0)
                  printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                break;
              }
            }
            else if(bis > 0 && toCol < fromCol) {
              if(board[1][fromRow+var][fromCol-var] == ' ')
                continue;
              else {
  					    q =1;
                if(printErrors == 0)
                  printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                break;
              }
            }
            else if(bis < 0 && toCol > fromCol) {   
              if(board[1][fromRow-var][fromCol+var] == ' ')
                continue;
              else {   
                q =1;
                if(printErrors == 0)
                  printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
                break;
              }
            }

          if(bis < 0 && toCol < fromCol) {   
            if(board[1][fromRow-var][fromCol-var] == ' ')
              continue;
            else {   
              q =1;
              if(printErrors == 0)
                printf("QUEEN CAN'T JUMP\n");/*******ERROR ERROR*********/
              break;
            }
          }
        }

        if(board[1][fromRow][fromCol] == board[1][toRow][toCol]) {
          q =1;
          var = 1;
          if(printErrors == 0)
            printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
        }

        if(var == 0) {
          board[0][toRow][toCol]=board[0][fromRow][fromCol];
          board[1][toRow][toCol]=board[1][fromRow][fromCol];
          board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
        }
      }
  
        else {
          q =1;
          if(printErrors == 0)
            printf("INVALID MOVE FOR QUEEN\n");/*******ERROR ERROR*********/
        }
      }
    
    break; 
  }                              /********END OF CASE 7 ************/
    
  default: {
    q =1;
    if(printErrors == 0)
      printf("QUEEN IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
    }           
  }
  
  return q;
  
  /***********************************END OF QUEEN ****************************************/

}

int checkKingMove(char ent1, int fromRow, int fromCol, int toRow, int toCol, int printErrors, char board[2][8][8]){

   int q = 0;
             
   switch(board[0][fromRow][fromCol])/***CHECKS WHETHER QUEEN IS THERE OR NOT******/
   {case'9':
      {

	 if( (toRow == fromRow + 1 || toRow == fromRow-1) && (toCol == fromCol || toCol==fromCol-1 || toCol == fromCol+1) )
	 {

	    if(board[1][fromRow][fromCol] == board[1][toRow][toCol])
	    {  
	       q =1; 
	       if(printErrors == 0)
		  printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
	    }

	    else
	    {
	       board[0][toRow][toCol]=board[0][fromRow][fromCol];
	       board[1][toRow][toCol]=board[1][fromRow][fromCol];
	       board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';

	    }

	 }  

	 else if( (toRow == fromRow) && (toCol==fromCol-1 || toCol == fromCol+1) )
	 {
	    if(board[1][fromRow][fromCol] == board[1][toRow][toCol])
	    {
	       q =1;
	       if(printErrors == 0)
		  printf("YOU CANNOT OVERRUN YOUR ARMY\n"); /************ERROR ERROR***************/
	    }

	    else                                  
	    {
	       board[0][toRow][toCol]=board[0][fromRow][fromCol];
	       board[1][toRow][toCol]=board[1][fromRow][fromCol];
	       board[0][fromRow][fromCol]=board[1][fromRow][fromCol]=' ';
               
	    }

	 }

	 else
	 {
	    q =1;
	    if(printErrors == 0)
	       printf("ILLEGAL MOVE FOR KING\n"); /************ERROR ERROR***************/
	 }

	 break;}/********END OF CASE 9 ************/

      default:
      { 
	 q =1;
	 if(printErrors == 0)
	    printf("KING IS NOT AT THE SPECIFIED POSITION\n");/***********ERROR ERROR**************/
      }
   }

      return q;

}

// Prints current board state to console
void printing(char chp [2][8][8])
{     
     int a,b;
     a =b =0;
     int  len, brd, buffer;   /*len = length & brd = breadth*/
     brd = len = 8;
     printf("\n\n\n\n\n");

     printf("                             \x1b[31m PLAYER \x1b[0m                            \n");
     printf("           1      2      3      4      5      6      7      8    \n");
     buffer = len;
     printf("       --");

      for(len; len>0; len--){
       printf("-------");
      }

      printf("\n");
      len = buffer;

      int i;
      char alpha = 'A';
      int vert = 0;
      for(brd; brd>0; brd--)
      {
          a = 8 - brd;
          i = 3;
          if(i==3)
          {
              len = buffer;
              int hor =0;

              printf("       |");
              for(len; len>0; len--)
              {
                  if( (hor+vert)%2 == 0 )
                  {
                    printf("       ");
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                    printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588");     /* the characters inside the print statement*/
                  }                                                           /* are unicodes used for printing the chess grid*/
                  hor++;
              }

              printf("|");
              printf("\n");
              i--;
         }

         if(i==2)
         {
              len = buffer;
              int hor =0;
              printf("     %c |",alpha);

              for(len; len>0; len--)
              {
                  b = 8 - len;
                  if( (hor+vert)%2 == 0 )
                  {
                      if(chp[1][a][b] == '1')
                      {
                       printf("   \x1b[31m%c\x1b[0m   ", chp[0][a][b]);                   /*unicode*/
                      }

                      if(chp[1][a][b] == ' ')
                      {
                       printf("       ");
                      }

                      if(chp[1][a][b] == '2')
                      {
                       printf("   \x1b[32m%c\x1b[0m   ", chp[0][a][b]);                   /*unicode*/
                      }
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                      if(chp[1][a][b] =='1')
                      {
                       printf("\u2588\u2588\u258C\x1b[31m%c\x1b[0m\u2590\u2588\u2588", chp[0][a][b]);
                      }

                      if(chp[1][a][b] =='2')
                      {
                       printf("\u2588\u2588\u258C\x1b[32m%c\x1b[0m\u2590\u2588\u2588", chp[0][a][b]);
                      }

                      if(chp[1][a][b] ==' ')
                      {
                       printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588", chp[0][a][b]);
                      }

                  }
                  hor++;

             }

              printf("| %c", alpha);
              printf("\n");
              i--;
         }

         if(i==1)
         {
              len = buffer;
              printf("       |");
              int hor =0;

               for(len; len>0; len--)
               {
                  if( (hor+vert)%2 == 0 )
                  {
                    printf("       ");
                  }

                  else if( (hor+vert)%2 != 0 )
                  {
                    printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
                  }
                  hor++;

               }

             printf("|");
             printf("\n");
             i--;
         }

          alpha++;
          vert++;
     }


     len = buffer;
     printf("       --");

      for(len; len>0; len--){
       printf("-------");
      }
             printf("\n");

     printf("           1      2      3      4      5      6      7      8    \n");
     printf("                             \x1b[32mCOMPUTER\x1b[0m                            \n\n");
     printf("       '1'=>PAWN        '2'=>KNIGHT          '4'=>BISHOP\n       '5'=>ROOK        '7'=>QUEEN           '9'=>KING");
     printf("\n\n");


}
