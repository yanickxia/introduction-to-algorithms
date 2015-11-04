#include <stdio.h>

struct queues{
	int data[10];
	int head;
	int tail;
	int length;
};

void check_safe(struct queues *q, int is_head, int is_tail){
	
	int tail = q->tail + is_tail;
	int head = q->head + is_head;
	int length = q->length;
	
	int r_tail = tail / length ;
	int r_head = head / length;
	
	int n_tail = tail % length;
	int n_head = head % length;
	
	if(r_tail - r_head > 1){
		printf("low flow");
		exit(0);
	}
	
	if(r_tail - r_head == 0 && n_tail == length	 - n_head	){
		printf("low flow 1");
		exit(0);
	}
	
	if(r_tail - r_head == 1 && n_tail == n_head - 1 ){
		printf("low flow 2");
		exit(0);
	}
}

void enqueues(struct queues *q, int x){
	check_safe(q,0,1);
	q->data[q->tail] = x;
	
	if(q->tail == q->length - 1){
		q->tail = 1;
	}else{
		q->tail += 1;
	}
}

int dequeues(struct queues *q){
	check_safe(q,1,0);
	
	int x = q->data[q->head];
	if(q->head == q->length - 1){
		q->head = 1;
	}else{
		q->head += 1;
	}
	
	return x;
}


int main(int argc, char *argv[])
{
	struct queues q = {
		{}, 0, 0, 10
	};
	
	int i = 0;
	for(; i < 10; i++){
		enqueues(&q, i + 1);
	}
	
	printf("dequenues is %d \n", dequeues(&q));
	printf("dequenues is %d \n", dequeues(&q));
	printf("dequenues is %d \n", dequeues(&q));
	
	
	return 0;
}