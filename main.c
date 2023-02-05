#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Welcomer_Lobby.h"
#include "Setup_New_Game.h"
#include "Game_Elements.h"
#include "Play_Game.h"
#include "File_Func.h"

void defult_keys(char *keys){
     keys[0] = 'Q';
     keys[1] = 'W';
     keys[2] = 'E';
     keys[3] = 'Z';
     keys[4] = 'X';
     keys[5] = 'C';

}




struct cell map_cells[9][13];

int main()
{
    int input, mrjack = 0, round = 0;
    int *exits;
    exits = malloc(4 * sizeof(int));
    struct characters *charr;
    char *keys;
    keys = malloc ( 6 * sizeof(char));
    charr = malloc ( 8 * sizeof(struct characters));
    int *checked_list;
    checked_list = malloc ( 4 * sizeof(int));

    for ( int i = 0 ; i < 4 ; i++){
        checked_list[i] = -1;
    }

    welcome_animation();
    set_characters(charr);
    defult_keys(keys);
    set_first_map_cells(map_cells, &round, &mrjack, exits);


       while(1){
            system("cls");
            printf("%c Main Menu\n", 16);
            printf("1) Start a new game\n2) Load an already existing game\n3) Settings\n4) Exit program\nCommand: ");
            scanf("%d", &input);

            if ( input == 1){
                set_first_map_cells(map_cells, &round, &mrjack, exits);
                char player1[20];
                char player2[20];
                system("cls");
                printf("%c New Game\n", 16);
                printf("Enter Player 1 name: ");
                getchar();
                gets(player1);
                printf("Enter Player 2 name: ");
                gets(player2);
                set_players(player1, player2, charr, &mrjack);
                system("cls");
                round = 1;
                round_manage(round , map_cells, mrjack, charr, exits, keys, checked_list);
            }
            else if (input == 2){
                system("cls");
                load_map_cells(map_cells, &round, &mrjack, exits, charr);
                system("cls");
                print_map(map_cells, exits, charr);
                do_visibility(charr, map_cells, mrjack, 7, keys, 0);
                round_manage(round + 1 , map_cells, mrjack, charr, exits, keys, checked_list);

            }

            else {
                interactions(input, keys);
            }

        }

    return 0;
}



