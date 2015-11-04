#include <stdio.h>

void printList(int *array, int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d ", array[i]);
    }
}

void exchange(int *heap, int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

int partition(int *arry, int p, int r)
{
    int x = arry[r - 1];
    int i = p - 1;
    int j = p;

    for(; j < r; j++)
    {
        if(arry[j] <= x)
        {
            i++;
            exchange(arry, i, j);
        }
    }
    exchange(arry, i+1, r - 1);

    return i;
}

int random_partition(int *arry, int p, int r)
{
    int random = rand() % (r - p);
    exchange(arry, p + random, r);

    return partition(arry, p, r);
}

int random_select(int *arry, int p, int r, int i)
{
    if(p == r)
    {
        return arry[p];
    }

    int q = random_partition(arry, p, r);
    int	k = q - p + 1;

    if(k == i)
    {
        return arry[q];
    }
    else if(i < k)
    {
        return random_select(arry, p, q - 1, i);
    }
    else
    {
        return random_select(arry, q + 1, r, i - k);
    }

}
int main(int argc, char *argv[])
{
    int array[] = {16,4,10,14,7,9,3,2,8,1};
    int arraySize = sizeof(array)/ sizeof(int);
    int i = 2;
    int i_value = random_select(array, 0, arraySize, i);
    printf("Array : index %d, value %d",i , i_value);

    return 0;
}