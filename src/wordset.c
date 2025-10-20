#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

int main(int argc, char *argv[]) {
    struct hashMap mp;
    initializeHashMap(&mp);
    int error = 0;
    const char *filename = argv[1];
    FILE *file = NULL;
    if (argc >= 2) {
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "error\n");
        error++;
        return 1;
        }
    } 
    else {
        file = stdin;
    }
    if (file == NULL) {
        return 1;
    }
    char cmd;
    // Buffer size set to 1024 to accommodate very long words
    char word[1024];

    while (fscanf(file, " %c %1023s", &cmd, word) != EOF) {
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
        }
        else if (cmd == 'R') {
            FILE *fptr = fopen(word, "rx");  // fail if file doesn't exist
            if (!fptr) {
                fprintf(stderr, "error\n");
                error++;
                continue;
            }

            char buffer[1024];
            while (fscanf(fptr, "%1023s", buffer) == 1) {
                if (!search(&mp, buffer)) {
                    insert(&mp, buffer);
                }
            }

            fclose(fptr);
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


