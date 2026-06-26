#ifndef GAME_H
#define GAME_H

typedef struct {
    int wg; 
    char ws[7];
} Game;

void display(const Game *game, const char *guess);

#endif
