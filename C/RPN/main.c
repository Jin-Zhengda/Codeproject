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
   int type;
   union
   {
      int ival;
      double dval;
   }dat;
}NodeType;
typedef struct stack
{
   NodeType data[N];
   int top;            //控制栈顶
}STACK;                 //栈的顺序存储

void Push(STACK* stack,NodeType data);
NodeType Pop(STACK* stack);
NodeType Op(NodeType d1,NodeType d2,int op);
NodeType OpData(NodeType* d1,NodeType* d2,int op);

int main(void)
{
   char word[N];
   NodeType d1,d2,d3;
   int i;
   STACK stack;
   stack.top=0;    //初始化栈顶
    
   while(scanf("%s",word)==1&&word[0]!='#')    //以空格为分隔符输入逆波兰表达式，以#结束
   {
         if(isdigit(word[0]))    //若为数字，则转化为整形后压栈
         {
            d1.type=0;
            for(i=0;i<strlen(word);i++)
            {
               if(word[i]=='.')
               {
                  d1.type=1;
               }
            }
            if(d1.type==0)
            {
               d1.dat.ival=atoi(word); //将word转换为整型数据
            }
            else
            {
               d1.dat.dval=atof(word);
            }
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
   if(d1.type==0)
   {
      printf("%d\n",d1.dat.ival);
   }
   else
   {
      printf("%f\n",d1.dat.dval);
   }
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

NodeType Op(NodeType d1,NodeType d2,int op)    //对数据d1和d2执行运算op，并返回计算结果
{
    NodeType res;
    if(d1.type==0&&d2.type==0)
    {
      res.type=0;
      switch(op)
      {
         case '+':
               res.dat.ival=d1.dat.ival+d2.dat.ival;
               break;
         case '-':
               res.dat.ival=d1.dat.ival-d2.dat.ival;
               break;
         case '*':
               res.dat.ival=d1.dat.ival*d2.dat.ival;
               break;
         case '/':
               res.dat.ival=d1.dat.ival/d2.dat.ival;
               break;
      }
   }
   else if(d1.type==0&&d2.type==1)
   {
      res.type=1;
      switch(op)
      {
         case '+':
               res.dat.dval=d1.dat.ival+d2.dat.dval;
               break;
         case '-':
               res.dat.dval=d1.dat.ival-d2.dat.dval;
               break;
         case '*':
               res.dat.dval=d1.dat.ival*d2.dat.dval;
               break;
         case '/':
               res.type=0;
               res.dat.ival=d1.dat.ival/(int)d2.dat.dval;
               break;
      }
   }
   else if(d1.type==1&&d2.type==0)
   {
      res.type=1;
      switch(op)
      {
         case '+':
               res.dat.dval=d1.dat.dval+d2.dat.ival;
               break;
         case '-':
               res.dat.dval=d1.dat.dval-d2.dat.ival;
               break;
         case '*':
               res.dat.dval=d1.dat.dval*d2.dat.ival;
               break;
         case '/':
               res.type=0;
               res.dat.ival=d1.dat.dval/d2.dat.ival;
               break;
      }
   }
   else
   {
      res.type=1;
      switch(op)
      {
         case '+':
               res.dat.dval=d1.dat.dval+d2.dat.dval;
               break;
         case '-':
               res.dat.dval=d1.dat.dval-d2.dat.dval;
               break;
         case '*':
               res.dat.dval=d1.dat.dval*d2.dat.dval;
               break;
         case '/':
               res.type=0;
               res.dat.ival=(int)d1.dat.dval/(int)d2.dat.dval;
               break;
      }
   }
   return res;
}

NodeType OpData(NodeType* d1,NodeType* d2,int op)   //对d1和d2执行运算op，并返回计算结果
{
    NodeType res;
    res=Op(*d1,*d2,op);
    return res;
}