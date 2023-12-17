#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <Windows.h>
#define SIZE 8


// Initializing board
char board[SIZE][SIZE] =  {
                          {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                          {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                          {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                          {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'}};

// To confirm is a piece is present on the location
int confirm_piece(char board[][SIZE],int current_row,int current_column,char ch)
{
 	// c for col 
 	// r for row
 	if (board[current_row][current_column] == ch)
 		return 1;
    else
        return 0;
} //end of confirm_piece

// Confirming if there is a space or not (when moving to a location where a piece is already present)
int confirm_space(char board[][SIZE],int final_row,int final_column) 
{
    // if there is space or not
 	if (board[final_row][final_column] == 'O'|| board[final_row][final_column] == 'X')
 		return 0;
 	else
        return 1;
} //end of confirm_space

// this function is responsible for removing a piece on the board
int capture_piece(char board[][SIZE],int diag_row,int diag_col,int current_row,int current_col, bool isComputer)
{
    char current_piece = board[current_row][current_col];
 	char diag_piece;

    // checks which piece is at current location
 	if (current_piece == 'X' || current_piece == 'K') {
        diag_piece = 'O';
 	} else if (current_piece == 'O' || current_piece == 'Q') {
        diag_piece = 'X';
    }

 	// if middle location empty, return 0
 	if (board[diag_row][diag_col] == ' ') {
        if (isComputer == false)
            printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE ONE SPACE DIAGONALLY!\n");
        return 0;
 	}
    // if middle location has the players piece present in current location return 0
    else if (board[diag_row][diag_col] == current_piece) {
        if (isComputer == false)
            printf("INVALID LOCATION ENTERED: YOUR PIECE IS ALREADY THERE DIAGONALLY\n");
        return 0;
    }
    // replace the middle piece with space
    else {
        if (board[diag_row][diag_col] == diag_piece || 
            (board[diag_row][diag_col] == 'K' && current_piece == 'O') ||
            (board[diag_row][diag_col] == 'Q' && current_piece == 'X') ||
            (board[diag_row][diag_col] == 'Q' && current_piece == 'K') ||
            (board[diag_row][diag_col] == 'K' && current_piece == 'Q')) {
 	     	board[diag_row][diag_col] = ' ';
            return 1;
        }
 	}
 	
} // end of capture_piece

//Display the board
void display(char board[][SIZE]){
      printf("====================\n");
      printf("  ||0|1|2|3|4|5|6|7|\n");
       printf(" _|=================\n");
      for ( int i = 0; i < SIZE;i++){
      	printf("|%d|", i);
      	for (int j = 0; j < SIZE; j++){
      		printf("|");
      		printf("%c",board[i][j] );
      	}

      	 printf("|");
         if(i==7){
         	printf("\n====================");
         }

      	printf("\n");
      	
      	
      }
       printf("Player 1 is: X\nPlayer 2 is: O\n");
      return;
}//end of display

// this function moves a piece, and replaces space in a previous location the piece was at
// it also is responsible for creating king piece
void move_piece(char board[][SIZE],int irow,int icol,int frow,int fcol,char a)
{
    // checks if a piece should become king
    // if piece reaches final row
    // player 1 
    if (a == 'X' && frow == 7) {
        board[irow][icol] = ' ';
        char b = 'K';
        board[frow][fcol] = b;
    }
    // player 2 condition
    else if (a == 'O' && frow == 0) {
        board[irow][icol] = ' ';
        board[frow][fcol] = 'Q';
    }
    // normal piece condition
    else {
        board[irow][icol] = ' ';
        board[frow][fcol] = a;
    }
    return;
} // end of move_piece

// king function 
int kingfun(char board[][SIZE],int rowintial,int colintial,int row,int col, int difrow,int difcol,int b,int c){
        // b and c are mod of difrow and dif col
        // if it can move 2 rows and 2 cols (simple words: will it move 2 spaces diagonally)
        if(b==2&&c==2){
            // basically checks if king is to move up or downwards
           if (difrow > 0) {
             switch (difcol) {
                // when moving rightwards
                case 2:
                    // if chackforbak is not 1 then that means incorrect final location was entered
                 if (chackforbak(board, row + 1,col +1, rowintial, colintial) != 1) {
                    printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                    return 1;
                  }
                  // when moving leftwards
                case -2:
                  if(chackforbak(board,row+1,col-1,rowintial,colintial) != 1){
                    printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                    return 1;
                   }
                  default:return 0;
                }//end of switch
            }//end of if (difrow > 0)
            else
                // same as above but for downwards
            if(difrow<0){
                switch(difcol){
                   case -2:
                     if(chackforbak(board,row-1,col-1,rowintial,colintial)!=1){
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                     }
                
                   case 2: 
                    if(chackforbak(board,row-1,col+1,rowintial,colintial)!=1){
                        printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
                        return 1;
                     }    
                    default: return 0;
                    }//end of switcah
                  }//end of if (difcol > 0)
        }//end of if b == 2 && a == 2//for king
        else 
        // if user wants to move 1 space only
        if (b==1&&c==1){
            // if piece already there or not
           if (board[row][col]!=' '){
              printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
              return 1;
           }else return 0;
        }else
            return 0;
}//end of king function

//this function can take input from 1st person
void fsinput(char board[][SIZE]){
        // to find current location of the piece
	   int rowintial,colintial;
       // to get location to move to
        int row,col;
        int i=1;
        int a;
        //loop ends when correct location is entered by the user
        while(i==1){

           printf("Enter Row, Column Of The Man You Want To Move: ");
           scanf("%d %d", &rowintial, &colintial);
           // conferm1 returns 1 if input was valid 
            a =  conferm1(board,rowintial,colintial,'X');
            // checks if input was out of bounds
           if ((rowintial<0||rowintial>7)||(colintial<0||colintial>7) )
           {
           	printf("INVALID INPUT: OUT OF BOUNDS!\n");
           }
           else{
            // a = 1 means input by user was correct
            if(a==0){
                // if king is there then i=-1, so that loop can end
                if(board[rowintial][colintial]!='K'){
                     printf("INVALID LOCATION ENTERED: YOU DONT HAVE A PIECE HERE\n");
                }else i=-1;
           }else i=-1;
          }
        }
          i=1;
        //loop ends when location to move to is correctly entered by the user
         while(i>0){

           printf("Enter Row, Column Where You Want To Move: ");
            scanf("%d %d", &row, &col);
           // returns 0 if the location to move to is empty
            a =  conferm2(board,row,col);
            int difrow=  rowintial-row ;
            int  difcol=  colintial-col;
            int b;//use as  a mod function for row
            int c;//use as a mod function for colume
            if(difrow<0){
                b = difrow*(-1);
             }else{
             b=difrow;
            }
            if(difcol<0){
            	c = difcol*(-1);
            }else{
            	c=difcol;
             }

           if ((row<0||row>7)||(col<0||col>7) ){
           	printf("INVALID INPUT: OUT OF BOUNDS!\n");
           }
           // to check if user wants to move more than 2 locations
           else 
           if(difcol>2||difrow>2){
           	  printf("You cannot move to this location\n");
           }else
           if (b!=c){
              printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
           }else
            if(board[rowintial][colintial]=='K'){
                // ki stores 0 if king can move, 1 if king cant move
                 int ki= kingfun(board,rowintial,colintial,row,col,difrow,difcol,b,c);
                 if(ki==0){
                    i=-1;
                 }
            
             }else
             if(a==0){
               printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE\n");
           }else 
            // b =2 and c=2 means user is to move two locations
            if(b==2&&c==2){
            	if(difrow>0){
            		printf("INVALID LOCATION ENTERED!");
            	}else
           	    if(difrow<0){
           	  	 switch(difcol){
           	  	  case -2:
                    // row-1, col-1 gives the middle location
           	  		if(chackforbak(board,row-1,col-1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		
           	  	  case 2: 
           	  		if(chackforbak(board,row-1,col+1,rowintial,colintial)!=1){
           	  			printf("your move is roung enter valid adderass\n");
           	  		}
           	  		
           	  	  default:i=-1;
           	  	}//end of switcah
           	  }//end of if difcol > 0
           	}//end of if b == 2 && c == 2
           	else 
           	if (b==1&&c==1){
           		if (board[row][col]!=' '){
           		 printf("you can't move hear becouse there is already an pice\n");//change karna 
           		}else
           		i=-1; 
            }else
            if (difrow >0){
               printf("you con't move in this location:\n");//cahng karna 
            }else{
           		i=-1;
           		break;
              }//end else
            }
            // moves the piece to the final location after middle location has been set to space
           movepice(board,rowintial,colintial,row,col,board[rowintial][colintial]);
            
	return;
}//end of input of frist preson


//in this function we take input for second person 
void scinput(char board[][SIZE]){
	   int rowintial,colintial;//we use these veriabe for find courent location of guti
        int row,col;//we use these veribel for d
        int i=1;
        int a;
        //by this loop we take initil position of guti
        while(i==1){

           printf("Enter Row, Column Of The Man You Want To Move: ");
           scanf("%d %d", &rowintial, &colintial);
           //now call the conferm function to cahck at given location guti is present or not 
            a =  conferm1(board,rowintial,colintial,'O');//call the function to 
           if ((rowintial<0||rowintial>7)||(colintial<0||colintial>7) )
           {
           	printf("INVALID INPUT: OUT OF BOUNDS!\n");
           }else if(a==0){
                if(board[rowintial][colintial]!='Q'){
                  printf("INVALID LOCATION ENTERED: YOU DONT HAVE A PIECE HERE\n");
                }else
           	     i=-1;
           }else i=-1;
        }
          i=1;


        //take input for final loction of guti 
          while (i == 1) {
        printf("Enter Row, Column Where You Want To Move: ");
        scanf("%d %d", &row, &col);

        // Call the confirm function to check if the new location is valid
        a = conferm2(board, row, col);

        int difrow = (rowintial-row );
        int difcol = ( colintial-col);
        int b,c;//use as mode function
        if(difrow<0){
        	b=difrow*(-1);
        }else
          b=difrow;
         if(difcol<0){
         	c=difcol*(-1);
         }else
          c=difcol;

        
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("INVALID INPUT: OUT OF BOUNDS!\n");
        } else if (difrow > 2 || difcol > 2) {
            printf("You cannot move to this location\n");
        } else
        if (b!=c)
           {
              printf("INVALID LOCATION ENTERED: YOU CAN ONLY MOVE DIAGONALLY\n");
        }else 
         if(board[rowintial][colintial]=='Q'){
             int ki= kingfun(board,rowintial,colintial,row,col,difrow,difcol,b,c);
             if(ki==0){
                i=-1;
             }
        
         }else
        if (a == 0) {
            printf("INVALID LOCATION ENTERED: A PIECE IS ALREADY THERE!\n");
        } else
        if (b == 2 && c == 2) {
            if (difrow > 0) {
                switch (difcol) {
                    case 2:
                        if (chackforbak(board, row + 1,col +1, rowintial, colintial) != 1) {
                            printf("Your move is wrong. Enter a valid address.\n");
                        }
                       case -2:
                       	if(chackforbak(board,row+1,col-1,rowintial,colintial) != 1){
                       		printf("your move is wrong>enter valid adderass:\n");
                       	}
                    default:
                        i=-1;
                }
            }
        }else if (b== 1 && c == 1) {
            if (board[row][col] != ' ') {
                printf("You can't move here because there is already a piece.\n");
            }else{
            	i=-1;
            }
        }else
        if (difrow <0){
            printf("you con't move in this location:\n");//cahng karna 
        }else{
           i = -1;
        }
    }

           movepice(board,rowintial,colintial,row,col,board[rowintial][colintial]);

	return;
}//end of input of frist preson

// this functon checks for base condition to stop game
int check(char board[][SIZE], char searchChar, char kingOrQueen)
{
    bool flag = true;
    // search for player piece

    for (int i = 0; i < SIZE; i++) {
        // strchr checks every column of a row without the need of another for loop
        if (strchr(board[i], searchChar) != NULL || strchr(board[i], kingOrQueen) != NULL) {
            // if a piece is found then set to false and break
            flag = false;   
            break;
        }
    }
    
    if (flag == true) {
    	return 0;
    }
    return 1;
} // end of check


// play game in the function
void playGame(char board[][SIZE], int i, int playerOrComputer)
{
    char choice;
    if (check(board, 'X', 'K') == 0) {
        setColor(1);
        printf("Player 2 Wins\n");
   	    return;
    }
    if (check(board, 'O', 'Q') == 0)
    {
        setColor(4);
        printf("Player 1 Wins\n");
        return;
    }

    if (i == 3000)
    {
        int newResume;
        printf("Do You Want To Start A New Game or Resume A Previous One:\n1- New Game\n2- Resume\nInput: ");
        scanf("%d", &newResume);
        pauseOrResume(board, newResume);
    }

    // if i is even then player 1 plays
    if (i % 2 == 0) {
        // Call the function for player 1 input
        playerInput(board, 'X', true);
    }
    // else player 2 plays
    else if (playerOrComputer == 1){
        computer(board, 'O');
    }
    else {
        playerInput(board, 'O', true);
    }

    if (check(board, 'X', 'K') == 0) {
        setColor(1);
        printf("Player 2 Wins\n");
        return;
    }
    if (check(board, 'O', 'Q') == 0)
    {
        setColor(4);
        printf("Player 1 Wins\n");
        return;
    }

    if (i % 2 != 0) {
        // cls and display again so that player 2 updated array is shown to user
        system("cls");
        display(board);
        printf("Do You Want To Pause?(Y/N): ");
        scanf(" %c", &choice);
        if (toupper(choice) == 'Y')
        {
            pauseOrResume(board, 3);
            return;
        }
    }

    playGame(board,i-1,playerOrComputer);

    return;
} // end of playGame

 int main(int argc, char const *argv[])
{

	system("cls");
	display(board);
	int c,r;//c stand for calume and r stand for row
    
    playgame(board,3000);

     
	return 0;
}
