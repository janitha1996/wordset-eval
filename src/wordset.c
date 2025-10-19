#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    struct hashMap mp;
    initializeHashMap(&mp);
    int error = 0;
    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }
    char cmd;
    // Buffer size set to 225 to accommodate very long words if present in the input file.
    char word[225];

    while (fscanf(file, " %c %s", &cmd, word) != EOF) {
        if (cmd == 'I') {
            if (search(&mp, word)) {
                printf("ok\n");
                continue;
            } 
            else {
                insert(&mp, word);
                printf("ok\n");
            }
        } 
        else if (cmd == 'Q') {
            if (search(&mp, word)) {
                printf("y\n");
            } 
            else {
                printf("n\n");
            }
        }
        else if (cmd == 'S') {
            if (strcmp(word, "count") == 0) { // has to  set to STDOUT
            printf("%d\n", mp.count);
            }
            else if (strcmp(word, "hits") == 0) { // has to  set to STDOUT
            printf("%d\n", mp.hits);
            }
            else if (strcmp(word, "errors") == 0) { // has to  set to STDOUT
            printf("%d\n", error);
            }
            else {
            fprintf(stderr, "error\n");
            error++;
            }
            fflush(stdout);
        }
        else if (cmd == 'C') {
            if (strcmp(word, "all") != 0) {
                fprintf(stderr, "error\n");
                error++;
                continue;
            }
            clear_all(&mp);
            error = 0;
            printf("ok\n");
        }
        else if (cmd == 'W') {  // Write to file
            FILE *fptr = fopen(word, "wx");  // fail if file exists
            if (!fptr) {
                fprintf(stderr, "error\n");
                error++;
                continue;
            }
            else {
                for (int i = 0; i < TABLE_SIZE; i++) {
                    struct node *current = mp.arr[i];
                    while (current) {
                        fprintf(fptr, "%s\n", current->word);
                        current = current->next;
                    }
                }
            }
            fclose(fptr);
            printf("ok\n");
        }
        else if (cmd == 'R') {
            FILE *fptr = fopen(word, "rx");  // fail if file doesn't exist
            if (!fptr) {
                fprintf(stderr, "error\n");
                error++;
                continue;
            }

            char buffer[225];
            while (fscanf(fptr, "%224s", buffer) == 1) {
                if (!search(&mp, buffer)) {
                    insert(&mp, buffer);
                }
            }

            fclose(fptr);
            printf("ok\n");
        }
        else {
            fprintf(stderr, "error\n");
            error++;
        }
    }
    freeHashMap(&mp);
    fclose(file);
    return 0;
}


