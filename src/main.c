#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char str1[100] = "Hello";
    char str2[100];

    printf("Length of '%s' = %d\n", str1, mystrlen(str1));

    mystrcpy(str2, str1);
    printf("Copy: %s\n", str2);

    mystrncpy(str2, "World", 3);
    printf("Copy 3 chars: %s\n", str2);

    mystrcat(str1, " World");
    printf("Concat: %s\n", str1);

    printf("\n--- Testing File Functions ---\n");

    FILE* f = fopen("test.txt", "r");
    if (f) {
        int lines, words, chars;
        if (wordCount(f, &lines, &words, &chars) == 0) {
            printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
        }

        char** matches;
        int count = mygrep(f, "test", &matches);
        if (count > 0) {
            printf("Found %d matching lines:\n", count);
            for (int i = 0; i < count; i++) {
                printf("%s", matches[i]);
                free(matches[i]);
            }
            free(matches);
        }
        fclose(f);
    } else {
        printf("test.txt not found. Create a file with sample text.\n");
    }

    return 0;
}
