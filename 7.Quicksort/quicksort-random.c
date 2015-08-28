#include <stdio.h>
#include <stdlib.h>

void printList(int *array, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%d ", array[i]);
	}
}

void exchange(int *heap, int i, int j){
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

int partition(int *arry, int p, int r){
	int x = arry[r - 1];
	int i = p - 1;
	int j = p;
	
	for(; j < r; j++){
		if(arry[j] <= x){
			i++;
			exchange(arry, i, j);
		}
	}
	exchange(arry, i+1, r - 1);
		
	return i;	
}

int random_partition(int *arry, int p, int r){
	int random = rand() % (r - p);
	exchange(arry, p + random, r);
	
	return partition(arry, p, r);
}

void quick_sort(int *arry, int p, int r){
	if(p < r - 1){
		int q = partition(arry,p,r);
		quick_sort(arry, p, q);
		quick_sort(arry, q+1,r);
	}
}

int main(int argc, char *argv[])
{
	int array[] = {16,4,10,14,7,9,3,2,8,1};
	int arraySize = sizeof(array)/ sizeof(int);
	
	quick_sort(array, 0, arraySize);
	printList(array, arraySize);
	return 0;
}

