#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 3
#define COLUMNS 3

#define PLAYER1_ID 1
#define PLAYER2_ID 2

int getI(int index){
    return (index - 1) / 3;
}

int getJ(int index){
    return (index -1) % 3;
}


bool markBoard(int index, int gameBoard[][COLUMNS], int player){
    int i = getI(index);
    int j = getJ(index);

    // printf("i = %d\nj = %d\n", i, j);
    int value = gameBoard[i][j];
    if (value != 0) {
        printf("%d\n", value);
        return false;
    } else {
         gameBoard[i][j] = player;
         return true;
    }
}

void drawBoard(int gameBoard[][COLUMNS]) {
    printf("Tic Tac Toe \n");
    printf("Player 1 (X) - Player 2 (0) \n");
    int counter = 1;
    for(int i = 0; i < ROWS; i++){
        for (int k = 0; k < COLUMNS; k++){
            printf("   |");
        }
        printf("\n");
        for (int j = 0; j < COLUMNS; j++){
            if (gameBoard[i][j] !=0)
                printf(" %s |", (gameBoard[i][j] == 1)? "X":"O");
            else
                printf(" %d |", counter);
            counter ++;
        }
        printf("\n");
        for (int m = 0; m < COLUMNS; m++){
           printf("   |");
        }
        printf("\n");
        if (i == (ROWS -1))
        {
            continue;
        }
        for (int l = 0; l < COLUMNS; l++){
            printf("___ ");
        }

        printf("\n");
    }
}

bool checkIfWon(int index, int player, int gameBoard[][COLUMNS]){
    int i = getI(index);
    int j = getJ(index);

    bool won;
    int startIndex = i;

    // Start with the rows
    for(int k = 0; k < 3; k++){
        won = true;
        int value = gameBoard[startIndex][k];
        if (value != player){
            won = false;
            break;
        }
    }

    if(won){
        return true;
    }

    // Then check for columns
    startIndex = j;
    for(int k = 0; k < 3; k++){
        won = true;
        int value = gameBoard[k][startIndex];
        if (value != player){
            won = false;
            break;
        }
    }

    if(won){
        return true;
    }

    // Then check for diagonals
    if (index == 2|| index == 4 || index == 6 || index == 8){
        return false;
    }

    int diagonal1[3] = {1,5,9};
    int diagonal2[3] = {3,5,7};

    size_t n = sizeof(diagonal1)/sizeof(diagonal1[0]);

    for(int k = 0; k < n; k++){
        won = true;
        int value = gameBoard[getI(diagonal1[k])][getJ(diagonal1[k])];
        if (value != player){
            won = false;
            break;
        }
    }

    if(won){
        return true;
    }

    for(int k = 0; k < n; k++){
        won = true;
        int value = gameBoard[getI(diagonal2[k])][getJ(diagonal2[k])];
        if (value != player){
            won = false;
            break;
        }
    }

    return won;

}

int main()
{
    // Assuming player one always begins the game
    int player1_count = 5;
    int player2_count = 4;
    bool won;


    int gameBoard[ROWS][COLUMNS] = {{0}};

    //printf("%d \n",markBoard(8, gameBoard, 1));
    while(true){
        system("clear");
        drawBoard(gameBoard);
        printf("Player 1, pls enter a number: \n");
        int number;
        scanf("%d", &number);

        while(!markBoard(number, gameBoard, PLAYER1_ID)){
                printf("Number is invalid pls try again Player 1 \n");
                scanf("%d", &number);
            }
         system("clear");
         drawBoard(gameBoard);
         player1_count--;

         if (player1_count <= 2){
            won = checkIfWon(number, PLAYER1_ID, gameBoard);
            if(won){
                printf("Player 1 won");
                break;
            }
         }
         if(player1_count == 0){
            break;
         }
         printf("Player 2, pls enter a number \n");
         scanf("%d", &number);


          while(!markBoard(number, gameBoard, PLAYER2_ID)){
                printf("Number is invalid pls try again Player 2\n");
                scanf("%d", &number);
            }
          system("clear");
         drawBoard(gameBoard);
         player2_count--;


         if (player2_count <= 1){
            won = checkIfWon(number, PLAYER2_ID, gameBoard);
            if(won){
                printf("Player 2 won");
                break;
            }
         }


    }
    if(!won){
        printf("It was a draw yo");
    }
    return 0;
}
