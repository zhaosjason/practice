#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hashtable.h"

void testHashTable();

int main(){
	struct HashTable *bible;
	unsigned int buckets = 5000000;

	bible = malloc(sizeof(struct HashTable));
	init(bible, buckets);

	FILE *fd = fopen("bible.txt", "r");

	char c;
	int i = 0;
	char buff[25];
	while((c = fgetc(fd)) != EOF){
		if(isalpha(c))
			buff[i++] = c;
		else if(c == ' '){
			if(i > 0){
				buff[i] = '\0';
				if(!incrementEntry(bible, buff))
					addEntry(bible, buff, 1);
			}

			memset(buff, 0, sizeof(buff));
			i = 0;
		}
	}

	fclose(fd);

	printf("--------------- HashTable ---------------\n");
	printTable(bible);
	printf("-----------------------------------------\n");

	//testHashTable();
	freeTable(bible);
}

void testHashTable(){
	struct HashTable *ht;
	unsigned int buckets = 5000;
	char word[100];

	ht = malloc(sizeof(struct HashTable));
	init(ht, buckets);

	int i = 0;
	while(1){
		// Adding
		printf("addEntry: ");
		scanf("%s", word);
		addEntry(ht, word, i++);

		getchar();

		printf("increment? ");
		char c = fgetc(stdin);
		if(c == 'y')
			incrementEntry(ht, word);

		// Printing
		printf("--------------- HashTable ---------------\n");
		printTable(ht);
		printf("-----------------------------------------\n");
		
		// Lookup
		int temp;
		printf("lookup: ");
		scanf("%s", word);
		if(getEntry(ht, word, &temp))
			printf("%s->%d\n", word, temp);
		else
			printf("no entries found\n");
	}
}
