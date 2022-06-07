/*
Author: Billy Gene Ridgeway
Purpose: Create a Tic Tak Toe game for course challenge.
Date: 2 June 2022

1.  checkForWin function    to check if there was a winner or draw.
2.  drawBoard function      which will redraw the board after each player's turn and checking for winner/draw.
3.  markBoard function      sets the char array with the player's selection and checks if it's valid, 1 through 9.

*/

#include <stdio.h>
#include <stdlib.h>

char checkForWin(void);
char checkForDraw(void);
void drawBoard(void);
int markBoard(void);
int selectNumber(void);
char currentPlayerSwitch(char);

int main()
{
    char winner = ' ';  // Declare a variable to check for a winner.
    char noWinner = ' '; // Declare a variable to check for a draw.

    char boardElements[3][3] = {            // Function to fill the game board with numbers 1 through 9.
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
    };

    char currentPlayerSwitch(char z)        // Function to switch players between X and O.
    {
        char x = z;
        //printf("The current player is %c.\n", x);

        if(x == 'X')x = 'O';
        else x = 'X';

        //printf("The current player is %c.\n", x);

        return x;
    }

    int selectNumber(void)
    {
        int sSelect;
        int numberRead = 0;
        printf("Enter the number of the space you would like to place your marker on the board.\n");
        numberRead = scanf("%d", &sSelect);
        while (numberRead != 1){
            printf("That is not a number.\n");
            scanf("%*[^\n]");
            printf("Enter a number between 1 and 9.\n");
            numberRead = scanf("%d", &sSelect);
        }

        return sSelect;
    }

    void drawBoard(void){
        system("clear");


        printf("\n");
        printf("        Tic Tac Toe\n");
        printf("\n");
        printf("Player 1 (X) - Player 2 (O)\n");
        printf("\n");

        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", boardElements[0][0],boardElements[0][1],boardElements[0][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", boardElements[1][0],boardElements[1][1],boardElements[1][2]);
        printf("_____|_____|_____\n");
        printf("     |     |     \n");
        printf("  %c  |  %c  |  %c \n", boardElements[2][0],boardElements[2][1],boardElements[2][2]);
        printf("     |     |     \n");
        printf("\n");

    }

    char checkForWin(void)
    {
        // Check rows.
        for(int i = 0; i < 3; i++)
        {
            if(boardElements[i][0] == boardElements[i][1] && boardElements[i][0] == boardElements[i][2])
            {
                return boardElements[i][0];
            }
        }
        // Check columns.
        for(int i = 0; i < 3; i++)
        {
            if(boardElements[0][i] == boardElements[1][i] && boardElements[0][i] == boardElements[2][i])
            {
                return boardElements[0][i];
            }
        }
        // Check diagonals.

        if(boardElements[0][0] == boardElements[1][1] && boardElements[0][0] == boardElements[2][2])
            {
                return boardElements[0][0];
            }

        if(boardElements[0][2] == boardElements[1][1] && boardElements[0][2] == boardElements[2][0])
            {
                return boardElements[0][2];
            }
        return ' ';
    }

 char checkForDraw(void)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {

                if(boardElements[i][j] == '1' || boardElements[i][j] == '2' || boardElements[i][j] == '3'
                || boardElements[i][j] == '4' || boardElements[i][j] == '5' || boardElements[i][j] == '6'
                || boardElements[i][j] == '7' || boardElements[i][j] == '8' || boardElements[i][j] == '9'){return 0;}

            }
        }

        return 'Z';
    }


    int markBoard(void)
    {
        char currentPlayer = 'X';
        int spaceSelect;
        int moves = 0;


        while(moves <= 9)
        {
            winner = checkForWin();
            if(winner == 'X' || winner == 'O')
            {
                if(winner == 'X'){printf("The winner of the game is player 1!\n");
                break;}else{printf("The winner of the game is player 2!\n"); break;}
            }
            noWinner = checkForDraw();
            if(noWinner == 'Z'){
                printf("The game is a draw.\n");
                break;
            }

            printf("The current player is %c.\n", currentPlayer);
            printf("\n");
            spaceSelect = selectNumber();
            printf("spaceSelect = %d.\n", spaceSelect);


            switch(spaceSelect)
            {
                case 1:

                    if(boardElements[0][0] == '1'){boardElements[0][0] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 1.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 2:
                    if(boardElements[0][1] == '2'){boardElements[0][1] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 2.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 3:
                    if(boardElements[0][2] == '3'){boardElements[0][2] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 3.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 4:
                    if(boardElements[1][0] == '4'){boardElements[1][0] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 4.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 5:
                    if(boardElements[1][1] == '5'){boardElements[1][1] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 5.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 6:
                    if(boardElements[1][2] == '6'){boardElements[1][2] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 6.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 7:
                    if(boardElements[2][0] == '7'){boardElements[2][0] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 7.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 8:
                    if(boardElements[2][1] == '8'){boardElements[2][1] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 8.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;
                case 9:
                    if(boardElements[2][2] == '9'){boardElements[2][2] = currentPlayer; moves++;
                    currentPlayer = currentPlayerSwitch(currentPlayer); printf("You selected space 9.\n"); drawBoard(); break;}
                    else{printf("This space has already been taken. Please choose another.");moves++;}
                    break;

                default: printf("Your number is invalid. You entered %d. Please enter a valid number from 1 to 9.\n", spaceSelect);
                break;
            }
        }

    }

   drawBoard();
   markBoard();


    return 0;
}
