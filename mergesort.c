#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *arr, int begin, int mid, int end){
	int k = 0;
	int *tmp = malloc(sizeof(int) * (end - begin));

	int i = begin;
	int j = mid;
	while(i < mid || j < end){
		if(j < end && (i == mid || arr[i] > arr[j])){
			tmp[k] = arr[j];
			++j;
		}
		else{
			tmp[k] = arr[i];
			++i;
		}
		
		++k;
	}
	
	int n = 0;
	arr = arr + begin;
	while(n < k)
		*arr++ = tmp[n++];

	free(tmp);

}

void msort(int *arr, int begin, int end){
	if(end - begin == 1)
		return;

	msort(arr, begin, (begin + end) / 2);
	msort(arr, (begin + end) / 2, end);
	merge(arr, begin, (begin + end) / 2, end);
}

int isSorted(int *arr, int len){
	int i;
	for(i = 0; i < len - 1; i++){
		if(arr[i] > arr[i + 1])
			return 0;
	}

	return 1;
}

int main(){
	int len = 0;
	int size = 10001;
	int *arr = malloc(sizeof(int) * size);

	int i = 0;
	char c;
	char buff[100];
	while((c = fgetc(stdin)) != EOF){
		if(c == ' ' || c == '\n'){
			arr[len++] = atoi(buff);
			memset(buff, 0, 100);
			i = 0;
		}
		else
			buff[i++] = c;
		
		if(c == '\n')
			break;

		if(len == size)
			arr = realloc(arr, size *= 2);

	}
		
	msort(arr, 0, len);
	int n;
	for(n = 0; n < len; ++n)
		printf("%d ", arr[n]);
	
	printf("\n");
	return 0;
}
