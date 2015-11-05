#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct link_list
{
    struct link_list *pre;
    struct link_list *next;
    int key;
};


struct link_list *list_search(struct link_list *root, int key)
{
    while (root->next != NULL && root->key != key)
    {
        root = root->next;
    }

    return root;
}



void list_insert(struct link_list *root, struct link_list *x)
{
    if(root->next != NULL)
    {
        x->next = root->next;
        root->next->pre = x;
    }
    root->next = x;
}



int main(int argc, char const *argv[])
{




    return 0;
}
