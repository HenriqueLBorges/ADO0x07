#include <stdio.h>
#include <stdlib.h>
//gcc -W -Wall -pedantic -std=c11 -O3 Jogo.c -o jogo
int matrix [3] [3]; 

int main(){
    int option = 0;
    int i = 0;
    int j = 0;
    int line = 0;
    int column = 0;
    int active [3];
    active [0] = 1;
    active [1] = 1;

    for ( i=0; i<3; i++ ){
        for ( j=0; j<3; j++ ){
            matrix[i][j] = 0;
        }
    }
    printf("Game\n");
    printf("\n1 - Start\n");
    scanf ("%d", &option);
    printf("--------------\n");
    if(option == 1){
        while(active[0]){
            render();
            printf("\n--------------\n");
            active[1] = 1;
            while(active[1]){
                printf("\nPlayer 1\n");
                printf("Choose a line.\n");
                scanf ("%d", &line);
                printf("Choose a column.\n");
                scanf ("%d", &column);
                if(matrix [line][column] != 0) printf("Position is already taken!");
                else{
                    active[1] = 0;
                    matrix[line][column] = 1;
                    render();
                } 
            }
            printf("\n--------------\n");
            active[2] = 1;
            while(active[2]){
                printf("\nPlayer 2\n");
                printf("Choose a line.\n");
                scanf ("%d", &line);
                printf("Choose a column.\n");
                scanf ("%d", &column);
                if(matrix [line][column] != 0) printf("Position is already taken!");
                else{
                    active[2] = 0;
                    matrix[line][column] = 2;
                } 
            }
            int finish = verifyWinner();
            if(finish == 1){
                printf("Player 1 won!");
                active[0] = 0;
                return;
            }
            else if(finish == 2){
                printf("Player 2 won!");
                active[0] = 0;
                return;
            }
        }
    }
}
void render(){
    int i = 0;
    int j = 0;
    //render header
    printf(" |0|1|2\n");
    printf("-------\n");

    for ( i=0; i<3; i++ ){
        printf("%d", i);
        for ( j=0; j<3; j++ ){
            printf("|%d", matrix[i] [j]);
            if(j == 3) printf("\n");
        }
        printf("\n- - - -\n");
    }
}

int verifyWinner(){
    //Player 1 wins return 1 || Player 2 wins return 2

    //Player 1
    //matrix line = 0
    if(matrix[0][0] == 1 && matrix[0][1] == 1 && matrix[0][2] == 1) return 1;
    //matrix line = 1
    else if(matrix[1][0] == 1 && matrix[1][1] == 1 && matrix[1][2] == 1) return 1;
    //matrix line = 2
    else if(matrix[2][0] == 1 && matrix[2][1] == 1 && matrix[2][2] == 1) return 1;

    //matrix column = 0
    else if(matrix[0][0] == 1 && matrix[1][0] == 1 && matrix[2][0] == 1) return 1;
    //matrix column = 1
    else if(matrix[0][1] == 1 && matrix[1][1] == 1 && matrix[2][1] == 1) return 1;
    //matrix column = 2
    else if(matrix[0][2] == 1 && matrix[1][2] == 1 && matrix[2][2] == 1) return 1;

    //Verify diagonals
    else if(matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1) return 1;
    if(matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1) return 1;

    //Player 2

    //matrix line = 0
    else if(matrix[0][0] == 2 && matrix[0][1] == 2 && matrix[0][2] == 2) return 2;
    //matrix line = 1
    else if(matrix[1][0] == 2 && matrix[1][1] == 2 && matrix[1][2] == 2) return 2;
    //matrix line = 2
    else if(matrix[2][0] == 2 && matrix[2][1] == 2 && matrix[2][2] == 2) return 2;

    //matrix column = 0
    else if(matrix[0][0] == 2 && matrix[1][0] == 2 && matrix[2][0] == 2) return 2;
    //matrix column = 1
    else if(matrix[0][1] == 2 && matrix[1][1] == 2 && matrix[2][1] == 2) return 2;
    //matrix column = 2
    else if(matrix[0][2] == 2 && matrix[1][2] == 2 && matrix[2][2] == 2) return 2;

    //Verify diagonals
    else if(matrix[0][0] == 2 && matrix[1][1] == 2 && matrix[2][2] == 2) return 2;
    else if(matrix[0][2] == 2 && matrix[1][1] == 2 && matrix[2][0] == 2) return 2;

    return 0;
}