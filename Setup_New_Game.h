#ifndef SETUP_NEW_GAME_H_INCLUDED
#define SETUP_NEW_GAME_H_INCLUDED
#include "Game_Elements.h"
#include "File_Func.h"
#include <time.h>
#include <stdlib.h>


void print_card( struct characters s){

    int i, j, k, z, length, spaces;

    for ( i = 0 ; i < 16 ; i++){
        printf("\n");
        printf("      ");
        if ( i == 0){
            for ( j = 0 ; j < 24 ; j++){
                printf("_");
            }
        }
        else if ( i == 15){
            printf("|");
            for ( j = 0 ; j < 22 ; j++){
                printf("_");
            }
            printf("|");

        }
        else if ( i != 3 && i != 5 && i != 8 && i != 10 && i != 12 && i != 14){
            printf("|");
            for ( z = 0 ; z < 22 ; z++){
                printf(" ");
            }
            printf("|");
        }
        else if ( i == 3){
            printf("|");
            length = strlen(s.name);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", s.name);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");
        }
        else if ( i == 5 ){
            printf("|");
            printf("         (%s)         ", s.inicialize);
            printf("|");

        }
        else if ( i == 8){
            printf("|");
            printf("   Movement: %d -> %d   ", s.movement_range[0], s.movement_range[1]);
            printf("|");
        }
        else if ( i == 10){
            printf("|");
            printf("          **          ");
            printf("|");
        }
        else if ( i == 12){
            printf("|");
            length = strlen(s.ability);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", s.ability);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");
        }
        else if ( i == 14){
            printf("|");
            length = strlen(s.time);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", s.time);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");

        }

    }
    printf("\n");

}

void delay1sec(){
    int millisec = 1000;
    clock_t start_time = clock();
    while ( clock() < start_time + millisec);
}

void set_players(char *player1, char *player2, struct characters *charr, int *ind){

    srand(time(NULL));
    int i;
    int r = rand();
    r = r % 2;

    system("cls");
    printf("%c Randomized players roles:\n\n", 16);

    if ( r == 1){
        printf("Mr.Jack = %s\nDetective = %s\n", player1, player2);
    }
    else if (r == 0){
        printf("Mr.Jack = %s\nDetective = %s\n", player2, player1);
    }
    printf("\n");
    for ( i = 4 ; i >= 0 ; i--){
        printf(" \rWill show Mr.Jacks card in %ds", i);
        delay1sec();
    }
    system("cls");
    printf("%c Mr.Jacks character: \n", 16);
    set_mrjack_character(charr, ind);

}



void set_mrjack_character(struct characters* character_list, int *index){
    srand(time(NULL));
    int r = rand(), i;
    r = r % 8;
    *index = r;
    print_card(character_list[r]);
    printf("\n");
    for ( i = 5 ; i >= 0 ; i--){
        printf("\rWill start the game in %ds", i);
        delay1sec();
    }
}

void set_characters(struct characters *charr){


    strcpy(charr[0].name , "Sherlock Holmes");
    charr[0].movement_range[0] = 1;
    charr[0].movement_range[1] = 3;
    strcpy(charr[0].inicialize, "SH");
    strcpy(charr[0].ability, "See one card");
    strcpy(charr[0].time, "After");
    charr[0].visi = 1;

    strcpy(charr[1].name, "John H. Watson");
    charr[1].movement_range[0] = 1;
    charr[1].movement_range[1] = 3;
    strcpy(charr[1].inicialize, "JW");
    strcpy(charr[1].ability, "Light up a line");
    strcpy(charr[1].time, "After");
    charr[1].visi = 1;

    strcpy(charr[2].name, "John Smith");
    charr[2].movement_range[0] = 1;
    charr[2].movement_range[1] = 3;
    strcpy(charr[2].inicialize, "JS");
    strcpy(charr[2].ability, "Swap lamps place");
    strcpy(charr[2].time, "Either");
    charr[2].visi = 1;

    strcpy(charr[3].name, "Inspector Lestrade");
    charr[3].movement_range[0] = 1;
    charr[3].movement_range[1] = 3;
    strcpy(charr[3].inicialize, "IL");
    strcpy(charr[3].ability, "Swap exit blocks");
    strcpy(charr[3].time, "Either");
    charr[3].visi = 1;

    strcpy(charr[4].name, "Miss Stealthy");
    charr[4].movement_range[0] = 1;
    charr[4].movement_range[1] = 4;
    strcpy(charr[4].inicialize, "MS");
    strcpy(charr[4].ability, "Cross any hex");
    strcpy(charr[4].time, "While");
    charr[4].visi = 1;

    strcpy(charr[5].name, "Sergeant Goodley");
    strcpy(charr[5].ability, "Call 3 others to him");
    charr[5].movement_range[0] = 1;
    charr[5].movement_range[1] = 3;
    strcpy(charr[5].inicialize, "SG");
    strcpy(charr[5].time, "Either");
    charr[5].visi = 1;

    strcpy(charr[6].name, "Sir William Gull");
    strcpy(charr[6].ability, "Swap place with others");
    charr[6].movement_range[0] = 1;
    charr[6].movement_range[1] = 3;
    strcpy(charr[6].inicialize, "WG");
    strcpy(charr[6].time, "Or");
    charr[6].visi = 1;

    strcpy(charr[7].name, "Jeremy Bert");
    charr[7].movement_range[0] = 1;
    charr[7].movement_range[1] = 3;
    strcpy(charr[7].inicialize, "JB");
    strcpy(charr[7].ability, "Swap hole blocks");
    strcpy(charr[7].time, "Either");
    charr[7].visi = 1;




}

void exits_default(char exits[4][3]){
    strcpy(exits[0], "[]");
    strcpy(exits[1], "[\]");
    strcpy(exits[2], "[]");
    strcpy(exits[3], "[\]");
}







#endif // SETUP_NEW_GAME_H_INCLUDED
