#include <stdio.h>

void swap1(int *arr, int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void swap2(int *arr, int i, int j){
	int mask = arr[i] ^ arr[j];
	arr[i] ^= mask;
	arr[j] ^= mask;
}

int partition(int *arr, int begin, int end){
	int pivot = arr[end - 1];
	int i, j, k;
	i = j = k = begin;

	for( ; k < end - 1; ++k){
		if(arr[k] < pivot){
			swap2(arr, i, j);
			++i;
		}

		++j;
	}

	swap2(arr, i, end - 1);
	return i;
}

void qs(int *arr, int begin, int end){
	if(end - begin < 2)
		return;
	
	int pivot = partition(arr, begin, end);
	qs(arr, begin, pivot);
	qs(arr, pivot + 1, end);
}

int main(){
	int arr[10] = {3,7,4,6,7,9,1,0,3,5};
	int len = sizeof(arr) / sizeof(int);
	qs(arr, 0, len);
	
	int i;
	for(i = 0; i < len; ++i)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}





