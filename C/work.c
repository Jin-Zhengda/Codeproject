//�����ǲ���
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define N 4

// void GuessNumber(int a[],int n)
// {
//     int i, j, x, y, cnt, find;
//     int b[N] = {0};
//     cnt = find = 0;
    
//     printf("Start:\n");
//     do{
//         x = y = 0;
        
//         for(i = 0; i < N; i++)
//         {
//             scanf("%d", &b[i]);
//         }
//         cnt++;
        
//         for(i = 0; i < N; i++)
//         {
//             if(a[i] == b[i])
//             {
//                 x++;
//             }
//             for(j = 0; j < N; j++)
//             {
//                 if(a[i] == b[j]&&i!= j)
//                 {
//                     y++;
//                 }
//             }
//         }
//         if(x == 4)
//         {
//             printf("Congratulations!\n");
//             find = 1;
//         }
//         else 
//         {
//             printf("%dA%dB\n", x, y);
//         }
//     }while(cnt <= n);
    
//     if(!find)
//     {
//         printf("You haven't guess the right number!");
//     }
// }

// int main()
// {
//     int a[N] = {0};
//     int i, flag, n;
//     srand((unsigned int)time(NULL));
    
//     do{
//         for(i = 0; i < N; i++)
//         {
//             a[i] = rand() % 10;
//         }
//         flag = (a[0]!= a[1]&&a[0]!= a[2]&&a[0]!= a[3]&&a[1]!= a[2]&&a[1]!= a[3]&&a[2]!= a[3]&&a[0]!= 0);
//     }while(!flag);
    
//     printf("Iuput n:");
//     scanf("%d", &n);
//     GuessNumber(a, n);
    
//     return 0;
// }


//�����������������ί������ƽ����֮��ĺ�
// #include <stdio.h>
// #include <math.h>
// #define n 3
// #define m 5

// void ReadNumber(int number[], int num)
// {
//     int i;
//     for (i = 0; i < num; i++)
//     {
//         number[i] = i + 1;
//     }
// }

// void ReadScore(int score[][m])                                                    
// {
//     int i, j;
//     for (i = 0; i < n; i++)
//     {
//         printf("Input No.%d's score:\n", i + 1);
//         for (j = 0; j < m; j++)
//         {
//             scanf("%d", &score[i][j]);
//         }
//     }
// }

// void Average(int score[][m], int aver[])                                        //ȥ��һ����߷ֺ�һ����ͷֲ�����ƽ����
// {
//     int i, j,max, min;
//     for (i = 0; i < n; i++)
//     {
//         max = score[i][0];
//         min = score[i][0];
//         for (j = 0; j < m; j++)
//         {
//             if (max < score[i][j])
//             {
//                 max = score[i][j];
//             }
//             if (min > score[i][j])
//             {
//                 min = score[i][j];
//             }
//         }
//     }
//     for (i = 0; i < n; i++)
//     {
//         for (j = 0; j < m; j++)
//         {
//             aver[i] = aver[i] + score[i][j];
//         }
//         aver[i] = (aver[i] - max - min) / (m - 2);
//     }
// }

// void DateSort(int input[], int onesnum[], int num)                         //�������������
// {
//     int i, j, t1, t2;
//     for (i = 0; i < num - 1; i++)
//     {
//         for (j = i + 1; j < num; j++)
//         {
//             if (input[j] > input[i])
//             {
//                 t1 = input[j];
//                 input[j] = input[i];
//                 input[i] = t1;

//                 t2 = onesnum[j];
//                 onesnum[j] = onesnum[i];
//                 onesnum[i] = t2;
//             }
//         }
//     }
// }

// void Judge(int score[][m], int aver[], int deviation[])                  //����ÿ����ί������ƽ����֮��ľ���ֵ֮��
// {
//     int i, j;
//     for (j = 0; j < m; j++)
//     {
//         for (i = 0; i < n; i++)
//         {
//             deviation[j] = deviation[j] + (fabs(score[i][j] - aver[i]));
//         }
//     }
// }

// void Print(int output[], int num)                                        
// {
//     int i;
//     for (i = 0; i < num; i++)
//     {
//         printf("%2d ", output[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int score[n][m] = {0};
//     int StuNum[n] = {0};
//     int JudNum[m] = {0};
//     int aver[n] = {0};
//     int deviation[m] = {0};

//     ReadNumber(StuNum, n);
//     ReadNumber(JudNum, m);
//     ReadScore(score);
//     Average(score, aver);
//     DateSort(aver, StuNum, n);
//     printf("Students:\n");
//     Print(StuNum, n);
//     Print(aver, n);
//     Judge(score, aver, deviation);
//     DateSort(deviation, JudNum, m);
//     printf("Judges:\n");
//     Print(JudNum, m);
//     Print(deviation, m);
//     return 0;
// }


// ð������
// #include <stdio.h>
// #define N 50

// void BubbleSort(int num[],int n)
// {
//     int i,t,flag;
//     do{
//         flag=0;
//         for(i=0;i<n-1;i++)
//         {
//             if(num[i+1]<num[i])
//             {
//                 t=num[i];
//                 num[i]=num[i+1];
//                 num[i+1]=t;
//             }
//         }
//         for(i=0;i<n-1;i++)
//         {
//             if(num[i+1]>=num[i])
//             {
//                 flag++;
//             }
//         }
//     }while(flag!=n-1);
// }

// int main()
// {
//     int num[N]={0};
//     int n,i;
//     n=0;
//     printf("Input numbers:\n");
//     for(i=0;i<N;i++)
//     {
//         scanf("%d",&num[i]);
//         if(num[i]>0)
//         {
//             n++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     BubbleSort(num,n);
//     printf("Result:\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d  ",num[i]);
//     }
//     return 0;
// }


//����40���ڵ����Ľ׳�
// #include <stdio.h>
// #define N 50

// int Fact(int num[],int n)
// {
//     int i,j,k,figure,cnt;
//     num[0]=1;
//     for(i=1;i<=n;i++)
//     {
//         for(j=N-1;j>=0;j--)
//         {
//             if(num[j]!=0)
//             {
//                 num[j]=num[j]*i;
//             }
//         }
//         for(k=0;k<N;k++)
//         {
//             while(num[k]>=10)
//             {
//                 figure=num[k]/10;
//                 num[k+1]=num[k+1]+figure;
//                 num[k]=num[k]-figure*10;
//             }
//         }
//     }
//     cnt=0;
//     for(i=N-1;;i--)
//     {
//         if(num[i]==0)
//         {
//             cnt++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     return N-cnt;
// }

// int main()
// {

//     int n,i,j,flag;

//     printf("Input the n:");
//     scanf("%d",&n);

//     for(i=1;i<=n;i++)
//     {
//         int num[N]={0};
//         flag = Fact(num, i);
//         printf("%d!=", i);
//         for (j = flag - 1; j >= 0; j--)
//         {
//             printf("%d", num[j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//�������˷�
// #include <stdio.h>
// #define ROW 2
// #define COL 3

// void MultiplyMatrix(int a[ROW][COL],int b[COL][ROW],int c[ROW][ROW])
// {
//     int i,j,k;
//     for(i=0;i<ROW;i++)
//     {
//         c[i][j]=0;
//         for(j=0;j<ROW;j++)
//         {
//             for (k = 0; k < COL; k++)
//             {
//                 c[i][j] = c[i][j] + a[i][k] * b[k][j];
//             }
//         }
//     }
// }

// void PrintMatrix(int a[ROW][ROW])
// {
//     int i,j;
//     for(i=0;i<ROW;i++)
//     {
//         for(j=0;j<ROW;j++)
//         {
//             printf("%6d",a[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     int a[ROW][COL],b[COL][ROW],c[ROW][ROW],i,j;
//     printf("Input 2*3 matrix a:\n");
//     for(i=0;i<ROW;i++)
//     {
//         for(j=0;j<COL;j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
//     }
//     printf("Input 3*2 matrix b:\n");
//     for(i=0;i<COL;i++)
//     {
//         for(j=0;j<ROW;j++)
//         {
//             scanf("%d",&b[i][j]);
//         }
//     }
//     MultiplyMatrix(a,b,c);
//     printf("Results:\n");
//     PrintMatrix(c);
//     return 0;
// }


//���򲢲�ֵ
// #include <stdio.h>
// #define N 50

// void DateSort(int num[],int n)
// {
//     int i,j,t;
//     for (i = 0; i < n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             if(num[j]>num[i])
//             {
//                 t=num[j];
//                 num[j]=num[i];
//                 num[i]=t;
//             }
//         }
//     }
// }

// void Inserting(int num[],int x,int n)
// {
//     int i,j;
//     for (i = 0; i < n; i++)
//     {
//         if(x<num[i]&&x>=num[i+1])
//         {
//             for (j = n - 1; j >i; j--)
//             {
//                 num[j + 1] = num[j];
//             }
//             num[i+1] = x;
//         }
//     }
// }

// int main()
// {
//     int num[N]={0};
//     int n,x,i;
//     n=0;
//     printf("Input numbers:\n");
//     for(i=0;i<N;i++)
//     {
//         scanf("%d",&num[i]);
//         if(num[i]>=0)
//         {
//             n++;
//         }
//         else
//         {
//             break;
//         }
//     }
//     printf("Input x:\n");
//     scanf("%d",&x);
//     DateSort(num,n);
//     Inserting(num,x,n);
//     printf("Result:\n");
//     for(i=0;i<=n;i++)
//     {
//         printf("%d  ",num[i]);
//     }
//     return 0;
// }


//������Ϸ
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// ����1~10��һ�������
// int Rand(void)
// {
//     srand((unsigned int)time(NULL));
//     return rand()%10+1;
// }

// ȷ��˳��
// int Order(void)
// {
//     int r,i;
//     r=Rand();

//     if(r<=5)
//     {
//         printf("Your order:1\n");
//         return 1;
//     }
//     else
//     {
//         printf("Computer's order:1\n");
//         return 0;
//     }
// }

// �����������α���
// int Progress(int first)
// {
//     int i=1;
//     do{                                                                     
//         if(first)                                                   
//         {
//             if((30-i)%3==1)
//             {
//                 printf("Computer's order:%d\n",i+1);
//                 i++;
//             }
//             else if((30-i)%3==2)
//             {
//                 printf("Computer's order:%d\n",i+1);
//                 printf("Computer's order:%d\n",i+2);
//                 i=i+2;
//             }
//             else 
//             {
//                 int ra;
//                 ra=Rand();
//                 if(ra<=5)
//                 {
//                     printf("Computer's order:%d\n",i+1);
//                     i++;
//                 }
//                 else 
//                 {
//                     printf("Computer's order:%d\n",i+1);
//                     printf("Computer's order:%d\n",i+2);
//                     i=i+2;
//                 }
//             }

//             if(i==30)
//             {
//                 return 0;
//             }

//             first=0; 
//         }
//         else
//         {   
//             int k;

//             printf("Your time/times(please input 1 or 2):");
//             scanf("%d",&k);

//             if(k==1)
//             {
//                 printf("Your order:%d\n",i+1);
//                 i++;
//             }
//             else
//             {
//                 printf("Your order:%d\n",i+1);
//                 printf("Your order:%d\n",i+2);
//                 i=i+2;
//             }
            
//             if(i==30)
//             {
//                 return 1;
//             }

//             first=1;
//         }
//     }while(i<=30);
// }
    

// int main()
// {
//     int first,out;

//     first=Order();
//     out=Progress(first);

//     if(out)
//     {
//         printf("You win!\n");
//     }
//     else
//     {
//         printf("You lose!\n");
//     }

//     return 0;
// }


//������������
// #include <stdio.h>
// #define N 10

// void YHTraingle(int n)
// {
//     int i,j;
//     int num[N][N]={0};
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(j==0||i==j)
//             {
//                 num[i][j]=1;
//             }
//             else if(j<i)
//             {
//                 num[i][j]=num[i-1][j]+num[i-1][j-1];
//             }
//         }
//     }
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<=i;j++)
//         {
//             printf("%d\t",num[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main(void)
// {
//     int n;
//     printf("Input n:");
//     scanf("%d",&n);
//     YHTraingle(n);
//     return 0;
// }


//���������е����ֵ����Сֵ
// #include <stdio.h>

// void Swap(int *x,int *y)
// {
//     int t;
//     t=*x;
//     *x=*y;
//     *y=t;
// }

// void Select(int a[],int *x,int *y)
// {
//     int max,min,i;
//     max=a[0];
//     min=a[0];
//     for(i=0;i<10;i++)
//     {
//         if(a[i]>=max)
//         {
//             max=a[i];
//             *x=i;
//         }
//         if(a[i]<=min)
//         {
//             min=a[i];
//             *y=i;
//         }
//     }
// }

// int main(void)
// {
//     int a[10]={0};
//     int i,m,n;
//     int *x=&m;
//     int *y=&n;
//     printf("Input:\n");
//     for(i=0;i<10;i++)
//     {
//         scanf("%d",&a[i]);
//     }
//     Select(a,x,y);
//     Swap(&a[m],&a[n]);
//     for(i=0;i<10;i++)
//     {
//         printf("%-3d",a[i]);
//     }
//     return 0;
// }


//��������
// #include <stdio.h>
// #include <stdlib.h>
// int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
// int b[]={31,29,31,30,31,30,31,31,30,31,30,31};

// int IsLeap(int year)
// {
//     if(year%4==0&&year%100!=0||year%400==0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int DayofYear(int year,int month,int day)
// {
//     int i,d;
//     d=0;
//     if(IsLeap(year))
//     {
//         for(i=0;i<month-1;i++)
//         {
//             d=d+b[i];
//         }
//         d=d+day;
//     }
//     else 
//     {
//         for(i=0;i<month-1;i++)
//         {
//             d=d+a[i];
//         }
//         d=d+day;   
//     }
//     return d;
// }

// void MonthDay(int year,int yearDay,int *pMonth,int *pDay)
// {
//     int i;
//     *pMonth=0;
//     if(IsLeap(year))
//     {
//         for(i=0;;i++)
//         {
//             if(yearDay>b[i])
//             {
//                 yearDay=yearDay-b[i];
//                 *pMonth=*pMonth+1;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         *pDay=yearDay;
//     }
//     else
//     {
//         for(i=0;;i++)
//         {
//             if(yearDay>a[i])
//             {
//                 yearDay=yearDay-a[i];
//                 *pMonth=*pMonth+1;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         *pDay=yearDay;
//     }
// }

// int main(void)
// {
//     int n,year,month,day,d,yearDay;
//     int *pMonth=&month;
//     int *pDay=&d;

//     printf("1.year/month/day->yearday\n");
//     printf("2.yearDay->year/month/day\n");
//     printf("3.Exit\n");
//     printf("Please enter your choice:");
//     scanf("%d",&n);
//     switch(n)
//     {
//         case 1:
//             printf("Please enter year,month&day:");
//             scanf("%d%d%d",&year,&month,&day);
//             d=DayofYear(year,month,day);
//             printf("%d.%d.%d is %d of %d",year,month,day,d,year);
//             break;
//         case 2:
//             printf("Please enter year&yearDay:");
//             scanf("%d%d",&year,&yearDay);
//             MonthDay(year,yearDay,pMonth,pDay);
//             printf("%d of %d is %d.%d.%d",yearDay,year,year,month,day);
//             break;
//         default:
//             exit(0);
//     }
//     return 0;
// }


//���㶨����
// #include <stdio.h>
// #define EPS 1e-3

// float y(float x)
// {
//     return x*x+1; 
// }

// float Integeral(float(*f)(float),float a,float b)
// {
//     float in;
//     in=0;
//     while (a<b)
//     {
//         in=in+((*f)(a)+(*f)(a+EPS))*EPS/2;
//         a=a+EPS;
//     }
//     return in;
// }

// int main(void)
// {
//     float a,b,in;
//     printf("Input a & b:");
//     scanf("%f%f",&a,&b);
//     in=Integeral(y,a,b);
//     printf("Result:%f",in);
//     return 0;
// }


//��������ַ����е��ʸ���
// #include <stdio.h>
// #include <ctype.h>
// #define N 50
// int main(void)
// {
//     char str[N];
//     int i,cnt;
//     cnt=0;
//     printf("Input:");
//     gets(str);
//     for(i=0;str[i]!='\0';i++)
//     {
//         if(isspace(str[i]))
//         {
//             if(isalpha(str[i+1]))
//             {
//                 cnt++;
//             }
//         }
//     }
//     printf("result:%d",cnt);
//     return 0;
// }


//ɾȥĳһ�ַ������ض����ַ�
// #include <stdio.h>
// #define N 50

// void CutStr(char str[],char c)           //������Ϊ��������
// {
//     int i,j;
//     for(i=0;str[i]!='\0';i++)
//     {
//         while(str[i]==c)
//         {
//             for(j=i;str[j]!='\0';j++)
//             {
//                 str[j]=str[j+1];
//             }
//         }
//     }
// }

// // void CutStr(char *pstr,char c)           //��ָ��Ϊ��������
// // {
// //     char *pt=NULL;
// //     for(;*pstr!='\0';pstr++)
// //     {
// //         while(*pstr==c)
// //         {
// //             pt=pstr;
// //             for(;*pt!='\0';pt++)
// //             {
// //                 *pt=*(pt+1);
// //             }
// //         }
// //     }
// // }

// int main(void)
// {
//     char str[N];
//     char c;
//     printf("Input the str:");
//     gets(str);
//     printf("Input the c:");
//     scanf("%c",&c);
//     CutStr(str,c);
//     puts(str);
//     return 0;
// }


//��ÿ���ַ������һ���ո�
// #include <stdio.h>
// #include <string.h>
// #define N 50

// // void SpaceStr(char str[])           //������Ϊ��������
// // {
// //     int i,j,k;
// //     char tem[N];
// //     strcpy(tem,str);
// //     for(i=2;tem[i/2]!='\0';i=i+2)
// //     {
// //         for(j=i,k=j/2;tem[k]!='\0';j++,k++)
// //         {
// //             str[j]=tem[k];
// //         }
// //     }
// //     for(i=1;str[i]!='\0'||str[i-1]!='\0'||str[i+1]!='\0';i=i+2)
// //     {
// //         str[i]=' ';
// //     }
// // }

// void SpaceStr(char *pstr)           //��ָ��Ϊ��������
// {
//     char *pt=pstr;
//     pstr++;
//     for(;*pstr!='\0';pstr=pstr+2)
//     {
//         while(*pt!='\0')
//         {
//             pt++;
//         }
//         for(;pt>=pstr;pt--)
//         {
//             *(pt+1)=*pt;
//         }
//         *pstr=' ';
//     }
// }

// int main(void)
// {
//     char str[N];
//     printf("Input:");
//     gets(str);
//     SpaceStr(str);
//     puts(str);
//     return 0;
// }


//��������ַ���
// #include <stdio.h>
// #include <string.h>
// #define N 50

// void Reverse(char *dst,char *src)           //��ָ��Ϊ��������
// {
//     int cnt,len;
//     cnt=0;
//     len=strlen(dst);
//     while(*dst!='\0')
//     {
//         dst++;
//     }
//     dst--;
//     do{
//         *src=*dst;
//         src++;
//         dst--;
//         cnt++;
//     }while(cnt<=len);
// }

// // void Reverse(char dst[],char src[])             //������Ϊ��������
// // {
// //     int len,i;
// //     len=strlen(dst);
// //     for(i=len-1;i>=0;i--)
// //     {
// //         src[i]=dst[len-i-1];
// //     }
// //     src[len+1]='\0';
// // }

// int main(void)
// {
//     char a[N],b[N];
//     printf("Input:  ");
//     gets(a);
//     Reverse(a,b);
//     printf("Result: ");
//     puts(b);
//     return 0;
// }


//�����ֵ�˳��Թ�������������
// #include <stdio.h>
// #include <string.h>
// #define N 150
// #define M 10

// void SortString(char str[][M],int n)
// {
//     int i,j;
//     char temp[M];
//     for(i=0;i<n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             if(strcmp(str[j],str[i])<0)
//             {
//                 strcpy(temp,str[i]);
//                 strcpy(str[i],str[j]);
//                 strcpy(str[j],temp);
//             }
//         }
//     }
// }

// int main(void)
// {
//     int i,n;
//     char name[N][M];
//     printf("How many countries?");
//     scanf("%d",&n);
//     getchar();                                  //���߻������Ļس���
//     printf("Input their names:\n");
//     for(i=0;i<n;i++)
//     {
//         gets(name[i]);
//     }
//     SortString(name,n);
//     printf("Result:\n");
//     for(i=0;i<n;i++)
//     {
//         puts(name[i]);
//     }
//     return 0;
// }


//�������ڱ�
// #include <stdio.h>
// #include <string.h>
// #define R 7
// #define C 10

// int DaySearch(char day[],int *pr)
// {
//     char week[R][C]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
//     int i,find;
//     find=0;
//     for(i=0;i<R;i++)
//     {
//         if(strcmp(day,week[i])==0)
//         {
//             *pr=i;
//             find=1;
//         }
//     }
//     return find;
// }

// int main(void)
// {
//     int n,r,find;
//     int *pr=&r;
//     char day[C];
//     printf("Please enter the day's name:");
//     gets(day);
//     find=DaySearch(day,pr);
//     if(find)
//     {
//         printf("The day's number is %d.\n",r);
//     }
//     else 
//     {
//         printf("Input erorr!\n");
//     }
//     return 0;
// }


//��ӡ��1900��2099������һ���һ�µ����ڱ�
// #include <stdio.h>
// #include <stdlib.h>

// int a[12]={31,29,31,30,31,30,31,31,30,31,30,31};
// int b[12]={31,28,31,30,31,30,31,31,30,31,30,31};

// int IsLeap(int year)
// {
//     if((year%4==0&&year%100!=0)||(year%400==0))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void PrintMonth(int year,int month)
// {
//     int i,sum,oneday;
//     sum=0;
//     for(i=1900;i<year;i++)
//     {
//         if(IsLeap(i))
//         {
//             sum=sum+366;
//         }
//         else
//         {
//             sum=sum+365;
//         }
//     }

//     if(IsLeap(year))
//     {
//         for(i=0;i<month-1;i++)
//         {
//             sum=sum+a[i];
//         }
//         oneday=sum%7;
//         if(oneday!=6)
//         {
//             for(i=0;i<=oneday;i++)
//             {
//                 printf("\t");
//             }
//         }
//         for(i=1;i<=a[month-1];i++)
//         {
//             if(i==6-oneday)
//             {
//                 printf("%d\t\n",i);
//             }
//             else if((i-6+oneday)%7==0)
//             {
//                 printf("%d\t\n",i);
//             }
//             else
//             {
//                 printf("%d\t",i);
//             }
//         }
//     }
//     else
//     {
//         for(i=0;i<month-1;i++)
//         {
//             sum=sum+b[i];
//         }
//         oneday=sum%7;
//         if(oneday!=6)
//         {
//             for(i=0;i<=oneday;i++)
//             {
//                 printf("\t");
//             }
//         }
//         for(i=1;i<=b[month-1];i++)
//         {
//             if(i==6-oneday)
//             {
//                 printf("%d\t\n",i);
//             }
//             else if((i-6+oneday)%7==0)
//             {
//                 printf("%d\t\n",i);
//             }
//             else
//             {
//                 printf("%d\t",i);
//             }
//         }
//     }

// }

// int main()
// {
//     int year,month;
//     scanf("%d%d",&year,&month);
//     printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
//     PrintMonth(year,month);
//     return 0;
// }


//Pell����
// #include <stdio.h>
// #define N 1000000
// #define M 32767
// int p[N+1]={0};

// void PellMod(int k)     //�ؼ���(a+-b)%c=(a%c+-b%c)%c��(a*b)%c=(a%c*b%c)%c
// {
//     int i;
//     p[0]=1;
//     p[1]=2;
//     for(i=2;i<k;i++)
//     {
//         p[i]=(2*p[i-1]%M+p[i-2]%M)%M;
//     }
// }

// int main(void)
// {
//     int i,n,k;
//     scanf("%d",&n);
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&k);
//         PellMod(k);
//         printf("%d\n",p[k-1]);
//     }
//     return 0;
// }


//����ת�þ���
// #include <stdio.h>
// #define N 100
// #define M 100

// void Transpose(int (*p)[N],int (*at)[M],int m,int n)    //��ָ��
// {
//     int i,j;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             *(at[j]+i)=*(p[i]+j);
//         }
//     }
// }

// void Transpose(int *p,int *at,int m,int n)    //��ָ��
// {
//     int i,j;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             at[j*M+i]=p[i*N+j];
//         }
//     }
// }

// void Transpose(int p[M][N],int at[N][M],int m,int n)    //����
// {
//     int i,j;
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             at[j][i]=p[i][j];
//         }
//     }
// }

// int main(void)
// {
//     int i,j,m,n;
//     int a[M][N]={0};
//     int b[N][M]={0};
//     printf("Input the m&n:");
//     scanf("%d%d",&m,&n);
//     printf("Input the Matrix:\n");
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             scanf("%d",&a[i][j]);
//         }
//     }
//     Transpose(a,b,m,n);
//     for(i=0;i<n;i++)
//     {
//         for(j=0;j<m;j++)
//         {
//             printf("%d ",b[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }


//��̬���������߷�
// #include <stdio.h>
// #include <stdlib.h>

// void MaxScore(int *p,int m,int n)
// {
//     int max,i,j;
//     printf("Input the score:\n");
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             scanf("%d",&p[i*n+j]);
//         }
//     }
//     max=p[0];
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(p[i*n+j]>max)
//             {
//                 max=p[i*n+j]; 
//             }
//         }
//     }
//     for(i=0;i<m;i++)
//     {
//         for(j=0;j<n;j++)
//         {
//             if(p[i*n+j]==max)
//             {
//                 printf("%d���%d��ѧ��,����Ϊ:%d\n",i+1,j+1,max);
//             }
//         }
//     } 
// }

// int main(int argc, char *argv[])
// {
//     int m,n;
//     int *p=NULL;
//     printf("Input m&n:");
//     scanf("%d%d",&m,&n);
//     p=(int *)calloc(m*n,sizeof(int));
//     if(p==NULL)
//     {
//         exit(1);
//     }
//     else
//     {
//         MaxScore(p,m,n);
//     }
//     free(p);
//     return 0;
// }


#include <stdio.h>

int main(int argc,char *argv[])
{
    return 0;
}