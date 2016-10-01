#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hashmap.h"

void sanitycheck() {
	struct HashMap *hm = malloc(sizeof(struct HashMap));
	constructor(hm, 100);

	char *str1 = "Jason Zhao";
	char *str2 = "Chris Gregory";
	char *str3 = "Cam Averill";

	assert(set(hm, str1, (void *) 1) == 1);
	assert(load(hm) == (float) 0.01);
	assert(set(hm, str2, (void *) 2) == 1);
	assert(load(hm) == (float) 0.02);
	assert(set(hm, str3, (void *) 3) == 1);
	assert(load(hm) == (float) 0.03);

	assert(set(hm, str1, (void *) 1) == 0);
	assert(set(hm, str2, (void *) 2) == 0);
	assert(set(hm, str3, (void *) 3) == 0);
	assert(load(hm) == (float) 0.03);

	assert((int) get(hm, str1) == 1);
	assert((int) get(hm, str2) == 2);
	assert((int) get(hm, str3) == 3);
	assert(load(hm) == (float) 0.03);

	assert((int) get(hm, "random") == 0);

	assert((int) delete(hm, str1) == 1);
	assert((int) delete(hm, str1) == 0);
	assert(load(hm) == (float) 0.02);
	assert((int) delete(hm, str2) == 2);
	assert((int) delete(hm, str2) == 0);
	assert(load(hm) == (float) 0.01);
	assert((int) delete(hm, str3) == 3);
	assert((int) delete(hm, str3) == 0);
	assert(load(hm) == (float) 0);

	free(hm);

	fprintf(stderr, "Sanity Check Passed!\n");
}

int main() {
	sanitycheck();
	return 0;
}