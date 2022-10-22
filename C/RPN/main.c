//使用栈的顺序结构实现逆波兰表达式的计算
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
    int top;            //控制栈顶
}STACK;                 //栈的顺序存储

void Push(STACK* stack,NodeType data);
NodeType Pop(STACK* stack);
NodeType OpInt(int d1,int d2,int op);
NodeType OpData(NodeType* d1,NodeType* d2,int op);

int main(void)
{
    char word[N];
    NodeType d1,d2,d3;
    STACK stack;
    stack.top=0;    //初始化栈顶
    
    while(scanf("%s",word)==1&&word[0]!='#')    //以空格为分隔符输入逆波兰表达式，以#结束
    {
        if(isdigit(word[0]))    //若为数字，则转化为整形后压栈
        {
            d1.ival=atoi(word); //将word转换为整型数据
            Push(&stack,d1);
        }
        else                    //否则弹出两个操作数，执行相应的运算后再将结果压栈
        {
            d2=Pop(&stack);
            d1=Pop(&stack);
            d3=OpData(&d1,&d2,word[0]); //执行运算
            Push(&stack,d3);            //运算结果压入堆栈
        }
    }
    d1=Pop(&stack);     //弹出栈顶保存的最终计算结果
    printf("%d\n",d1.ival);
    return 0;
}

void Push(STACK* stack,NodeType data)   //将数据data压入堆栈
{
    memcpy(&stack->data[stack->top],&data,sizeof(NodeType));
    stack->top=stack->top+1;    //改变栈顶指针
}

NodeType Pop(STACK* stack)      //弹出栈顶数据并返回
{
    stack->top=stack->top-1;
    return stack->data[stack->top];
}

NodeType OpInt(int d1,int d2,int op)    //对数据d1和d2执行运算op，并返回计算结果
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

NodeType OpData(NodeType* d1,NodeType* d2,int op)   //对d1和d2执行运算op，并返回计算结果
{
    NodeType res;
    res=OpInt(d1->ival,d2->ival,op);
    return res;
}