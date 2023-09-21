#include <stdio.h>
#include "Linklist.h"

extern List list;

int main(void)
{
    list.head = list.tail = NULL;
    int number;
    printf("Please add numbers into the linklist:\n");
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            AddLinklist(&list, number);
        }
    } while (number != -1);

    printf("Result:\n");
    PrintLinklist(&list);

    SortLinklist(&list);
    printf("Sorting result:\n");
    PrintLinklist(&list);

    printf("Please enter the number you want to delete:\n");
    scanf(" %d", &number);
    DeleteLinklist(&list, number);
    printf("Deleting result:\n");
    PrintLinklist(&list);

    printf("Please enter the number you want to search:\n");
    scanf(" %d", &number);
    SearchLinklist(&list, number);

    printf("Please enter the number you want to insert:\n");
    scanf(" %d", &number);
    InsertLinlist(&list, number);
    printf("Inserting result:\n");
    PrintLinklist(&list);
    
    FreeLinklist(&list);
}
