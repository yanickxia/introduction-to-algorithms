#include <stdio.h>

#define MAX_NUM 100 //max of element
#define PREV 0
#define KEY 1
#define NEXT 2
#define N 3


int find(int (*objects)[N], int key) {

    int n = 0;

    while (objects[n][KEY] != key) {
        n = objects[n][NEXT];

        if (n == 0) {
            return -1;
        }
    }

    return n;
}

int main(int argc, char const *argv[]) {

    int objects[MAX_NUM][N] = {{1, 2, 3}};

    printf("find it at %d", find(objects, 2));
    return 0;
}
