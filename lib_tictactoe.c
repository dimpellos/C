#include <stdio.h>
#include <ctype.h>
#include "lib_tictactoe.h"

char location[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
char slot[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
int loc[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

int a;
int cursor = 4;



int check(){
	if(slot[1] != ' ' && slot[1]==slot[2] && slot[2]==slot[3]){
        return 1;
    }
	else if(slot[4]==slot[5] && slot[5]==slot[6] && slot[4] != ' '){
        return 1;
    }
	else if(slot[7]==slot[8] && slot[8]==slot[9] && slot[7] != ' '){
        return 1;
    }
	else if(slot[1]==slot[4] && slot[4]==slot[7] && slot[1] != ' '){
        return 1;
    }
	else if(slot[2]==slot[5] && slot[5]==slot[8] && slot[2] != ' '){
        return 1;
    }
	else if(slot[3]==slot[6] && slot[6]==slot[9] && slot[3] != ' '){
        return 1;
    }
	else if(slot[1]==slot[5] && slot[5]==slot[9] && slot[1] != ' '){
        return 1;
    }
	else if(slot[3]==slot[5] && slot[5]==slot[7] && slot[3] != ' '){
        return 1;
    }
	else if(slot[1]!=' ' && slot[2]!=' ' && slot[3]!=' ' && slot[4]!=' ' && slot[5]!=' ' && slot[6]!=' ' && slot[7]!=' ' && slot[8]!=' ' && slot[9]!=' '){
        return 0;
    }
	else {
        return -1;
    }

}	

void board(){
	printf("\n\n     TIC-TAC-TOE\n\n");
    printf("     Player1: O\n");
    printf("     Player2: X\n\n");
    printf("\t\t\t       |     |      \n");
    printf("\t\t\t    %c  |  %c  |  %c \n", slot[6], slot[7], slot[8]);
    printf("\t\t\t    %c  |  %c  |  %c \n", location[6], location[7], location[8]);
	printf("\t\t\t ------ ----- ------\n");
    printf("\t\t\t       |     |      \n");
    printf("\t\t\t    %c  |  %c  |  %c \n", slot[3], slot[4], slot[5]);
    printf("\t\t\t    %c  |  %c  |  %c \n", location[3], location[4], location[5]);
    printf("\t\t\t ------ ----- ------\n");
    printf("\t\t\t       |     |      \n");
    printf("\t\t\t    %c  |  %c  |  %c \n", slot[0], slot[1], slot[2]);
    printf("\t\t\t    %c  |  %c  |  %c \n\n\n", location[0], location[1], location[2]);
}

void game() {


    int rounds = 9;
    char icon = 'O';
    bool player = true;
	while(1) {
		location[cursor] = '-';
		board();
		char ch;
		
		while(rounds > 0){
	        ch = toupper(getchar());
            switch (ch) {
                case 'W': 
                    if(cursor!=6 && cursor!=7 && cursor!=8)
                        cursor = cursor + 3;
                    break;
                case 'S': 
                    if(cursor!=0 && cursor!=1 && cursor!=2)
				        cursor = cursor - 3;
                    break;
                case 'A': 
                    if(cursor!=6 && cursor!=3 && cursor!=0)
                        cursor = cursor - 1;
                    break;
                case 'D':
                    if(cursor!=8 && cursor!=5 && cursor!=2) {
                        cursor = cursor + 1; 
                    }
                    break;
                case 'P': 
                    if (playerMove(cursor, icon, player)) {
                        rounds--;
                        player = !player;
                    }
                    break;
                default:

            }
            
            clearCursor();
            location[cursor] = '-';
            if (player) {
                icon = 'O';
            } else {
                icon = 'X';
            }
            clear();
            board();
            if (check())
                break; 
            continue;
        }
        if (check())
            printGameOver();    
	}
}

bool playerMove(int cursor, char icon, bool player) {
    if (slot[cursor] == ' ') {
        slot[cursor] = icon;
        return true;
    }
    return false;
}

void clearCursor() {
    for (int i = 0; i < 9; ++i)
        location[i] = ' ';
}

void printGameOver() {
    printf("GAME OVER!!!!");
    sleep(2);
}