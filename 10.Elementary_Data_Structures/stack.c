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



int main(int argc, char const *argv[])
{

    struct stack s = {0, 0};
    printf("stack is empty %d \n", is_empty(&s));

    push(&s, 1);
    printf("stack is empty %d \n", is_empty(&s));

    printf("stack pop is %d \n", pop(&s));
    printf("stack is empty %d \n", is_empty(&s));

    return 0;
}
