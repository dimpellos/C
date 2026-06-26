#include <stdio.h>
#include "game.h"

void display(const Game *game, const char *guess) { 
    int wg = game->wg; 
    printf("\n\t Be aware you can be hanged!!.");
    printf("       _                                             \n");
    printf("      | |                                            \n");
    printf("      | |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("      | '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("      | | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("      |_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                          __/ |                      \n");
    printf("                         |___/  \n");
    printf("      ");
    printf("                coded by Dimitrios Bellos ");
    printf("\n\n\t Rules : ");
    printf("\n\t - Maximum 6 mistakes are allowed.");
    printf("\n\t - Only lower case characters.");
    printf("\n\t - All words are name of very popular websites. eg. Google");
    printf("\n\t - Enjoy ;)");
    printf("\n\n\n");
    printf("\033[H\033[J ┏━━━┓\n"); 
    printf(" ┃   │\n"); 
    printf(" ┃   %c\n", wg < 1 ? ' ' : 'O'); 
    printf(" ┃  %c%s%c\n", wg < 3 ? ' ' : '/', wg < 2 ? " " : "│", wg < 4 ? ' ' : '\\'); 
    printf(" ┃  %c %c\n", wg < 5 ? ' ' : '/', wg < 6 ? ' ' : '\\'); 
    printf(" ┃\n"); 
    printf("┏┻━━━━━━┓\n┃       ┗━┓\n┗━━━━━━━━━┛\n"); 
    printf("wrong guesses %d: %s\n", wg, game->ws); 
    printf("word: %s\n", guess); 
}
