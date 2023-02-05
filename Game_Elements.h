#ifndef GAME_ELEMENTS_H_INCLUDED
#define GAME_ELEMENTS_H_INCLUDED
#include <string.h>
#include <windows.h>


struct characters{
    int visi;
    int vistmp;
    char name[20];
    char ability[25];
    int movement_range[2];
    char time[8];
    char inicialize[2];
};

struct cell{
    int type;
    char in[3];
    char bg[3];

};

struct node{
    struct node *next;
    struct characters data;
};

void print_color (char *text, int c){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    printf("%s", text);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}





#endif // GAME_ELEMENTS_H_INCLUDED
