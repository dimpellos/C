#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "termio_utils.h"

static struct termios old, new;

void resetTermios(void) { 
    tcsetattr(STDIN_FILENO, TCSANOW, &old); 
} 

char getch_(int echo) { 
    initTermios(echo); 
    char ch = getchar(); 
    resetTermios(); 
    return ch; 
}

void initTermios(int echo) { 
    tcgetattr(STDIN_FILENO, &old);  
    new = old;  
    new.c_lflag &= ~ICANON;  
    if (echo)
        new.c_lflag |= ECHO;
    else
        new.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new);  
}
