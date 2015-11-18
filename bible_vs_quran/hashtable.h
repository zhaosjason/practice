#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <stdlib.h>

struct Node {
	char *key;
	int value;
	struct Node *next;
};

struct HashTable {
	unsigned int size;
	struct Node **arr;
};

/*
 * Initialize an empty HashTable of size <buckets>
 */
static inline void init(struct HashTable *ht, unsigned int buckets){
	struct Node **_arr = malloc(sizeof(struct Node) * buckets);

	int i;
	for(i = 0; i < buckets; i++){
		_arr[i] = 0;
	}

	ht->arr = _arr;
	ht->size = buckets;
}

/*
 * Returns an integer index from a hash of the provided string <key>
 */
unsigned int hash(struct HashTable *ht, char *key);

/*
 * Adds an entry to <ht> if an entry with the same key doesn't already exist
 * Returns 1 on success, 0 if an entry with the same key already exists
 */
int addEntry(struct HashTable *ht, char *key, int value);

/*
 * Updates the entry found with <key> to the integer stored in <value>
 * Returns 1 on success, 0 if no entry is found
 */
int updateEntry(struct HashTable *ht, char *key, int value);

/*
 * Increments the value of the entry found with <key> by one
 * Adds an entry with value = 0 if no entry with key <key> is found
 * Returns 1 on successful incrementation, 0 if entry was added
 */
int incrementEntry(struct HashTable *ht, char *key);

/*
 * Finds the entry with key <key> and returns its value
 * Returns NULL if no entry is found
 */
int getEntry(struct HashTable *ht, char *key);

/*
 * Removes the entry with key <key>
 * Returns 1 on success, 0 if no entry is found
 */
int removeEntry(struct HashTable *ht, char *key);

/*
 * Prints all entries in the hashtable
 */
void printTable(struct HashTable *ht);

/*
 * Removes all entries from <ht> and frees its memory
 */
void freeTable(struct HashTable *ht);


#endif /* ifndef _HASHTABLE_H_ */