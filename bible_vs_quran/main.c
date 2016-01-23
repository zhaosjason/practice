#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hashtable.h"

void testHashTable();

/*
 * Comparison function for qsort()
 * Returns positive integer if a < b, 0 if a = b, and a negative integer if a > b
 */
int cmpFunc(const void *a, const void *b){
	struct Node *na = *(struct Node **) a;
	struct Node *nb = *(struct Node **) b;

	return (nb->value) - (na->value);
}

int main(){
	struct HashTable *ht;
	unsigned int buckets = 8000;

	ht = malloc(sizeof(struct HashTable));
	init(ht, buckets);

	char filename[30];
	printf("Enter filename: ");
	fgets(filename, sizeof(filename), stdin);
	filename[strlen(filename) - 1] = '\0';

	FILE *fd = fopen(filename, "r");

	char c;
	int i = 0;
	char buff[25];
	while((c = fgetc(fd)) != EOF){
		if(isalpha(c))
			buff[i++] = tolower(c);
		else if(c == ' ' || c == '\n' || c == '-'){
			if(i > 0){
				buff[i] = '\0';
				if(!incrementEntry(ht, buff))
					addEntry(ht, buff, 1);
			}

			memset(buff, 0, sizeof(buff));
			i = 0;
		}
	}

	fclose(fd);

	printf("Print hashtable? (y/n) ");
	if(getchar() == 'y'){
		printf("--------------- HashTable ---------------\n");
		printTable(ht);
		printf("-----------------------------------------\n");
	}

	int temp;
	char word[25];
	printf("---------- Lookup & List Top N ----------\n");
	while(fgets(word, sizeof(word), stdin) != NULL){
		word[strlen(word) - 1] = '\0';

		int len = strlen(word);
		if(len > 0){
			int isDigit = 1;
			int c;
			for(c = 0; c < len; c++){
				if(!isdigit(word[c])){
					isDigit = 0;
					break;
				}
			}

			if(isDigit){
				temp = atoi(word);

				struct Node **list = malloc(sizeof(struct Node) * temp);
				int size = getTopNEntries(ht, list, temp);
				qsort(list, size, sizeof(struct Node *), cmpFunc);

				int j;
				for(j = 0; j < size; j++){
					struct Node *n = list[j];
					printf("[%03d] %s: %d\n", j + 1, n->key, n->value);
				}

				free(list);
			}
			else{
				char *p = word;
				while(*p){
					*p = tolower(*p);
					p++;
				}

				if(getEntry(ht, word, &temp))
					printf("%s -> %d\n", word, temp);
				else
					printf("no entries found\n");

			}
		}
	}

	freeTable(ht);
	return 0;
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
