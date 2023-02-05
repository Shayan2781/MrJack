#ifndef WELCOMER_LOBBY_H_INCLUDED
#define WELCOMER_LOBBY_H_INCLUDED
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
void play_song(){
    PlaySound(TEXT("C:\\Users\\user\\Downloads\\mr.jack_theme.wav"),NULL,SND_SYNC);
    printf("\n");
}

int check_arr(char *keys, char a){
    int i;

    for ( i = 0 ; i < 6 ; i++){
        if ( keys[i] == a){
            return 1;
        }
    }
    return 0;



}

void edit_key(char *keys){
    char a, b;
    int i;
    printf("\n%c Enter the key of the direction you want to change 'a' and the key you want to change to 'b' (a b): ", 16);
    getchar();
    scanf("%c %c", &a, &b);
    for ( i = 0 ; i < 6 ; i++){
        if ( check_arr(keys, a) == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("\n\n(!) Key '%c' doesnt exist, try another key.\n", a);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            return;
        }
        if ( keys[i] == b){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            printf("\n\n(!) Key '%c' already exists, try another key.\n", b);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            return;
        }


    }
    for ( i = 0 ; i < 6 ; i++){
        if ( keys[i] == a){
            keys[i] = b;
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf("\n(%c) Key '%c' was changed to '%c' successfully.\n\n",251, a, b);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    print_keys(keys);

    return;

}


void stop_song(){
    PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
}

void delay(){
    int millisec = 170;
    clock_t start_time = clock();
    while ( clock() < start_time + millisec);
}

void delay_long(){
    int millisec = 1500;
    clock_t start_time = clock();
    while ( clock() < start_time + millisec);
}

void animation_print(char *arr){
    int l, i;
    l = strlen(arr);
    for ( i = 0 ; i < l ; i++){
        printf("%c", arr[i]);
        delay();
    }

}

void welcome_animation(){

    int i, l;
    printf("\n\n\n\n\n\t\t\t\t\t\t\t");
    animation_print("Welcome to");
    printf("\n\t\t\t\t\t\t\t ");
    animation_print("MR.JACK");
    printf("\n");
    printf("\n\t\t\t\t\t\t\t");
    animation_print("Created by");
    printf("\n\t\t\t               \t             ");
    animation_print("Shayan Ahmadizad\n");
    printf("\n\t\t\t\t\t   \t       ");
    animation_print("Winter 1400\n");
    delay_long();
    system("cls");
}

void print_keys(char *keys){
    printf("   %c %c %c\n", keys[0], keys[1], keys[2]);
    printf("    \\|/\n");
    printf("    /|\\ \n");
    printf("   %c %c %c\n", keys[3], keys[4], keys[5]);
}




void setting( char *key ){

    int input, key_input, key_edit_input;
    static int rand = 0;
    char color_arrays[5][8] = {"COLOR 0A", "COLOR 09", "COLOR 0E", "COLOR 0F", "COLOR 0D"} ;

    while(1){
        system("cls");
        printf("%c Setting\n1) Keys settings\n2) Change color\n3) Help\n4) Restore all setting to default\n5) Back to main menu\nCommand: ", 16);
        scanf("%d", &input);
        if ( input == 1){
            while(1){
                system("cls");
                printf("%c Key settings\n1) Change keys\n2) Back to setting\nCommand: ", 16);
                scanf("%d", &key_input);
                if ( key_input == 1){
                    while (1){
                        system("cls");
                        printf("%c Change keys\n\n", 16);
                        print_keys(key);
                        edit_key(key);
                        printf("\n%c Enter '0' to go back to Key setting or enter '1' to change another key: ", 16);
                        getchar();
                        scanf("%d", &key_edit_input);
                        if ( key_edit_input == 0){
                            break;
                        }

                    }

                }
                else if ( key_input == 2){
                    break;
                }
            }
        }
        else if ( input == 2){
            rand = rand % 8;
            switch (rand){
                case 0: system("COLOR 0A");
                    break;
                case 1: system("COLOR 09");
                    break;
                case 2: system("COLOR 0E");
                    break;
                case 3: system("COLOR 0C");
                    break;
                case 4: system("COLOR 0D");
                    break;
                case 5: system("COLOR 0B");
                    break;
                case 6: system("COLOR 05");
                    break;
                case 7: system("COLOR 01");
                    break;

            }

            rand++;

        }
        else if ( input == 3){
            while (1){
                int help_cmd;
                system("cls");
                printf("%c Help\n", 16);
                printf("1) Map Elements\n2) Characters Card\n3) Back to setting\nCommand: ");
                scanf("%d", &help_cmd);
                if ( help_cmd == 1){
                    while (1){
                        system("cls");
                        printf("%c Map Elements\n", 16);
                        printf("%c Houses: %c%c\n", 249, 254, 254);
                        printf("%c Lamp (On): ", 249);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                        printf("%c", 221);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                        printf("\n%c Lamp (Off): %c", 249, 221);
                        printf("\n%c Hole (Open): %c", 249, 234);
                        printf("\n%c Hole (Closed): %c", 249, 237);
                        printf("\n%c Exit (Open): %s", 249, "[]");
                        printf("\n%c Exit (Closed): %s", 249, "[\\]");


                        printf("\n%c Enter '0' to go back to setting : ", 16);
                        getchar();
                        scanf("%d", &key_edit_input);
                        if ( key_edit_input == 0){
                            break;
                        }

                    }
                }
                if ( help_cmd == 3){
                    break;
                }
                if ( help_cmd == 2){
                    system("cls");
                    printf("%c Characters card", 16);
                    int i, j, k, z, length, spaces, inp;

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
                            length = strlen("Character Name");
                            spaces = (22 - length) / 2;
                            for ( k = 0 ; k < spaces ; k++){
                                printf(" ");
                            }
                            printf("%s", "Character Name");
                            for ( k = 0 ; k < 22 - length - spaces ; k++){
                                printf(" ");
                            }

                            printf("|");
                        }
                        else if ( i == 5 ){
                            printf("|");
                            printf("      (%s)       ", "Initial");
                            printf("|");

                        }
                        else if ( i == 8){
                            printf("|");
                            printf("   Movement: %c -> %c   ", 'a', 'b');
                            printf("|");
                        }
                        else if ( i == 10){
                            printf("|");
                            printf("          **          ");
                            printf("|");
                        }
                        else if ( i == 12){
                            printf("|");
                            length = strlen("Character Ability");
                            spaces = (22 - length) / 2;
                            for ( k = 0 ; k < spaces ; k++){
                                printf(" ");
                            }
                            printf("%s", "Character Ability");
                            for ( k = 0 ; k < 22 - length - spaces ; k++){
                                printf(" ");
                            }

                            printf("|");
                        }
                        else if ( i == 14){
                            printf("|");
                            length = strlen("Ability time");
                            spaces = (22 - length) / 2;
                            for ( k = 0 ; k < spaces ; k++){
                                printf(" ");
                            }
                            printf("%s", "Ability time");
                            for ( k = 0 ; k < 22 - length - spaces ; k++){
                                printf(" ");
                            }

                            printf("|");

                        }

                    }
                    printf("\n\n\n");
                    printf("%c Characters name: name of each character which is placed on top of the card.\n\n", 249);
                    printf("%c Initial: a 2 letter word which represents each character on the map.\n\n", 249);
                    printf("%c Movement: the number of minimum (a) and maximum (b) moves a character can take.\n\n", 249);
                    printf("%c Characters Ability: the special ability which each character has and can be used by the player.\n\n", 249);
                    printf("%c Ability time: the time when the character can use its ability, BEFORE moving, AFTER moving, \n  EITHER before or after, can only move OR use ability, WHILE moving.\n\n", 249);
                    printf("%c Enter 0 to go back to setting: ", 16);
                    scanf("%d", &inp);
                    if ( inp == 0){
                        break;
                    }
                }

            }


        }
        else if ( input == 4){
            system("COLOR 0F");
            defult_keys(key);
        }
        else if( input == 5){
            system("cls");
            return 1;
        }
    }
}

void interactions(int input, char *keyarr){

    if ( input == 3){
        setting(keyarr);
    }
    else if ( input == 4){
        exit(1);
    }
}



#endif // WELCOMER_LOBBY_H_INCLUDED
