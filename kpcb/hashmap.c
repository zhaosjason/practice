#include <stdio.h>
#include <string.h>
#include "hashmap.h"

// Currently using djb2 by Dan Bernstein
unsigned int hash(struct HashMap *hm, char *key){
	unsigned long int index = 5381;
	int len = strlen(key);

	int i;
	for(i = 0; i < len; i++){
		index = (index << 5) + index + key[i];
	}

	index %= hm->size;
	return index;

	/*** My Hashing Algorithm, pretty basic, not very good.
	unsigned long int index = 0;
	int len = strlen(key);

	int i;
	for(i = 0; i < len; i++){
		index += ((unsigned long int) key[i]) << (sizeof(int) * 8);
		index %= hm->size;
	}

	return index;
	***/
}

int set(struct HashMap *hm, char *key, void *val){
	if(get(hm, key))
		return 0;

	struct Node *node = malloc(sizeof(struct Node));
	node->val = val;

	unsigned int index = hash(hm, key);
	hm->arr[index] = node;
	hm->entries++;

	return 1;
}

void * get(struct HashMap *hm, char *key) {
	unsigned int index = hash(hm, key);
	struct Node *temp = hm->arr[index];

	if (!temp)
		return 0;

	return temp->val;
}

void * delete(struct HashMap *hm, char *key) {
	unsigned int index = hash(hm, key);
	struct Node *temp = hm->arr[index];

	if (!temp)
		return 0;

	void *ret = temp->val;
	free(temp);

	hm->arr[index] = 0;
	hm->entries--;
	return ret;
}

float load(struct HashMap *hm) {
	return ((float) hm->entries) / ((float) hm->size);
}








