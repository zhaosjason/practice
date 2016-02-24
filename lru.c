#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 20

int * inCache(int *cache, int len, int num){
	int i = 0;
	while(i < len){
		if(cache[i] == num){
			return &cache[i];
		}

		++i;
	}

	return 0;
}

void updateCache(int *cache, int *p, int len){
	int i = 0;
	while(i < len){
		if(cache[i] == *p){
			break;
		}

		++i;
	}

	int temp = *p;
	while(i < len){
		cache[i - 1] = cache[i];
		++i;
	}

	cache[i - 1] = temp;
}

void addToCache(int *cache, int len, int num){
	int i = 1;
	while(i < len){
		cache[i - 1] = cache[i];
		++i;
	}

	cache[i - 1] = num;
}

int lru(int cacheSize, int *pages, int len){
	int misses = 0;
	int *cache = malloc(sizeof(int) * cacheSize);

	int i = 0;
	while(i < len){
		int *p;
		if((p = inCache(cache, cacheSize, pages[i])) != 0){
			updateCache(cache, p, cacheSize);
		}
		else{
			/* element not found in cache */
			addToCache(cache, cacheSize, pages[i]);
			++misses;			
		}

		++i;
	}

	return misses;
}

int calculateMisses(int cacheSize, int *pages, int len){
	int misses = 0;

	int i = 0;
	while(i < len){
		int j = 1;
		while(j <= cacheSize && i - j >= 0){
			if(pages[i - j] == pages[i])
				goto end_for;

			++j;
		}

		/* element not in cache */
		++misses;

end_for:
		++i;
	}

	return misses;
}

int main(){
	int cacheSize = 3;
	int page[PAGE_SIZE] = {2, 3, 7, 3, 8, 4, 3, 5, 1, 0, 3, 8, 6, 2, 4, 3, 0, 9, 1, 8};

	printf("calculateMisses = %d\n", calculateMisses(cacheSize, page, PAGE_SIZE));
	printf("            lru = %d\n", lru(cacheSize, page, PAGE_SIZE));

	return 0;
}










