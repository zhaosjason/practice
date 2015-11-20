#include <stdio.h>
#include <string.h>
#include "hashtable.h"

// Currently using djb2 by Dan Bernstein
unsigned int hash(struct HashTable *ht, char *key){
	unsigned long int index = 5381;
	int len = strlen(key);

	int i;
	for(i = 0; i < len; i++){
		index = (index << 5) + index + key[i];
	}

	index %= ht->size;
	return index;


	/*** My Hashing Algorithm, pretty basic, not very good.
	unsigned long int index = 0;
	int len = strlen(key);

	int i;
	for(i = 0; i < len; i++){
		index += ((unsigned long int) key[i]) << (sizeof(int) * 8);
		index %= ht->size;
	}

	return index;
	***/
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

	ht->entries++;
	return 1;
}

int updateEntry(struct HashTable *ht, char *key, int value){
	unsigned int index = hash(ht, key);
	struct Node *temp = ht->arr[index];

	while(temp){
		if(!strcmp(temp->key, key)){
			temp->value = value;
			return 1;
		}

		temp = temp->next;
	}

	return 0;
}

int incrementEntry(struct HashTable *ht, char *key){
	unsigned int index = hash(ht, key);
	struct Node *temp = ht->arr[index];

	while(temp){
		if(!strcmp(temp->key, key)){
			temp->value++;
			return 1;
		}

		temp = temp->next;
	}

	return 0;
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
	unsigned int index = hash(ht, key);
	struct Node *temp = ht->arr[index];
	struct Node *prev;

	while(temp){
		if(!strcmp(temp->key, key)){
			if(prev)
				prev->next = temp->next;
			else
				ht->arr[index] = 0;

			free(temp);
			return 1;
		}

		prev = temp;
		temp = temp->next;
	}

	ht->entries--;
	return 0;
}

/*
 * Helper function for getTopNEntries(), assumes <arr> has no NULL values
 * Returns the index of the minimum value in <arr>
 */
int getMin(struct Node **arr, int size){
	int i;
	int index = 0;
	int min = arr[0]->value;
	for(i = 1; i < size; i++){
		if(arr[i]->value < min){
			min = arr[i]->value;
			index = i;
		}
	}

	return index;
}

int getTopNEntries(struct HashTable *ht, struct Node **list, int n){
	int i;
	int addedVals = 0;
	for(i = 0; i < ht->size; i++){
		if(ht->arr[i]){
			struct Node *node = ht->arr[i];
			while(node){
				if(addedVals < n)
					list[addedVals++] = node;
				else{
					int index = getMin(list, n);
					if(node->value > list[index]->value)
						list[index] = node;
				}

				node = node->next;
			}
		}
	}

	return addedVals;
}

void printTable(struct HashTable *ht){
	int i;
	for(i = 0; i < ht->size; i++){
		if(ht->arr[i]){
			printf("[%d]:", i);

			struct Node *n = ht->arr[i];
			while(n){
				printf("(%s %d) ", n->key, n->value);
				n = n->next;
			}

			printf("\n");
		}
	}
}

void freeTable(struct HashTable *ht){
	int i;
	for(i = 0; i < ht->size; i++){
		if(ht->arr[i]){
			struct Node *n = ht->arr[i];
			struct Node *prev;
			while(n){
				prev = n;
				n = n->next;
				free(prev->key);
				free(prev);
			}
		}
	}

	free(ht->arr);
	free(ht);
}








