#ifndef FILE_FUNC_H_INCLUDED
#define FILE_FUNC_H_INCLUDED
#include "Setup_New_Game.h"


int load_map_cells(struct cell map_cells[9][13], int *round, int *mrjack, int exits[4], struct characters charr[8]){
    FILE *fp;
    int n, cnt = 0;
    char c, s[2];
    int i = 0 , j = 0, k;
    char add[200] = "Saved games\\";
    char inp[50];
    //system("cls");
    while (1){


        printf("%c Load a game\n", 16);
        printf("Enter the name you had your game saved as: ");

        scanf("%s", inp);
        strcat(add, inp);
        strcat(add, ".txt");

        fp = fopen(add, "r");
        if ( fp != NULL){
            break;
        }
        if ( fp == NULL){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("(!) No such file was found, try again.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            return 0;
        }

    }

    fscanf(fp, "%d%d", &n, &k);
    *mrjack = n;
    *round = k;
    for ( i = 0 ; i < 4 ; i++){
        fscanf(fp, "%d", &exits[i]);

    }

    for ( int q = 0 ; q < 117 ; q++){
        fscanf(fp, "%d %d %s", &i, &j, s);
        strcpy(map_cells[j][i].in, s);
        if ( s[0] == 'X' || s[0] == 'O'){
            strcpy(map_cells[i][j].bg, "N");
        }
    }
    char s2[2];

    while (1){
        if ( c = getc(fp) == EOF){
            break;
        }
        fscanf(fp, "%s %s", s, s2);
        for ( i = 0 ; i < 9 ; i++){
            for ( j = 0 ; j < 13 ; j++){
                if ( strcmp(map_cells[i][j].in, s) == 0){
                    strcpy(map_cells[i][j].bg, s2);
                }
            }
        }
    }





    fclose(fp);

    return 1;
}

void set_first_map_cells(struct cell mapp[9][13], int *round, int *mrjack, int exits[4]){
    FILE *fp;
    int n, cnt = 0;
    char c, s[2];
    int i = 0 , j = 0, k;


    fp = fopen("Other files\\First_Locations.txt", "r");
    fscanf(fp, "%d%d", &n, &k);
    *mrjack = n;
    *round = k;

    fscanf(fp, "%d %d %d %d", &exits[0], &exits[1], &exits[2], &exits[3]);






    while (1){
        if ( c = getc(fp) == EOF){
            break;
        }

        fscanf(fp, "%d %d %s", &j, &i, s);

        strcpy(mapp[i][j].in, s);
        if ( s[0] == 'X' || s[0] == 'O'){
            strcpy(mapp[i][j].bg, "N");
        }

    }
    fclose(fp);
}

void save_file(struct cell mapp[9][13], int r, int jack, int exits[4], struct characters charr[8]){
    FILE *fp;
    char add[200] = "Saved games\\";
    char inp[50];
    int i, j;

    printf("%c Save Game\n", 16);
    printf("Enter the name you want your game to be saved as: ");
    scanf("%s", inp);
    strcat(add, inp);
    strcat(add, ".txt");
    fp = fopen(add, "w");

    fprintf(fp, "%d\n%d\n", jack, r);
    fprintf(fp, "%d %d %d %d", exits[0], exits[1], exits[2], exits[3]);

    for ( i = 0 ; i < 13 ; i++){
        for ( j = 0 ; j < 9 ; j++){
            fprintf(fp, "\n");
            fprintf(fp, "%d %d %s", i, j, mapp[j][i].in);
        }
    }
    for ( i = 0 ; i < 13 ; i++){
        for ( j = 0 ; j < 9 ; j++){
            if ( mapp[i][j].bg[0] == 'X' || mapp[i][j].bg[0] == 'O'){
                fprintf(fp, "\n%s %s", mapp[i][j].in, mapp[i][j].bg);
            }
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\n(%c) Your game was successfully saved in: \n    (%s)\n",251, add);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    for ( int y = 0 ; y < 3 ; y++){
        delay1sec();
    }

    fclose(fp);
}
#endif // FILE_FUNC_H_INCLUDED
