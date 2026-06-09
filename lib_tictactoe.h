#ifndef LIB_TICTACTOE_H
#define LIB_TICTACTOE_H
#define clear() system("@cls || clear")

#include <stdbool.h>
#include <stdlib.h>

extern char location[9];
extern char slot[9];
extern int loc[9];

extern int a;
extern int cursor;

int check();
void board();
void game();
bool playerMove(int cursor, char icon, bool player);
void clearCursor();

#endif