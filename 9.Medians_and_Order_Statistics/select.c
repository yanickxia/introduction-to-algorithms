#include <stdio.h>
#include <string.h>


void exchange(int *heap, int i, int j)
{
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void printList(int *array, int size)
{
    int i = 0;
    for(; i<size; i++)
    {
        printf("%d ", array[i]);
    }
}

int find_min(int *arry, int size, int min_limt)
{
    int min = 9999999, i = 0;
    for(; i < size; i++)
    {
        if(arry[i] < min && arry[i] > min_limt)
        {
            min = arry[i];
        }
    }

    return min;
}

void select_sort(int *arry, int size)
{

    int min = -1;
    int cp_arry[size], i = 0;
    memcpy(cp_arry, arry, size * sizeof(int));

    for(; i < size; i++)
    {
        int j = 0;
        min =  find_min(cp_arry, size, min);
        arry[i] = min;
    }
}



int find_median(int *arry, int size)
{
    select_sort(arry, size);

    return arry[size / 2 + 1];
}

void spilt_to_5_list(int *arry, int size, int *list_head)
{
    int size_of_list;
    if(size % 5 == 0)
    {
        size_of_list = size/5;
    }
    else
    {
        size_of_list = size/5 + 1;
    }

    int i = 0,j = 0, k = 1;
    list_head[0] = &arry[0];
    while(i < size)
    {
        int list_point = &arry[i];

        if(j == size_of_list)
        {
            list_head[k] = list_point;
            k++;
            j = 0;
        }

        i++;
        j++;
    }

    if(k != 4)
    {
        list_head[4] = arry[size - 1];
    }
}

int divide_by_number(int *arry, int size, int number)
{
    int i = 0, j = size - 1, temp[size], k = 0;

    for(; k < size; k++)
    {
        if(arry[k] > number)
        {
            temp[i] = arry[k];
            i++;
        }
        else
        {
            temp[j] = arry[k];
            j--;
        }
    }

    temp[i] = number;
    memcpy(arry, temp, size * sizeof(int));

    return i;
}



int select(int *array, int size, int index)
{
    int spilt_list[5], i = 0, median_list[5], median_of_5;
    spilt_to_5_list(array, size, spilt_list);
    for(; i < 5; i++)
    {
        median_list[i] = find_median(spilt_list[i], 5);
        median_of_5 = find_median(median_list, 5);
    }

    int left = divide_by_number(array, size, median_of_5);

    if(left == index)
    {
        return median_of_5;
    }
    else if(left > index)
    {
        return select(array[left], left - size, left - index);
    }
    else
    {
        return select(array, size - left, size -index);
    }

}



int main(int argc, char *argv[])
{
    int array[] = {16,4,10,14,7,9,3,2,8,1};
    int arraySize = sizeof(array)/ sizeof(int);

    printf("midian %d", find_median(array, arraySize));

    return 0;
}
