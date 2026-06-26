#ifndef TERMIO_UTILS_H
#define TERMIO_UTILS_H

// Initialize terminal for single-character input
//  - save current settings in 'old'
//  - copy settings to 'new' and modify:
//     disable canonical mode for unbuffered input
//     enable/disable echo based on parameter
//  - apply new settings immediately
void initTermios(int echo);
// Restore the original terminal settings saved in 'old'
void resetTermios(void);
// Read a single character from terminal with optional echo
//  - disables canonical mode to get immediate input
//  - echoes typed character if 'echo' is non-zero
//  - restores terminal settings after reading
//Calling getch_(0) → input is hidden (no echo).
//Calling getch_(1) → input is shown (echo enabled).
char getch_(int echo);

#endif
