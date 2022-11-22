#include <stdio.h>
#include "Array.h"

extern Array a;

int main(int argc, char *argv[])
{
    int size,MoreSize,index,flag,n;
    int *p;
    flag=1;
    
    do{
        printf("1.Creat an array;\n");
        printf("2.Input numbers into the array;\n");
        printf("3.Use the number in the array:\n");
        printf("4.Inflate the array;\n");
        printf("5.Exit.\n");
        printf("Please enter the number to enter the operation:");
        scanf(" %d",&n);
        switch(n)
        {
            case 1:
                printf("Please input the size of the array you want to creat:");
                scanf("%d",&size);
                a=ArrayCreat(size);
                break;
            case 2:
                printf("Please Input numbers:\n");
                for(int i=0;i<ArraySize(&a);i++)
                {
                    scanf("%d",&a.array[i]);
                }
                break;
            case 3:
                printf("Please input which number you want to use:");
                scanf("%d",&index);
                p=ArrayAt(&a,index);
                printf("The %d number of the array is %d.\n",index,*p);
                break;
            case 4:
                printf("Please input the moresize you want:");
                scanf(" %d",&MoreSize);
                ArrayInflate(&a,MoreSize);
                break;
            default:
                flag=0;
                break;
        }
    }while(flag);
    ArrayFree(&a);
    return 0;
}