#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <stdlib.h>

struct Node {
	void *val;
};

struct HashMap {
	unsigned int size;
	unsigned int entries;
	struct Node **arr;
};

/*
 * Initialize an empty HashMap of size <buckets>
 */
static inline void constructor(struct HashMap *hm, unsigned int buckets){
	struct Node **_arr = calloc(buckets, sizeof(struct Node *));

	hm->arr = _arr;
	hm->size = buckets;
	hm->entries = 0;
}

/*
 * Returns an integer index from a hash of the provided string <key>
 */
unsigned int hash(struct HashMap *hm, char *key);

/*
 * Adds an entry to <hm> if an entry with the same key doesn't already exist
 * Returns 1 on success, 0 if an entry with the same key already exists
 */
int set(struct HashMap *hm, char *key, void *val);

/*
 * Finds the entry with key <key> and stores its value in <dest>
 * Returns 1 on success and 0 if no entry is found
 */
void * get(struct HashMap *hm, char *key);

/*
 * Removes the entry with key <key>
 * Returns 1 on success, 0 if no entry is found
 */
void * delete(struct HashMap *hm, char *key);

/*
 * Returns the load factor of <hm>
 * load factor = (items in hash map)/(size of hash map)
 */
float load(struct HashMap *hm);


#endif /* ifndef _HASHMAP_H_ */