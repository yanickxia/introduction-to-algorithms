#include<stdio.h>
#include<stddef.h>
#include <stdlib.h>

struct node {
	int n;
	struct node *left;
	struct node *right;
};

void walk_tree(struct node *root){
    if(root != NULL){
        walk_tree(root->left);
        printf(" %d ", root->n);
        walk_tree(root->right);
    }
}

struct node *tree_search(struct node *root, int k){
    if(root == NULL){
        return NULL;
    }

    if(root->n == k){
        return root;
    }else if(root->n > k){
        return tree_search(root->left, k);
    }

    return tree_search(root->right, k);
}

int tree_minimum(struct node *root){
    while(root != NULL){
        root = root->left;
    }
    return root->n;
}

int tree_maximum(struct node *root){
    while(root != NULL){
        root = root->right;
    }
    return root->n;
}

struct node *successor(struct node *root){
	
}

void tree_insert(struct node *root, int x){
    if(root != NULL){
        root = malloc(sizeof(struct node));
        root->n = x;
    }
    if(root->n == x){
        return;
    }else if(root->n > x){
        tree_insert(root->left, x);
    }else{
        tree_insert(root->right, x);
    }

}
//from a -> b
void dump_node(struct node *a, struct node *b){
    b->left = a->left;
    b->n = a->n;
    b->right = a->right;
}

void transplant(struct node *root, )

void tree_delete(struct node *root, int x){
    struct node *to_del = tree_search(root, x);
    if(to_del == NULL) return;

    if(to_del->left == NULL && to_del->right != NULL){
        dump_node(to_del->right, to_del);
    }else if(to_del->left != NULL && to_del->right == NULL){
        dump_node(to_del->left, to_del);
    }else if(to_del->left != NULL && to_del->right != NULL && to_del->right->left == NULL && to_del->right->right != NULL){
        to_del->n = to_del->right->n;
        to_del->right = to_del->right->right;
    }else{


    }


}

int main(){

}
