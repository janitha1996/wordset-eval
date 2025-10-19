#include "hashmap.h"

// Initialize hash map
void initializeHashMap(struct hashMap *mp){
    mp->count = 0;
    mp->hits = 0;
    mp->errors = 0;
    mp->arr = (struct node**)calloc(TABLE_SIZE, sizeof(struct node*));
    return;
}

// Hash function (djb2)
unsigned long hashFunction(const char *word){
    unsigned long hash = START_VALUE;
    int c;
    while ((c = *word++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

// Insert new word
void insert(struct hashMap *mp, const char *word){
    unsigned long index = hashFunction(word);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->word = strdup(word);
    newNode->next = mp->arr[index];
    mp->arr[index] = newNode;
    mp->count++;
    if (!newNode) {
    fprintf(stderr, "Memory allocation failed in insert()\n");
    exit(EXIT_FAILURE);
    }
    newNode->word = strdup(word);
    if (!newNode->word) {
        fprintf(stderr, "Memory allocation failed for word copy\n");
        free(newNode);
        exit(EXIT_FAILURE);
    }
}

int search(struct hashMap *mp, const char *word){
    unsigned long index = hashFunction(word);
    struct node *current = mp->arr[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            mp->hits++;
            return 1; // found
        }
        current = current->next;
    }
    mp->errors++;
    return 0; // not found
}

void clear_all(struct hashMap *mp) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node *current = mp->arr[i];
        while (current) {
            struct node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
        mp->arr[i] = NULL;
    }
    mp->count = 0;
    mp->hits = 0;
    mp->errors = 0;
}

void freeHashMap(struct hashMap *mp) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct node *current = mp->arr[i];
        while (current) {
            struct node *tmp = current;
            current = current->next;
            free(tmp->word);
            free(tmp);
        }
        mp->arr[i] = NULL;
    }
    free(mp->arr);
    mp->arr = NULL;
}

