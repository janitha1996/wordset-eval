#include "hashmap.h"

// Initialize hash map
void initializeHashMap(struct hashMap *mp){
    mp->count = 0;
    mp->hits = 0;
    mp->arr = (struct node**)calloc(TABLE_SIZE, sizeof(struct node*));
    return;
}

// Hash function
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
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        exit(EXIT_FAILURE);
    }
    newNode->word = strdup(word);
    if (!newNode->word) {
        free(newNode);
        exit(EXIT_FAILURE);
    }
    newNode->next = mp->arr[index];
    mp->arr[index] = newNode;
    mp->count++;
}


int search(struct hashMap *mp, const char *word){
    unsigned long index = hashFunction(word);
    struct node *current = mp->arr[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            mp->hits++;
            return 1;
        }
        current = current->next;
    }
    return 0; 
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

