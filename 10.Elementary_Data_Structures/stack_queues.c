#include <stdio.h>

struct stack
{
    int data[10];
    int top;
};


int is_empty(struct stack *s)
{
    return s->top;
}

void push(struct stack *s, int x)
{
    s->data[s->top] = x;
    s->top += 1;
}

int pop(struct stack *s)
{
    s->top = s->top - 1;
    return s->data[s->top];
}

int dequeues(struct stack *src, struct	stack	*temp){
	
	while(!is_empty(src)){
		push(temp, pop(src));
	}
	
	int v = pop(temp);
	
	while(!is_empty(temp)){
			push(temp, pop(src));
	}
	
	return v;
}

void enqueues(struct stack *src, int x){
	push(src, x);
}



int main(int argc, char *argv[])
{
	
	return 0;
}