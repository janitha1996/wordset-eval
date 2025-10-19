#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef HASHMAP_H
#define HASHMAP_H


#define TABLE_SIZE 10009
#define START_VALUE 5381

struct node {
    char *word;
    struct node *next;
};

struct hashMap {
    int count;
    int hits;
    int errors;
    struct node **arr;
};

// function declarations
void initializeHashMap(struct hashMap *mp);
unsigned long hashFunction(const char *word);
void insert(struct hashMap *mp, const char *word);
int search(struct hashMap *mp, const char *word);
void clear_all(struct hashMap *mp);
void freeHashMap(struct hashMap *mp);

#endif // HASHMAP_H