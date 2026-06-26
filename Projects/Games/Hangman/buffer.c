#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "buffer.h"

void shuffle(Buffer *buf) { 
    size_t rnd, tmp; 
    for(size_t i = buf->words - 1; i > 0; --i) { 
        rnd = rand() % (i + 1);
        tmp = buf->index[rnd]; 
        buf->index[rnd] = buf->index[i]; 
        buf->index[i] = tmp; 
    } 
}

Buffer readwords(const char *fn) { 
    char buffer[512]; 
    char *bp = NULL, *wi = NULL, *wl = NULL; 
    size_t size, bytes, wlen = 0, ilen, len; 
    FILE *stream, *tstream; 

    FILE *fp = fopen(fn, "r"); 
    if (!fp) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    stream = open_memstream(&bp, &size); 
    while ((bytes = fread(buffer, sizeof(char), sizeof(buffer), fp)) > 0) { 
        fwrite(buffer, sizeof(char), bytes, stream); 
    }
    fflush(stream); fclose(stream); 
    fclose(fp);

    stream = open_memstream(&wi, &ilen); 
    tstream = open_memstream(&wl, &bytes); 
    for(char *tok = strtok(bp, "\n"); tok; tok = strtok(NULL, "\n")) { 
        len = strlen(tok); 
        if (len < 3 || len > 50) continue; 
        for(char *p = tok; *p; ++p) { 
            if (isalpha(*p)) *p = tolower(*p);
            else goto next_word;
        }
        fwrite(&wlen, sizeof wlen, 1, stream); 
        wlen += fprintf(tstream, "%s", tok); 
        fputc(0, tstream); 
        wlen++;

    next_word:;
    } 
    fflush(tstream); fclose(tstream); 
    fflush(stream); fclose(stream); 
    free(bp); 

    return (Buffer){.words = ilen / sizeof(ilen), .index = (size_t *)wi, .buffer = wl}; 
}
