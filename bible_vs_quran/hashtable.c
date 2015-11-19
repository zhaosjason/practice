#include <stdio.h>
#include <string.h>
#include "hashtable.h"

// Consider researching better hashing algorithims
unsigned int hash(struct HashTable *ht, char *key){
	unsigned long int index = 0;
	int len = strlen(key);

	int i;
	for(i = 0; i < len; i++){
		index += ((unsigned long int) key[i]) << (sizeof(int) * 8);
		index %= ht->size;
	}

	return index;
}

int addEntry(struct HashTable *ht, char *key, int value){
	// Return if entry with key already exists
	int n;
	if(getEntry(ht, key, &n))
		return 0;

	struct Node *node = malloc(sizeof(struct Node));
	node->key = strdup(key);
	node->value = value;
	node->next = 0;

	unsigned int index = hash(ht, key);
	struct Node *temp = ht->arr[index];

	if(!temp){
		ht->arr[index] = node;
	}
	else{
		while(temp->next)
			temp = temp->next;

		temp->next = node;
	}

	return 1;
}

int updateEntry(struct HashTable *ht, char *key, int value){
	return -1;
}

int incrementEntry(struct HashTable *ht, char *key){
	return -1;
}

int getEntry(struct HashTable *ht, char *key, int *dest){
	unsigned int index = hash(ht, key);
	struct Node *temp = ht->arr[index];

	while(temp){
		if(!strcmp(temp->key, key)){
			*dest = temp->value;
			return 1;
		}

		temp = temp->next;
	}

	return 0;
}

int removeEntry(struct HashTable *ht, char *key){
	return -1;
}

void printTable(struct HashTable *ht){
	int i;
	for(i = 0; i < ht->size; i++){
		if(ht->arr[i]){
			printf("[%d]:", i);

			struct Node *n = ht->arr[i];
			while(n){
				printf(" %d", n->value);
				n = n->next;
			}

			printf("\n");
		}
	}
}

void freeTable(struct HashTable *ht){
	return;
}








