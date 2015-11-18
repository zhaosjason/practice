#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(){
	//FILE *fd = fopen("bible.txt", "r");
	struct HashTable *ht;
	unsigned int buckets = 5000;
	char word[100];

	ht = malloc(sizeof(struct HashTable));
	init(ht, buckets);

	while(1){
		scanf("%s", word);
		addEntry(ht, word, 0);
		printf("--------------- HashTable ---------------\n");
		printTable(ht);
		printf("-----------------------------------------\n");
	}
}
