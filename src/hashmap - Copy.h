#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define HASH_SIZE 10007

struct node {
    // value is string
    char *value;
    struct node *next;
};

static node *table[HASH_SIZE];  // global hash table
static size_t word_count = 0;
static size_t hits = 0;
static size_t errors = 0;

void setNode(struct node* node, char* value)
{
    node->value = value; // assign value to node
    node->next = NULL;
    return;
};

struct hashMap {
    // Current number of elements in hashMap
    // and capacity of hashMap
    int numOfElements, capacity;
    // hold base address array of linked list
    struct node** arr;
};

// like constructor
void initializeHashMap(struct hashMap* mp)
{
    // Default capacity in this case
    mp->capacity = 100;
    mp->numOfElements = 0;

    // array of size = 1
    mp->arr = (struct node**)malloc(sizeof(struct node*)
                                    * mp->capacity);
    return;
}

c(struct hashMap* mp, char* key)
{
    int bucketIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {

        // sum = sum + (ascii value of
        // char * (primeNumber ^ x))...
        // where x = 1, 2, 3....n
        sum = ((sum % mp->capacity)
               + (((int)key[i]) * factor) % mp->capacity)
              % mp->capacity;

        // factor = factor * prime
        // number....(prime
        // number) ^ x
        factor = ((factor % __INT16_MAX__)
                  * (31 % __INT16_MAX__))
                 % __INT16_MAX__;
    }

    bucketIndex = sum;
    return bucketIndex;
}

void insert(struct hashMap* mp, char* value)
{

    // Getting bucket index for the given
    // key - value pair
    int bucketIndex = hashFunction(mp, value);
    struct node* newNode = (struct node*)malloc(

        // Creating a new node
        sizeof(struct node));

    // Setting value of node
    setNode(newNode, value);

    // Bucket index is empty....no collision
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    }

    // Collision
    else {

        // Adding newNode at the head of
        // linked list which is present
        // at bucket index....insertion at
        // head in linked list
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    return;
}

char* search(struct hashMap* mp, char* value)
{

    // Getting the bucket index
    // for the given key
    int bucketIndex = hashFunction(mp, value);

    // Head of the linked list
    // present at bucket index
    struct node* bucketHead = mp->arr[bucketIndex];
    while (bucketHead != NULL) {

        // Key is found in the hashMap
        if (bucketHead->value == value) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }

    return 0;
}
