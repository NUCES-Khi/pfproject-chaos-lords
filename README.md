[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/j0WbCUcA)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=13059236&assignment_repo_type=AssignmentRepo)
# PROJECT CHECKERS

# Group
| Members        | ID       |
| ---------------|:--------:|
| Muhammed Owais (Group Leader) | 23K-0047 |
| Talha Rusman | 23K-0065 |
| Muhammad John Raza | 23K-0069 |

## Project Proposal

### Project Description

1. A checker board consisting of an 8x8 grid.
2. Each player has 12 pieces, totaling 24 pieces.
3. Every turn, a piece can move only one space diagonally.
4. Capturing is allowed if there is a free space adjacent to an opponent's piece.

### Checkers Board Layout

The checkers are initially set up on the dark-colored squares, with each player having their pieces on the three rows closest to them.

![Checkers Board Layout](https://github.com/NUCES-Khi/pfproject-chaos-lords/assets/83649329/c4120b08-6be8-41e3-b0b0-35b7b81a99c7)


### Man: A piece on the board

A piece that can only move forward. It cannot move backward. Here's a visual representation of how a man is moved:

![Man - Piece Movement](https://github.com/NUCES-Khi/pfproject-chaos-lords/assets/83649329/11b7c1b4-7021-42a2-b25f-4394cfdf6a85)


### King: A piece on the board

When a man reaches the other home rank of the checkerboard, it becomes a king. This allows the piece to move both forward and backward. Here's a visual representation of how a king moves in a checkerboard:

![King - Piece Movement](https://github.com/NUCES-Khi/pfproject-chaos-lords/assets/83649329/d20a2176-e7ff-457a-9dd5-46e61e83d6c0)


### Game Ending Conditions

A player wins if all their pieces are captured by the opponent.

## Project Objectives

1. Two players can play against each other.
2. If one player is present, the player plays against the computer.
3. All the rules of checkers are printed before the game starts.


## Data Structures

1. **Character Array:**
   - Used to store the "O" and "X" of the checkers board, declared as an 8x8 2D array.

2. **Functions:**
   - Utilizes void and integer-returning functions that perform various tasks on a checkers board. Functions are designed for checking player moves, moving pieces, handling king pieces, displaying the checkers board, and creating the AI that plays against the player.

3. **Boolean Data Type:**
   - Controls the printing for errors when the computer is playing. Also used to check if the game has been won by a player or not.

4. **Conditional Statements:**
   - Used to validate different moves made on the board by the player and the AI, preventing incorrect moves. Also employed in the main function and the playGame function to determine whether it's player 1 vs player 2 or player vs computer. Switch statements are used to determine if the player wants to move left or right on the board.

5. **Recursions:**
   - The playGame function uses recursion to keep the checkers game running until a winning condition occurs. Recursion is also employed in the playerInput function to allow the player to choose a different piece if the current piece cannot be moved.

6. **Loops:**
   - While loop used in the playerInput function to take input until correct input is entered. A for loop is used to display the contents of the array as a checkers board. A for loop is also used for filing, either to fill the array with contents or fill the file with contents of the array.

7. **Filing:**
   - A filing function has been created to allow a user to start a new game or pause the current game by filing the file with the contents of the array. Resuming allows the user to resume a previously saved game by filing the current array with the contents of the file. If a user resumes and no previous file is available, it starts a new game.

8. **Libraries:**
   - `stdio.h`: Used for basic functions in C.
   - `string.h`: Used for `strchr` function.
   - `stdbool.h`: Used for the boolean data type.
   - `ctype.h`: Used for `isupper` function.
   - `Windows.h`: Used for coloring.
   - `stdlib.h`: Used for `system("cls")`.

    
  
