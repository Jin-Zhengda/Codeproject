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
   int top;            //����ջ��
}STACK;                 //ջ��˳��洢

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
   stack.top=0;    //��ʼ��ջ��
    
   while(scanf("%s",word)==1&&word[0]!='#')    //�Կո�Ϊ�ָ��������沨�����ʽ����#����
   {
         if(isdigit(word[0]))    //��Ϊ���֣���ת��Ϊ���κ�ѹջ
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
               d1.dat.ival=atoi(word); //��wordת��Ϊ��������
            }
            else
            {
               d1.dat.dval=atof(word);
            }
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

NodeType Op(NodeType d1,NodeType d2,int op)    //������d1��d2ִ������op�������ؼ�����
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

NodeType OpData(NodeType* d1,NodeType* d2,int op)   //��d1��d2ִ������op�������ؼ�����
{
    NodeType res;
    res=Op(*d1,*d2,op);
    return res;
}