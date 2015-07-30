#include <stdio.h>

#define PARENT(i) ((i + 1)/2 - 1)
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

void printList(int *array, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%d ", array[i]);
	}
	
	printf("\n");
}

void exchange(int *heap, int i, int j){
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void maxHeapify(int *heap,int heapSize, int i){
	int left = LEFT(i), right = RIGHT(i), largest;
	
	if(left < heapSize && heap[i] < heap[left]) 
		largest = left;
	else 
		largest = i;
	
	if(right < heapSize && heap[largest] < heap[right]) 
		largest = right;
	
	if (largest  != i) {
		exchange(heap, i, largest);
		maxHeapify(heap, heapSize, largest);
	} 
}

void buildMaxHeap(int *heap, int heapSize){
	int i = 0;
	for(; i < heapSize/ 2 + 1; i++){
		maxHeapify(heap, heapSize, i);
	}
}

void heapSort(int *heap, int heapSize){
	buildMaxHeap(heap, heapSize);
	int i = heapSize - 1;
	for(;i > 0; i--){
		exchange(heap, 0, i);
		heapSize--;
		maxHeapify(heap, heapSize, 0);
	}
}

int heapMaximum(int *heap){
	return heap[0];
}

int heapExtractMax(int *heap, int heapSize){
	if(heapSize < 1)
		exit(-1);
	int max = heap[0];
	exchange(heap, 0, heapSize - 1);
	heapSize--;
	
	maxHeapify(heap, heapSize, 0);
	
	return max;
}
/**
* update  item i, update value to key
*
*/
void heapIncreaseKey(int *heap, int i, int key){
	if(key < heap[i]){
		printf("new key smaller than current key");
		exit(-1);
	}	
	heap[i] = key;
	while (i > 0 && heap[PARENT(i)] < key){
		exchange(heap, i, PARENT(i));
		i = PARENT(i);
	}
}

void maxHeapInsert(int *heap, int heapSize, int key){
	heap[heapSize] = -1;
	heapIncreaseKey(heap, heapSize, key);
}

void maxHeapDel(int *heap, int heapSize, int i){
	exchange(heap, i, heapSize - 1);
	heapSize--;
	
	maxHeapify(heap, heapSize, i);	
}



int main(int argc, char *argv[])
{
	int heap[] = {16,4,10,14,7,9,3,2,8,1};
	int heapSize = sizeof(heap)/ sizeof(int);
	
	buildMaxHeap(heap, heapSize);
	
	printf("exect max key: %d \n", heapExtractMax(heap, heapSize--)); 
	printf("exect max key: %d \n", heapExtractMax(heap, heapSize--)); 
	printList(heap, heapSize);
	
	printf("update 4th item to 17, rebuild heap \n");
	heapIncreaseKey(heap, 3, 17);
	printList(heap, heapSize);
	
	printf("inset a key 24, rebuild it \n");
	maxHeapInsert(heap, heapSize++, 24);
	printList(heap, heapSize);
	
	printf("del 4th item, rebuild it \n");
	maxHeapDel(heap, heapSize--, 3);
	printList(heap, heapSize);
	
	return 0;
}

