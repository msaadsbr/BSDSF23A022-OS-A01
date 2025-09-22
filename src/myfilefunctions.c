#include "../include/myfilefunctions.h"
#include <stdlib.h>
#include <string.h>

int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1;
    *lines = *words = *chars = 0;

    char c, prev = ' ';
    while ((c = fgetc(file)) != EOF) {
        (*chars)++;
        if (c == '\n') (*lines)++;
        if ((c == ' ' || c == '\n' || c == '\t') &&
            !(prev == ' ' || prev == '\n' || prev == '\t')) {
            (*words)++;
        }
        prev = c;
    }
    rewind(file); // reset file pointer for reuse
    return 0;
}

int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str) return -1;

    size_t size = 10, count = 0;
    *matches = malloc(size * sizeof(char*));
    if (!*matches) return -1;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str)) {
            if (count >= size) {
                size *= 2;
                *matches = realloc(*matches, size * sizeof(char*));
                if (!*matches) return -1;
            }
            (*matches)[count] = strdup(buffer);
            count++;
        }
    }
    rewind(fp);
    return (int)count;
}

