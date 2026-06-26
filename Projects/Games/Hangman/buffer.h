#ifndef BUFFER_H
#define BUFFER_H

#include <stddef.h>

typedef struct { 
    size_t word, words, *index; 
    char *buffer; 
} Buffer;

Buffer readwords(const char *filename);
void shuffle(Buffer *buf);

#endif
