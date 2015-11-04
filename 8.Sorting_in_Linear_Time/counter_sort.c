#include <stdio.h>

void print_list(int *array, int size){
	int i = 0;
	for(;i<size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void init_list(int *array, int size){
	int i = 0;
	for(;i<size; i++){
		array[i] = 0;
	}	
}

void copy_list(int *from, int *to, int size){
	int i = 0;
	for(; i < size; i++){
		to[i] = from[i];
	}
}


void counter_sort(int *array, int size, int max){
	
	max += 1;
	int counter[max], sorted[size];
	init_list(counter, max);
	init_list(sorted, size);
	
	int i = 0;
	for(; i < size; i++){
		counter[array[i]] += 1;
	}
	
	i = 1;
	for(; i < max; i++){
		counter[i] += counter[i - 1];	
	}
	
	i = size;
	for(; i >= 0; i--){
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	copy_list(sorted, array, size);	
}



int main(int argc, char *argv[])
{
	int array[] = {16,4,10,14,7,9,3,2,8,1};
	int arraySize = sizeof(array)/ sizeof(int);
	
	counter_sort(array, arraySize, 16);
	print_list(array, arraySize);

	return 0;
}