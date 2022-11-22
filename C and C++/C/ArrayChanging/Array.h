#ifndef _Array_H_
#define _Array_H_

#include <stdlib.h>
#define BLOCK 5

typedef struct{ 
    int *array;
    int size;
}Array;

Array a;

Array ArrayCreat(int size)
{
    Array a;
    a.array=(int*)malloc(size*sizeof(int));
    a.size=size;
    return a;
}

void ArrayFree(Array *a)
{
    free(a->array);
    a->size=0;
}

int ArraySize(const Array *a)
{
    return a->size;
}

void ArrayInflate(Array *a,int MoreSize)
{
    int i;
    int *t;
    t=(int*)malloc((a->size+MoreSize)*sizeof(int));
    for(i=0;i<a->size;i++)
    {
        t[i]=a->array[i];
    }
    for(i=a->size;i<a->size+MoreSize;i++)
    {
        t[i]=0;
    }
    free(a->array);
    a->array=t;
    a->size=a->size+MoreSize;
}

int* ArrayAt(Array *a,int index)
{
    if(index>a->size)
    {
        ArrayInflate(a,(index/BLOCK+1)*BLOCK-a->size);
    }
    return &(a->array[index]);
}

#endif