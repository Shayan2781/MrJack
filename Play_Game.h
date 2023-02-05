#ifndef PLAY_GAME_H_INCLUDED
#define PLAY_GAME_H_INCLUDED
#include "Game_Elements.h"
#include "File_Func.h"
#include <string.h>


int* randomize_num(){

    int *arr, c = 0, i, j, r;
    arr = malloc ( 4 * sizeof(int));



    srand(time(NULL));

    while (1){
        r = rand() % 8;


       if ( checkarr(arr, c, r)){
            arr[c] = r;
            c++;
        }
        if ( c == 5){
            break;
        }
    }
    return arr;
}

int check_arr_int(int *arr, int n){

    for ( int i = 0 ; i < 4 ; i++){
        if ( arr[i] == n){
            return 0;
        }
    }
    return 1;
}

void print_map(struct cell mapp[9][13], int *exits, struct characters charr[8]){
    FILE *fp;
    char ch;
    int iv = 0, jv = 0, i, j, l, m;

    fp = fopen("Other files\\Grid1.txt", "r");
    printf("      ");
    print_exit(exits[0]);
    printf("\t\t\t\t\t\t\t\t\t\t    ");
    print_exit(exits[1]);
    printf("\n");
    while( ( ch = fgetc(fp) ) != EOF ){
        if ( ch == '*'){
            fscanf(fp, "%d", &m);
            i = m % 10;
            j = m / 10;


              l = strlen(mapp[i][j].in);
                    if ( strcmp(mapp[i][j].in, "N") == 0 && (mapp[i][j].bg[0] == 'X' || mapp[i][j].bg[0] == 'O')){
                        strcpy(mapp[i][j].in, mapp[i][j].bg);
                        strcpy(mapp[i][j].bg, "N");
                    }


                    if ( strcmp(mapp[i][j].in, "N") == 0){
                        mapp[i][j].type = 0;
                        if ( j > 9){
                            printf("    ");
                        }
                        else {
                            printf("   ");
                        }

                    }
                    else if (strcmp(mapp[i][j].in, "H") == 0){
                        mapp[i][j].type = 1;
                        if ( j > 9){
                            printf("%c%c%c ", 254, 254, 254);

                        }
                        else{
                            printf("%c%c%c", 254, 254, 254);
                        }

                    }

                    else if (mapp[i][j].in[0] == 'O'){
                        mapp[i][j].type = 9;
                        if ( j > 9){
                            printf(" %c%c ", 234, mapp[i][j].in[1]);
                        }
                        else {
                            printf(" %c%c", 234, mapp[i][j].in[1]);
                        }

                    }
                    else if ( mapp[i][j].in[0] == 'X'){
                        mapp[i][j].type = 9;
                        if ( j > 9){
                            printf(" %c%c ", 237, mapp[i][j].in[1]);
                        }
                        else {
                            printf(" %c%c", 237, mapp[i][j].in[1]);
                        }

                    }
                    else if ( mapp[i][j].in[0] == 'L' && mapp[i][j].in[1] != 'O'){
                        mapp[i][j].type = 3;
                        if ( j > 9){
                            mapp[i][j].type = 3;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                            printf(" %c", 221);
                            printf("%c ", mapp[i][j].in[1]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                        }
                        else{
                            mapp[i][j].type = 3;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                            printf(" %c", 221);
                            printf("%c", mapp[i][j].in[1]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                        }
                    }
                    else if ( mapp[i][j].in[0] == 'L' && mapp[i][j].in[1] == 'O'&& mapp[i][j].in[1] != '0'){
                        mapp[i][j].type = 1;
                        if ( j > 9){

                            printf(" %c%c ", 221, mapp[i][j].in[2]);
                        }
                        else{
                            printf(" %c%c", 221, mapp[i][j].in[2]);
                        }
                    }
                    else if ( l > 1){
                        mapp[i][j].type = 4;
                    if ( j > 9 ){
                        for ( int q = 0 ; q < 8 ; q++){
                            if ( strcmp(mapp[i][j].in, charr[q].inicialize) == 0){
                                if (charr[q].visi == 0){
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                                    printf("%.2s  ", mapp[i][j].in);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                                }
                                else {
                                    printf("%.2s  ", mapp[i][j].in);
                                }
                            }
                        }
                    }
                    else {
                         for ( int q = 0 ; q < 8 ; q++){
                            if ( strcmp(mapp[i][j].in, charr[q].inicialize) == 0){
                                if (charr[q].visi == 0){
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                                    printf("%.2s ", mapp[i][j].in);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                                }
                                else {
                                    printf("%.2s ", mapp[i][j].in);
                                }
                            }
                        }
                    }

                }

                }
                else {
                    printf("%c", ch);

                }
        }
        printf("\n");
        printf("\n     ");
        print_exit(exits[3]);
        printf("\t\t\t\t\t\t\t\t\t\t     ");
        print_exit(exits[2]);
        printf("\n");
    fclose(fp);
    return;
}


void create_card_linked_list (struct characters arr[8], int x, struct node *head){

    int n, mod;
    n = x;

    while (n > 0){
        mod = n % 10;
        add_node(head, arr[mod]);
        n /= 10;
    }
}

void print_to_num (int cnt, struct node *head){

    int i, j, k, z, y, m, length, spaces;
    struct node *ptr;
    ptr = head->next;
    for ( i = 0 ; i < 16 ; i++){
        printf("\n");
        printf("      ");
        if ( i == 0){
            for ( z = 0 ; z < cnt ; z++){
                for ( j = 0 ; j < 24 ; j++){
                printf("_");
            }
            printf("  ");

            }

        }
        else if ( i == 15){
            for ( z = 0 ; z < cnt ; z++){
                printf("|");
                for ( j = 0 ; j < 22 ; j++){
                    printf("_");
                }
                printf("|");
                printf("  ");
            }


        }
        else if ( i != 3 && i != 5 && i != 8 && i != 10 && i != 12 && i != 14){
            for ( y = 0 ; y < cnt ; y++){
            printf("|");
            for ( z = 0 ; z < 22 ; z++){
                printf(" ");
            }
            printf("|");
            printf("  ");
           }
        }
        else if ( i == 3){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            length = strlen(ptr->data.name);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", ptr->data.name);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");
            printf("  ");
            ptr = ptr->next;
        }
        ptr = head->next;

        }
        else if ( i == 5 ){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            printf("         (%s)         ", ptr->data.inicialize);
            printf("|");
            printf("  ");
            ptr = ptr->next;
            }
            ptr = head->next;
        }
        else if ( i == 8){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            printf("   Movement: %d -> %d   ", ptr->data.movement_range[0], ptr->data.movement_range[1]);
            printf("|");
            printf("  ");
            ptr = ptr->next;
            }
            ptr = head ->next;
        }
        else if ( i == 10){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            printf("          **          ");
            printf("|");
            printf("  ");
            }
        }
        else if ( i == 12){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            length = strlen(ptr->data.ability);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", ptr->data.ability);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");
            printf("  ");
            ptr = ptr->next;
        }
        ptr = head ->next;
        }
        else if ( i == 14){
            for ( m = 0 ; m < cnt ; m++){
            printf("|");
            length = strlen(ptr->data.time);
            spaces = (22 - length) / 2;
            for ( k = 0 ; k < spaces ; k++){
                printf(" ");
            }
            printf("%s", ptr->data.time);
            for ( k = 0 ; k < 22 - length - spaces ; k++){
                printf(" ");
            }

            printf("|");
            printf("  ");
            ptr = ptr->next;
        }
        ptr = head->next;

        }

    }
    printf("\n\n\n\n");



}

void print_remaining_cards (struct node *head){

    int cnt = 0;
    struct node *ptr;


    ptr = head;
    while ( ptr->next != NULL){
        ptr = ptr ->next;
        cnt++;
    }
    print_to_num(cnt, head);

}
void freeList(struct node* head)
{
   struct node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}


int round1(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 1");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 1\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 1\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 1\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 1\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        printf("\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 1 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 2\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 1){
            return 1;
        }
        else if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }

}

int round2(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 2");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 2\n\n", 16);
        turnoff_light("L1", mapp, "LO3");
        printf("%c ", 249);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        printf("Light 1");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" was turned off\n\n");
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 2\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 2\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 2\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 2 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 3\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }
        return 1;

}

int round3(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 3");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 3\n\n", 16);
        turnoff_light("L2", mapp, "LO4");
        printf("%c ", 249);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        printf("Light 2");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" was turned off\n\n");
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 3\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 3\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 3\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 3 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 4\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }
        return 1;

}
int round4(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 4");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 4\n\n", 16);
        turnoff_light("L3", mapp, "LO5");
        printf("%c ", 249);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        printf("Light 3");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" was turned off\n\n");
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 4\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 4\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 4\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 4 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 5\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }

        return 1;
}

int round5(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 5");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 5\n\n", 16);
        turnoff_light("L4", mapp, "LO6");
        printf("%c ", 249);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        printf("Light 4");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf(" was turned off\n\n");
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 5\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 5\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 5\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        printf("\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 5 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 6\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }

        return 1;

}

int round6(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 6");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 6\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 6\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 6\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 6\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        printf("\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 6 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 7\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }
        return 1;

}

int round7(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 7");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 7\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 7\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 7\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 7\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);

        print_map(mapp, exits1, charr);
        printf("\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 7 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        printf("1) Continue to Round 8\n2) Save and exit\n3) Exit without saving\nCommand: ");
        scanf("%d", &inp);
        if ( inp == 2){
            system("cls");
            save_file(mapp, r, mrjack, exits1, charr);
            return 0;
        }
        else if ( inp == 3){
            return 0;
        }
        return 1;
}

int round8(struct node *head, struct cell mapp[9][13], int exits1[4], int mrjack, int rand, struct characters charr[8], char key[8], int r, int *checked_list){
    char chosen[2];
    int inp, t = 0;
    int light_line;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             ");
    animation_print("    Round 8");
    for ( int i = 0 ; i < 3 ; i++){
        delay1sec();
    }

        system("cls");
        printf("%c Round 8\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }


        system("cls");
        printf("%c Round 8\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack,&head,  &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }

        system("cls");
        printf("%c Round 8\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Mr.Jack - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 0, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;

            }

        }


        system("cls");
        printf("%c Round 8\n\n\n", 16);
        printf("%c Available cards", 249);
        print_remaining_cards(head);
        printf("\n");
        printf("%c Game map\n\n\n", 249);
        print_map(mapp, exits1, charr);
        printf("\n");
        while (1){
            printf("\n%c Detective - Choose one of the shuffled cards: ", 249);
            scanf("%s", chosen);
            if (delete_node(&head, chosen)){
                move_char(chosen, mapp, charr, key, exits1, mrjack, &head, &light_line, 1, checked_list);
                if ( strcmp(chosen, "JW") == 0){
                t = 1;
                }
                break;
            }
        }
        system("cls");
        do_visibility(charr, mapp, mrjack, light_line, key, 1);
        print_map(mapp, exits1, charr);
        printf("\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        printf("\n(%c) Round 8 was completed\n\n",251);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        printf("\n\n\n----> Detective didnt catch Mr.Jack, \"Mr.Jack\" is the winner! <----\n\n\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        for ( int z = 0 ; z < 4 ; z++){
            delay1sec();
        }
        return 0;

}



void round_manage(int r, struct cell map_cells[9][13], int jack, struct characters arr[8], int exits[4], char keys[8], int *checked_list){

    int inp;
    int *n;
    n = malloc ( 4 * sizeof(int));
    n = randomize_num();



    if ( r == 1){
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, arr_to_num(n), head);
        if(round1(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    if ( r == 2){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, revert(n), head);
        if(round2(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;

        }
        freeList(head);
        r++;
    }
    free(n);
    n = malloc ( 4 * sizeof(int));
    n = randomize_num();
    if ( r == 3){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, arr_to_num(n), head);
        if(round3(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    if ( r == 4){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, revert(n), head);
        if (round4(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    free(n);
    n = malloc ( 4 * sizeof(int));
    n = randomize_num();
    if ( r == 5){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, arr_to_num(n), head);
        if (round5(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    if ( r == 6){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, revert(n), head);
        if (round6(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    free(n);
    n = malloc ( 4 * sizeof(int));
    n = randomize_num();
    if ( r == 7){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, arr_to_num(n), head);
        if (round7(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    if ( r == 8){
        system("cls");
        struct node *head;
        head = malloc(sizeof(struct node *));
        head ->next = NULL;
        create_card_linked_list(arr, revert(n), head);
        if (round8(head, map_cells,exits, jack, 1234, arr, keys, r, checked_list) == 0){
            freeList(head);
            r++;
            return;
        }
        freeList(head);
        r++;
    }
    free(n);
}


void add_node(struct node *head, struct characters ch){
    struct node *tmp, *ptr;
    tmp =  malloc(sizeof(struct node));
    ptr = head;
    tmp->data = ch;
    tmp->next = NULL;

    while ( ptr->next != NULL){
        ptr = ptr ->next;
    }
    ptr-> next = tmp;

}

int delete_node ( struct node **head, char *in){
    struct node *current, *previous;
    current = *head;
    previous = *head;
    while (1){
        if ( strcmp(current ->data.inicialize, in) == 0){
            previous ->next = current ->next;
            free(current);
            current = NULL;
            return 1;
        }

        if (current ->next == NULL){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("\n(!) Character \"%s\" doesnt exist in the deck.\n", in);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            return 0;
        }
        previous = current;
        current = current ->next;
    }
}

void print_exit(int n){
    if ( n == 0){
        printf("[\\]");
    }
    else if ( n == 1){
        printf("[ ]");
    }
}

void swap_char(char *a, char *b){
    char tmp[5];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}
///zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
void move_char(char *input, struct cell map_cells[9][13], struct characters charr[8], char keys[6], int exits[4], int mrjck, struct node **head, int *light_line, int movenum, int *checked){

    int i, j, or, either;
    static int index = 0;
    int inputi, inputj, b = 0, l, found = 0, run = 0, mj = 0;
    int desti, destj, ms = 1;
    char atime[8];

    for ( i = 0 ; i < 8 ; i++){
        if ( strcmp(charr[i].inicialize, input) == 0){
            strcpy(atime, charr[i].time);
        }
    }

    if ( strcmp(charr[mrjck].inicialize, input) == 0){
        mj = 1;
    }


    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, input) == 0){
                inputi = i;
                inputj = j;
                b = 1;
                break;
            }
        }
        if ( b == 1){
            break;
        }
    }

    desti = inputi;
    destj = inputj;
    int bf = 0, chosei;
    for ( i = 0 ; i < 8 ; i++){
        if ( strcmp(charr[i].inicialize, input) == 0){
            l = charr[i].movement_range[1];
            chosei = i;
        }
    }

    if ( strcmp(atime, "Either") == 0){
        printf("\n%c You should to do your ability before or after moving, 1 to do after, 0 to do before moving: ", 249);
        scanf("%d", &either);
        if ( either == 0){
            bf = 1;
        }
    }

    if ( strcmp(atime, "Or") == 0){
        printf("\n%c You should choose between using ability or moving, 1 to move, 0 to use ability: ", 249);
        scanf("%d", &or);
        if ( or == 0){
            char swpp[3];
            printf("\n%c Enter the characters initial you want to swap spots with: ", 249);
            scanf("%s", swpp);
            for ( int p = 0 ; p < 9 ; p++){
                for ( int u = 0 ; u < 13 ; u++){
                    if ( strcmp(map_cells[p][u].in, swpp) == 0){
                        swap_char(map_cells[p][u].in, map_cells[inputi][inputj].in);
                        return;
                    }
                }
            }
        }
    }

    if ( strcmp(atime, "Before") == 0 || bf == 1){
        printf("\n%c You should do your ability (%s) before moving. ", 249, charr[chosei].ability);
        if ( strcmp(charr[chosei].inicialize, "JB") == 0){
            int oh, bh;
            printf("\n%c Enter the number of open and blocked hole to switch: ", 249);
            scanf("%d %d", &oh, &bh);
            switch_hole(map_cells, oh, bh );
            printf("\n");
            print_map(map_cells, exits, charr);
            printf("\n");
        }
        else if ( strcmp(charr[chosei].inicialize, "IL") == 0){
            printf("\n%c Enter the number of open and blocked exit to switch (exits are numbered 1-4 clock wise): ", 249);
            int fe, ce;
            scanf("%d %d", &fe, &ce);
            int tmpi;
            tmpi = exits[fe-1];
            exits[fe-1] = exits[ce-1];
            exits[ce-1] = tmpi;
            printf("\n");
            print_map(map_cells, exits, charr);
            printf("\n");
        }
        else if ( strcmp(charr[chosei].inicialize, "JS") == 0){
            int oh, bh;
            printf("\n%c Enter the number of on and off light to switch: ", 249);
            scanf("%d %d", &oh, &bh);
            switch_light(map_cells, oh, bh );
            printf("\n");
            print_map(map_cells, exits, charr);
            printf("\n");
        }
        else if ( strcmp(charr[chosei].inicialize, "SG") == 0){
            int oh, bh;
            int c = 1, *max_moves;
            max_moves = malloc ( sizeof(int));
            *max_moves = 3;
            char sginp[2];
            printf("\n");
            while ( c < 4 && *max_moves > 0 ){
                printf("\n%c Enter the initial of person %d to move towards \"SG\" (must take the closest rout) : ", 249, c);
                scanf("%s", sginp);
                if (!search_char(charr, sginp)){
                    move_1(map_cells, sginp, keys, max_moves);
                    printf("\n");
                    print_map(map_cells, exits, charr);
                    c++;
                }

            }
        }




    }
    //////////////////////////////////////////////////////////////////////////////////////////
    char  movestmp[10];
    printf("\n");
    while (1){
        ms = 1;
        desti = inputi;
        destj = inputj;
        printf("%c Enter your movements keys without spaces (max %d moves): ", 249, l);

        scanf("%s", movestmp);
        if ( strlen(movestmp) > l ){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("(!) You cant enter more than %d moves, try again.\n", l);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }

        else {
            int l2 = strlen(movestmp);
            char moves[l2];
            strcpy(moves, movestmp);

            for ( i = 0 ; i < l2  ; i++){
                if ( (moves[i] != keys[0]) && (moves[i] != keys[1]) && (moves[i] != keys[2]) && (moves[i] != keys[3]) && (moves[i] != keys[4]) && (moves[i] != keys[5])){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) Invalid key entered, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    break;
                }
            }
            if (ms == 0){
                continue;
                }
            for ( i = 0 ; i < l2 ; i++){
                 if ( moves[i] == keys[0]){
                    if ( desti == 0 && destj == 1 && exits[0] == 1){
                        run = 1;
                    }
                    if ( destj % 2 == 0){
                        destj -= 1;
                    }
                    else {
                        destj -= 1;
                        desti -= 1;
                    }

                }
                else if ( moves[i] == keys[1]){
                    if ( (desti == 0 && destj == 12) && exits[1] == 1){
                        run = 1;
                    }
                    desti -= 1;
                }
                else if ( moves[i] == keys[2]){
                    if ( desti == 0 && destj == 11 && exits[1] == 1){
                        run = 1;
                    }
                    if ( destj % 2 == 0){
                        destj += 1;
                    }
                    else {
                        destj += 1;
                        desti -= 1;
                    }

                }
                else if ( moves[i] == keys[3]){
                    if ( desti == 8 && destj == 0 && exits[3] == 1){
                        run = 1;
                    }
                    if ( destj % 2 == 0){
                        destj -= 1;
                        desti += 1;
                    }
                    else {
                        destj-= 1;
                    }

                }
                else if (moves[i] == keys[4]){
                    if ( ((desti == 8 && destj == 0) && exits[3] == 1 ) || ((desti == 8 && destj == 12) && exits[2] == 1)){
                        run = 1;

                    }

                    desti += 1;
                }
                else if ( moves[i] == keys[5]){
                    if ( desti == 8 && destj == 12 && exits[2] == 1){
                        run = 1;
                    }
                    if ( destj % 2 == 0){
                        destj += 1;
                        desti += 1;
                    }
                    else {
                        destj += 1;
                    }

                }
                if ( run == 1 && mj == 1 && movenum == 0 && charr[mrjck].vistmp == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                    printf("\n\n\n----> Mr.Jack ran out of town, \"Mr.Jack\" is the winner! <----\n\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    exit(1);
                }
                if ( map_cells[desti][destj].type == 4 && movenum == 1){
                    int capnum;
                    printf("\n%c You have reached a character enter 1 to capture else enter 0: ", 249);
                    scanf("%d", &capnum);
                    if ( capnum == 1){
                        if ( strcmp(map_cells[desti][destj].in, charr[mrjck].inicialize) == 0){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                            printf("\n\n\n----> Detective caught Mr.Jack, \"Detective\" is the winner! <----\n\n\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                            exit (1);
                        }
                        else {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                            printf("\n\n\n----> Detective didnt catch Mr.Jack, \"Mr.Jack\" is the winner! <----\n\n\n");
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                            exit(1);
                        }
                    }

                }
                if ( desti == inputi && destj == inputj){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant end on the starting position, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    break;
                }
                if (  (desti < 0 || desti > 8 || destj < 0 || destj > 12)){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant exit the map, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    desti = inputi;
                    destj = inputj;
                    break;
                }
                if ( (map_cells[desti][destj].type == 1 || map_cells[desti][destj].type == 4 || map_cells[desti][destj].type == 3) && (strcmp(input, "MS") != 0) ){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant move through or end on objects, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    desti = inputi;
                    destj = inputj;
                    break;
                }

                if ( map_cells[desti][destj].in[0] == 'O'){
                    printf("\n%c You have reached a (Hole) if you want to use it enter 1 else enter 0: ", 249);
                    int hii;
                    scanf("%d", &hii);
                    if ( hii == 1){
                        int ih;
                        printf("\n%c Enter number of destination hole to move: ", 249);
                        scanf("%d", &ih);
                        travel_hole(map_cells, &desti, &destj, ih);
                    }
                    else{
                        ms = 1;
                    }
                }
            }
            if ( (map_cells[desti][destj].type != 0 && map_cells[desti][destj].type != 9) && (strcmp(input, "MS") == 0)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf("(!) You cant end on objects, try again.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                ms = 0;
            }
            if ( ms == 0){
                continue;
            }
            if ( ms == 1){
                if ( map_cells[desti][destj].type == 9  && (map_cells[desti][destj].in[0] == 'X' || map_cells[desti][destj].in[0] == 'O') ){
                    strcpy(map_cells[desti][destj].bg, map_cells[desti][destj].in);
                    strcpy(map_cells[desti][destj].in, map_cells[inputi][inputj].in);
                    strcpy(map_cells[inputi][inputj].in, "N");
                    break;
                }
                else {
                    swap_char(map_cells[inputi][inputj].in, map_cells[desti][destj].in);
                    break;
                }
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////
    if ( strcmp(atime, "After") == 0 || either == 1){
        printf("\n");
        print_map(map_cells, exits, charr);
        printf("\n");

        printf("\n%c You should do your ability (%s) after moving. ", 249, charr[chosei].ability);
        if ( strcmp(charr[chosei].inicialize, "JB") == 0){
            int oh, bh;
            printf("\n%c Enter the number of open and blocked hole to switch: ", 249);
            scanf("%d %d", &oh, &bh);
            switch_hole(map_cells, oh, bh );

        }
        else if ( strcmp(charr[chosei].inicialize, "IL") == 0){
            printf("\n%c Enter the number of open and blocked exit to switch (exits are numbered 1-4 clock wise): ", 249);
            int fe, ce;
            scanf("%d %d", &fe, &ce);
            int tmpi;
            tmpi = exits[fe-1];
            exits[fe-1] = exits[ce-1];
            exits[ce-1] = tmpi;

        }
        else if ( strcmp(charr[chosei].inicialize, "JS") == 0){
            int oh, bh;
            printf("\n%c Enter the number of on and off light to switch: ", 249);
            scanf("%d %d", &oh, &bh);
            switch_light(map_cells, oh, bh );

        }
        else if ( strcmp(charr[chosei].inicialize, "SH") == 0){
            printf("\n\n%c Enter 1 to see one of the cards (Mr.jacks card isnt included): ", 249);
            int in1;
            scanf("%d", &in1);
            srand(time(NULL));
            int rndm;

            while (1){
                rndm = rand() % 8;
                if ( rndm != mrjck && check_arr_int(checked, rndm)){
                    checked[index] = rndm;
                    break;
                }
            }
            print_card(charr[rndm]);
            printf("\n");
            getchar();
            for ( int p = 4 ; p > 0 ; p--){
            printf("\rWill continue the game in %ds", p);
            delay1sec();
        }

        }
        else if ( strcmp(charr[chosei].inicialize, "JW") == 0){
            int fff = 0;
            char ch;

            while(1){
            printf("\n%c Enter a direction to light up: ", 249);
            getchar();
            scanf("%c", &ch);

            for ( int a = 0 ; a < 6 ; a++){
                if ( keys[a] == ch){
                    *light_line = a;
                    fff = 1;
                    break;
                }
            }
                if ( fff == 1){
                    break;
                }
                else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf("(!) Invalid key, try again.");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

                }
            }

        }
        else if ( strcmp(charr[chosei].inicialize, "SG") == 0){
            int oh, bh;
            int c = 1, *max_moves;
            max_moves = malloc ( sizeof(int));
            *max_moves = 3;
            char sginp[2];
            printf("\n");
            while ( c < 4 && *max_moves > 0 ){
                printf("\n%c Enter the initial of person %d to move towards \"SG\" (must take the closest rout) : ", 249, c);
                scanf("%s", sginp);
                if (!search_char(charr, sginp)){
                    move_1(map_cells, sginp, keys, max_moves);
                    printf("\n");
                    print_map(map_cells, exits, charr);
                    c++;
                }

            }
        }


    }

}

///zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
void turnoff_light(char *light, struct cell map_cells[9][13], char *light2){
    int i, j;
    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(light, map_cells[i][j].in) == 0){
                strncpy(map_cells[i][j].in, light2, 3);
            }
        }
    }
}

void switch_hole(struct cell map_cells[9][13], int a, int b){

    char *arr2;
    arr2 = malloc ( 2 * sizeof(char));
    arr2[0] = 'X';
    arr2[1] = b + '0';
    arr2[2] = '\0';


    char *arr1;
    arr1 = malloc ( 2 * sizeof(char));
    arr1[0] = 'O';
    arr1[1] = a + '0';
    arr1[2] = '\0';

    int i, j, fi, fj, li , lj;

    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, arr1) == 0){
                fi = i;
                fj = j;
            }

        }
    }
    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, arr2) == 0){
                li = i;
                lj = j;
            }

        }
    }
    swap_char(map_cells[fi][fj].in, map_cells[li][lj].in);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\n(%c) Ability was used successfully.\n\n",251);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void switch_light(struct cell map_cells[9][13], char a, char b){\
    char *arr2;
    arr2 = malloc ( 3 * sizeof(char));
    arr2[0] = 'L';
    arr2[1] = 'O';
    arr2[2] = b + '0';
    arr2[3] = '\0';


    char *arr1;
    arr1 = malloc ( 2 * sizeof(char));
    arr1[0] = 'L';
    arr1[1] = a + '0';
    arr1[2] = '\0';

    int i, j, fi, fj, li , lj;

    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, arr1) == 0){
                fi = i;
                fj = j;
            }

        }
    }
    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, arr2) == 0){
                li = i;
                lj = j;
            }

        }
    }
    swap_char(map_cells[fi][fj].in, map_cells[li][lj].in);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\n(%c) Ability was used successfully.\n\n",251);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}


void travel_hole( struct cell mapp[9][13], int *desti, int *destj, int a){

    int i, j;
    char *dh;
    dh = malloc ( 2 * sizeof(char));
    dh[0] = 'O';
    dh[1] = a + '0';
    dh[2] = '\0';
    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(mapp[i][j].in, dh) == 0){
                *desti = i;
                *destj = j;
                return;
            }

        }
    }
}


void do_visibility(struct characters charr[8], struct cell map_cells[9][13], int mrjack, int light_line, char keys[6], int t){

    int i;


    for ( i = 0 ; i < 8 ; i++){
        charr[i].vistmp = check_visibility(charr[i], map_cells);
    }
    if ( t == 1){
        light_line_visi(charr, map_cells, light_line, keys);
    }

    if ( charr[mrjack].vistmp == 1){
        printf("\n\n%c Mr.jack is visible, marking invisible cards...\n\n", 249);
        for ( i = 0 ; i < 8 ; i++){
            if ( charr[i].visi != 0 && charr[i].vistmp == 0){
                charr[i].visi = 0;

            }
        }
    }

    else {
        printf("\n\n%c Mr.jack is invisible, marking visible cards...\n\n", 249);

        for ( i = 0 ; i < 8 ; i++){
            if ( charr[i].vistmp != 0 && charr[i].visi != 0){
                charr[i].visi = 0;
            }
        }
    }

}

int check_visibility(struct characters charr, struct cell map_cells[9][13]){

    int i, j;
    int ai, aj, found = 0;

    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, charr.inicialize) == 0){
                ai = i;
                aj = j;
                found = 1;
                break;
            }
        }
        if ( found == 1){
            break;
        }
    }
    if ( aj %  2 == 0){
            if ( (ai > 0 && map_cells[ai- 1][aj].type == 3) || ( ai < 8 && map_cells[ai + 1][aj].type == 3) || ( aj >  0 && map_cells[ai][aj - 1].type == 3) || (aj < 12 && map_cells[ai][aj + 1].type == 3) || (aj < 12 && ai < 8 && map_cells[ai + 1][aj + 1].type == 3) || (ai < 8 && aj > 0 && map_cells[ai + 1][aj - 1].type == 3)|| (ai > 0 && map_cells[ai- 1][aj].type == 4) || ( ai < 8 && map_cells[ai + 1][aj].type == 4) || ( aj >  0 && map_cells[ai][aj - 1].type == 4) || (aj < 12 && map_cells[ai][aj + 1].type == 4) || (aj < 12 && ai < 8 && map_cells[ai + 1][aj + 1].type == 4) || (ai < 8 && aj > 0 && map_cells[ai + 1][aj - 1].type == 4)){
                return 1;
            }
            else {
                return 0;
            }
    }
    else {
        if ( (ai > 0 && map_cells[ai - 1][aj].type == 3) || (ai < 8 && map_cells[ai + 1][aj].type == 3) || (ai > 0 && aj > 0 && map_cells[ai - 1][aj - 1].type == 3) || ( ai > 0 && aj < 12 && map_cells[ai - 1][aj + 1].type == 3) || (aj > 0 && map_cells[ai][aj - 1].type == 3) || (aj < 12 && map_cells[ai][aj + 1].type == 3 ) || (ai > 0 && map_cells[ai - 1][aj].type == 4) || (ai < 8 && map_cells[ai + 1][aj].type == 4) || (ai > 0 && aj > 0 && map_cells[ai - 1][aj - 1].type == 4) || ( ai > 0 && aj < 12 && map_cells[ai - 1][aj + 1].type == 4) || (aj > 0 && map_cells[ai][aj - 1].type == 4) || (aj < 12 && map_cells[ai][aj + 1].type == 4 )){
            return 1;
        }
        else{
            return 0;
        }
    }
}


void move_1(struct cell map_cells[9][13], char *input, char keys[6], int *p){

    int i, j;
    int ms = 0;
    int inputi, inputj, desti, destj;

    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cells[i][j].in, input) == 0){
                inputi = i;
                inputj = j;

            }
        }
    }

    desti = inputi;
    destj = inputj;


    char  movestmp[10];
    printf("\n");
    int tfrgh;
    while (1){
        ms = 1;
        desti = inputi;
        destj = inputj;
        int l = *p;
        printf("%c Enter your movements keys without spaces (max %d moves): ", 249, l);

        scanf("%s", movestmp);
        if ( strlen(movestmp) > l ){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("(!) You cant enter more than %d moves, try again.\n", l);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }

        else {
            int l2 = strlen(movestmp);
            tfrgh = l2;
            char moves[l2];
            strcpy(moves, movestmp);

            for ( i = 0 ; i < l2  ; i++){
                if ( (moves[i] != keys[0]) && (moves[i] != keys[1]) && (moves[i] != keys[2]) && (moves[i] != keys[3]) && (moves[i] != keys[4]) && (moves[i] != keys[5])){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) Invalid key entered, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    break;
                }
            }
            if (ms == 0){
                continue;
                }
            for ( i = 0 ; i < l2 ; i++){
                 if ( moves[i] == keys[0]){
                    if ( destj % 2 == 0){
                        destj -= 1;
                    }
                    else {
                        destj -= 1;
                        desti -= 1;
                    }

                }
                else if ( moves[i] == keys[1]){
                    desti -= 1;
                }
                else if ( moves[i] == keys[2]){
                    if ( destj % 2 == 0){
                        destj += 1;
                    }
                    else {
                        destj += 1;
                        desti -= 1;
                    }

                }
                else if ( moves[i] == keys[3]){
                    if ( destj % 2 == 0){
                        destj -= 1;
                        desti += 1;
                    }
                    else {
                        destj-= 1;
                    }

                }
                else if (moves[i] == keys[4]){
                    desti += 1;
                }
                else if ( moves[i] == keys[5]){
                    if ( destj % 2 == 0){
                        destj += 1;
                        desti += 1;
                    }
                    else {
                        destj += 1;
                    }

                }
                if ( desti == inputi && destj == inputj){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant end on the starting position, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    break;
                }
                else if (  (desti < 0 || desti > 8 || destj < 0 || destj > 12)){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant exit the map, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    desti = inputi;
                    destj = inputj;
                    break;
                }
                else if ( (map_cells[desti][destj].type == 1 || map_cells[desti][destj].type == 4 || map_cells[desti][destj].type == 3) && (strcmp(input, "MS") != 0) ){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    printf("(!) You cant move through or end on objects, try again.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    ms = 0;
                    desti = inputi;
                    destj = inputj;
                    break;
                }

                if ( (map_cells[desti][destj].in[0] == 'O' || map_cells[desti][destj].in[0] == 'X')){
                    printf("\n%c You have reached a (Hole) if you want to use it enter 1 else enter 0: ", 249);
                    int hii;
                    scanf("%d", &hii);
                    if ( hii == 1){
                        int ih;
                        printf("\n%c Enter number of destination hole to move: ", 249);
                        scanf("%d", &ih);
                        travel_hole(map_cells, &desti, &destj, ih);
                    }
                    else{
                        ms = 1;
                    }
                }
            }
            if ( (map_cells[desti][destj].type != 0) && (strcmp(input, "MS") == 0)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                printf("(!) You cant end on objects, try again.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                ms = 0;
            }
            if ( ms == 0){
                continue;
            }
            if ( ms == 1){
                if ( map_cells[desti][destj].type == 9  && (map_cells[desti][destj].in[0] == 'X' || map_cells[desti][destj].in[0] == 'O') ){
                    strcpy(map_cells[desti][destj].bg, map_cells[desti][destj].in);
                    strcpy(map_cells[desti][destj].in, map_cells[inputi][inputj].in);
                    strcpy(map_cells[inputi][inputj].in, "N");
                    break;

                }
                else {
                    swap_char(map_cells[inputi][inputj].in, map_cells[desti][destj].in);
                    break;
                }
            }
        }
    }
    *p = *p - tfrgh;
}


void search_char(struct characters charr[8], char *inp){

    for ( int i = 0 ; i < 8 ; i++){
        if ( strcmp(charr[i].inicialize, inp) == 0){
            return 1;
        }

    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("(!) Character \"%s\" doesnt exist.\n", inp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

    return 0;

}


void light_line_visi(struct characters charr[8], struct cell map_cell[9][13], int line_light, char keys[6]){

    int i, j, desti, destj;

    for ( i = 0 ; i < 9 ; i++){
        for ( j = 0 ; j < 13 ; j++){
            if ( strcmp(map_cell[i][j].in, "JW") == 0){
                desti = i;
                destj = j;

            }
        }
    }

                if ( line_light == 0){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    if ( destj % 2 == 0){
                        destj -= 1;
                    }
                    else {
                        destj -= 1;
                        desti -= 1;
                    }
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp(map_cell[desti][destj].in, charr[k].inicialize) == 0){
                                charr[k].vistmp = 1;
                            }
                        }
                    }
                }
            }
                else if ( line_light == 1){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    desti -= 1;
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp(map_cell[desti][destj].in, charr[k].inicialize) == 0){
                                charr[k].vistmp = 1;
                            }
                        }
                    }
                    }
                }
                else if ( line_light == 2){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    if ( destj % 2 == 0){
                        destj += 1;
                    }
                    else {
                        destj += 1;
                        desti -= 1;
                    }
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp(map_cell[desti][destj].in, charr[k].inicialize) == 0){
                                charr[k].vistmp = 1;
                            }
                        }
                    }
                }

                }
                else if ( line_light == 3){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    if ( destj % 2 == 0){
                        destj -= 1;
                        desti += 1;
                    }
                    else {
                        destj-= 1;
                    }
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp(map_cell[desti][destj].in, charr[k].inicialize) == 0){
                                charr[k].vistmp = 1;
                            }
                        }
                    }
                }

                }
                else if (line_light == 4){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    desti += 1;
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp(map_cell[desti][destj].in, charr[k].inicialize) == 0){
                                charr[k].vistmp = 1;
                            }
                        }
                    }
                    }
                }
                else if ( line_light == 5){
                    while(desti >= 0 && desti < 9 && destj >= 0 && destj < 13 && map_cell[desti][destj].in[0] != 'H'){
                    if ( destj % 2 == 0){
                        destj += 1;
                        desti += 1;
                    }
                    else {
                        destj += 1;
                    }
                    if ( map_cell[desti][destj].type == 4){
                        for ( int k = 0 ; k < 8 ; k++){
                            if ( strcmp( map_cell[desti][destj].in, charr[k].inicialize) == 0){

                                charr[k].vistmp = 1;
                            }
                        }
                    }

                    }
                }
}






int arr_to_num(int *arr){
    int num = 0, i;
    for ( i = 0 ; i < 4 ; i++){
        num += arr[i];
        if ( i != 3){
            num *= 10;

        }
    }
    return num;
}


int revert(int *arr){
    int i, j = 0;
    int *arr2;
    arr2 = malloc ( 4 * sizeof(int));
    for ( i = 7 ; i >= 0 ; i--){
        if ( checkarr(arr, 4, i)){
            arr2[j] = i;
            j++;
        }
        if ( j == 4){
            break;
        }
    }
    return arr_to_num(arr2);
}

int checkarr(int *arr, int c, int r){

    int i;

    for ( i = 0 ; i < c ; i++){
        if ( arr[i] == r){
            return 0;
        }
    }
    return 1;
}



#endif // PLAY_GAME_H_INCLUDED
