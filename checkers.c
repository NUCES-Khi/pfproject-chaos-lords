#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 8


// Initializing board
char board[SIZE][SIZE] =  {{'X', ' ', 'X', ' ','X', ' ', 'X', ' '},
                          {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
                          {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
                          {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
                          {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'}};

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

 int main(int argc, char const *argv[])
{

	system("cls");
	display(board);
	int c,r;//c stand for calume and r stand for row
    
    playgame(board,3000);

     
	return 0;
}
