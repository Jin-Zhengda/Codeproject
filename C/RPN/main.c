//ʹ��ջ��˳��ṹʵ���沨�����ʽ�ļ���
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define INT 1
#define FlT 2
#define N 20

typedef struct node
{
    int ival;
}NodeType;
typedef struct stack
{
    NodeType data[N];
    int top;            //����ջ��
}STACK;                 //ջ��˳��洢

void Push(STACK* stack,NodeType data);
NodeType Pop(STACK* stack);
NodeType OpInt(int d1,int d2,int op);
NodeType OpData(NodeType* d1,NodeType* d2,int op);

int main(void)
{
    char word[N];
    NodeType d1,d2,d3;
    STACK stack;
    stack.top=0;    //��ʼ��ջ��
    
    while(scanf("%s",word)==1&&word[0]!='#')    //�Կո�Ϊ�ָ��������沨�����ʽ����#����
    {
        if(isdigit(word[0]))    //��Ϊ���֣���ת��Ϊ���κ�ѹջ
        {
            d1.ival=atoi(word); //��wordת��Ϊ��������
            Push(&stack,d1);
        }
        else                    //���򵯳�������������ִ����Ӧ��������ٽ����ѹջ
        {
            d2=Pop(&stack);
            d1=Pop(&stack);
            d3=OpData(&d1,&d2,word[0]); //ִ������
            Push(&stack,d3);            //������ѹ���ջ
        }
    }
    d1=Pop(&stack);     //����ջ����������ռ�����
    printf("%d\n",d1.ival);
    return 0;
}

void Push(STACK* stack,NodeType data)   //������dataѹ���ջ
{
    memcpy(&stack->data[stack->top],&data,sizeof(NodeType));
    stack->top=stack->top+1;    //�ı�ջ��ָ��
}

NodeType Pop(STACK* stack)      //����ջ�����ݲ�����
{
    stack->top=stack->top-1;
    return stack->data[stack->top];
}

NodeType OpInt(int d1,int d2,int op)    //������d1��d2ִ������op�������ؼ�����
{
    NodeType res;
    switch(op)
    {
        case '+':
            res.ival=d1+d2;
            break;
        case '-':
            res.ival=d1-d2;
            break;
        case '*':
            res.ival=d1*d2;
            break;
        case '/':
            res.ival=d1/d2;
            break;
    }
    return res;
}

NodeType OpData(NodeType* d1,NodeType* d2,int op)   //��d1��d2ִ������op�������ؼ�����
{
    NodeType res;
    res=OpInt(d1->ival,d2->ival,op);
    return res;
}