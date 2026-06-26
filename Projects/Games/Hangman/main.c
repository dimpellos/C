#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "termio_utils.h"
#include "buffer.h"
#include "game.h"

// Now main.c only coordinates the logic.

int main(void) { 
    Buffer text = readwords("/usr/share/dict/words"); 
    Game game = {0, {[0 ... 6] = 0}}; 
    int ch;
    size_t word = 0; 
    char *guess = NULL;  
    srand(time(NULL)); 
    shuffle(&text); 

    do { 
        char *unknown = text.buffer + text.index[word]; 
        size_t len = strlen(unknown); 
        guess = realloc(guess, len + 1); 

        for(size_t i = 0; i < len; ++i) guess[i] = '_'; 
        guess[len] = 0; 

        do { 
            display(&game, guess); 
            ch = getch_(0); 
            if(strchr(unknown, ch)) {
                for(size_t i = 0; i < len; ++i) { 
                    if(ch == unknown[i]) guess[i] = ch; 
                } 
            }
            else if(!strchr(game.ws, ch)) {
                game.ws[game.wg++] = ch; 
            } 
        } while(strcmp(unknown, guess) && ch != ('d' & 0x1f) && ch != EOF && game.wg < 6); 

        display(&game, unknown); 
        if(strcmp(unknown, guess)) printf("You lost.\n"); 
        else printf("You won! With %d misses.\n", game.wg); 
        
        if(ch == EOF || ch == ('d' & 0x1f)) break; 
        
        printf("Try again (Y/n)? "); 
        ch = getch_(0); 
        
        game.wg = 0; 
        for(size_t i = 0; i < 7; ++i) game.ws[i] = 0; 
        
        ++word; 
        word %= text.words; 
        
    } while(tolower(ch) != 'n'); 
    
    printf("\ncoded by Dimitrios Bellos\n");
    
    free(guess);
    
    // Optionally free text buffer and index if needed
    free(text.buffer);
    free(text.index);

    return 0;
}
