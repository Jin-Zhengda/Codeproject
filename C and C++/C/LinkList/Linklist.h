#ifndef _Linklist_H_
#define _Linklist_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct list{
    Node* head;
    Node* tail;
}List;

List list;

void AddLinklist(List* pList,int number)
{
    Node* p=(Node*)malloc(sizeof(Node));
    if(p==NULL)
    {
        printf("No enough memories!\n");
        exit(1);
    }
    else
    {
        p->value=number;
        p->next=NULL;
    }
    pList->tail=pList->head;
    if(pList->tail!=NULL)
    {
        while(pList->tail->next!=NULL)
        {
            pList->tail=pList->tail->next;
        }
        pList->tail->next=p;
    }
    else 
    {
        pList->head=p;
    }
}

void PrintLinklist(List* pList)
{
    Node* p;
    for(p=pList->head;p!=NULL;p=p->next)
    {
        printf("%d\t",p->value);
    }
    printf("\n");
}

void SearchLinklist(List* list,int number)
{
    Node* p;
    int find=0;
    int i=1;
    for(p=list->head;p!=NULL;p=p->next,i++)
    {
        if(p->value==number)
        {
            find=1;
            printf("Get it!No.%d\n",i);
            break;
        }
    }
    if(!find)
    {
        printf("Not Found!\n");
    }
}

void DeleteLinklist(List* pList,int number)
{
    Node* p=NULL;
    Node* pr=NULL;
    int find=0;
    for(p=pList->head;p!=NULL;pr=p,p=p->next)
    {
        if(p==NULL)
        {
            printf("Empty!\n");
            return;
        }
        else if(p->value==number)
        {
            if(pr!=NULL)
            {
                pr->next=p->next;
            }
            else
            {
                pList->head=p->next;
            }
            free(p);
            find=1;
            break;
        }
    }
    if(!find)
    {
        printf("Not Found!\n");
    }
}

void SortLinklist(List* pList)
{
    int t;
    Node* p;
    Node* pr;
    for(p=pList->head;p!=NULL;p=p->next)
    {
        for(pr=p->next;pr!=NULL;pr=pr->next)
        {
            if(p->value<=pr->value)
            {
                t=p->value;
                p->value=pr->value;
                pr->value=t;
            }
        }
    }

}

void InsertLinlist(List* pList,int number)
{
    Node* p=(Node*)malloc(sizeof(Node));
    Node* pr=NULL;
    if(p==NULL)
    {
        printf("No enough memories!\n");
        exit(1);
    }
    else
    {
        p->next=NULL;
        p->value=number;
    }
    if(pList->head==NULL)
    {
        pList->head=p;
    }
    else if(p->value>pList->head->value)
    {
        p->next=pList->head;
        pList->head=p;
    }
    else if(pList->tail->value>p->value)
    {
        pList->tail->next=p;
    }
    else
    {
        for(pr=pList->head;pr!=NULL;pr=pr->next)
        {
            if(pr->value>=p->value&&pr->next->value<=p->value)
            {
                p->next=pr->next;
                pr->next=p;
                break;
            }
        }
    }
}

void FreeLinklist(List* list)
{
    Node* p;
    while(list->head!=NULL)
    {
        p=list->head;
        list->head=list->head->next;
        free(p);
    }
}

#endif