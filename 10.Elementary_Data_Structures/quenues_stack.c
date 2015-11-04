#include <stdio.h>

struct queues{
	int data[10];
	int head;
	int tail;
	int length;
};

int is_empty(struct queues *q){
	
}

void enqueues(struct queues *q, int x){
	q->data[q->tail] = x;
	
	if(q->tail == q->length - 1){
		q->tail = 1;
	}else{
		q->tail += 1;
	}
}

int dequeues(struct queues *q){
	int x = q->data[q->head];
	if(q->head == q->length - 1){
		q->head = 1;
	}else{
		q->head += 1;
	}
	
	return x;
}

void push(struct queues *q, int x){
	enqueues(q, x);
}


int pop(struct queues *q, struct queues *p){
	while(!is_empty(q)){
		enqueues(p, dequeues(q));
	}
	
	int x = dequeues(p);
	
		
	while(!is_empty(p)){
		enqueues(q, dequeues(p));
	}
	
	
	return x;
}

int main(int argc, char *argv[])
{
	struct queues q = {
		0, 0, 0, 10
	};
	
	enqueues(&q, 1);
	enqueues(&q, 2);
	enqueues(&q, 3);
	
	printf("dequenues is %d \n", dequeues(&q));
	printf("dequenues is %d \n", dequeues(&q));
	printf("dequenues is %d \n", dequeues(&q));
	
	
	return 0;
}