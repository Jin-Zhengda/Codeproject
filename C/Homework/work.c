//文曲星猜数
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


//评分排序并输出各个评委评分与平均分之差的和
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

// void Average(int score[][m], int aver[])                                        //去除一个最高分和一个最低分并计算平均分
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

// void DateSort(int input[], int onesnum[], int num)                         //对输入进行排序
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

// void Judge(int score[][m], int aver[], int deviation[])                  //计算每个评委评分与平均分之差的绝对值之和
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


// 冒泡排序
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


//计算40以内的数的阶乘
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


//计算矩阵乘法
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


//排序并插值
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


//报数游戏
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// 生成1~10的一个随机数
// int Rand(void)
// {
//     srand((unsigned int)time(NULL));
//     return rand()%10+1;
// }

// 确定顺序
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

// 玩家与电脑依次报数
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


//输出杨辉三角形
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


//交换数组中的最大值和最小值
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


//计算日期
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


//计算定积分
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


//输出输入字符串中单词个数
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


//删去某一字符串中特定的字符
// #include <stdio.h>
// #define N 50

// void CutStr(char str[],char c)           //以数组为函数参数
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

// // void CutStr(char *pstr,char c)           //以指针为函数参数
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


//在每个字符间插入一个空格
// #include <stdio.h>
// #include <string.h>
// #define N 50

// // void SpaceStr(char str[])           //以数组为函数参数
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

// void SpaceStr(char *pstr)           //以指针为函数参数
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


//逆序输出字符串
// #include <stdio.h>
// #include <string.h>
// #define N 50

// void Reverse(char *dst,char *src)           //以指针为函数参数
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

// // void Reverse(char dst[],char src[])             //以数组为函数参数
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


//按照字典顺序对国家名进行排序
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
//     getchar();                                  //读走缓冲区的回车符
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


//查找星期表
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


//打印【1900，2099】间任一年的一月的星期表
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


//Pell数列
// #include <stdio.h>
// #define N 1000000
// #define M 32767
// int p[N+1]={0};

// void PellMod(int k)     //关键：(a+-b)%c=(a%c+-b%c)%c和(a*b)%c=(a%c*b%c)%c
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


//计算转置矩阵
// #include <stdio.h>
// #define N 100
// #define M 100

// void Transpose(int (*p)[N],int (*at)[M],int m,int n)    //行指针
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

// void Transpose(int *p,int *at,int m,int n)    //列指针
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

// void Transpose(int p[M][N],int at[N][M],int m,int n)    //数组
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


//动态数组输出最高分
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
//                 printf("%d班第%d个学生,分数为:%d\n",i+1,j+1,max);
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


//模拟扑克洗牌发牌
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #define N 10
// #define M 52
// #define A 4
// #define B 13

// typedef struct poker{
//     char suit[N];
//     char face[N];
// }Poker;

// char dst[][N]={"Spades","Hearts","Clubs","Diamonds"};
// char str[][B]={"A","1","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

// void InitializingPoker(Poker card[])
// {
//     int i,j,k;
//     i=j=k=0;
//     while(i<M)
//     {
//         if(k==13)
//         {
//             k=0;
//             j++;
//         }
//         strcpy(card[i].suit,dst[j]);
//         strcpy(card[i].face,str[k]);
//         i++;
//         k++;
//     }
// }

// void ShufflingPoker(Poker card[])
// {
//     int x,y;
//     int i;
//     for(i=0;i<60;i++)
//     {
//         srand((unsigned int)time(NULL));
//         x=rand()%52;
//         y=rand()%52;
//         Sleep(1000);
//         if(x!=y)
//         {
//             strcpy(card[x].suit,card[y].suit);
//             strcpy(card[x].face,card[y].face);
//         }
//         else 
//         {
//             continue;
//         }
//     }
// }

// void AssigningPoker(Poker card[])
// {
//     Poker* people[A][B]={NULL};
//     int i,j,k;
//     i=j=k=0;
//     while(i<M)
//     {
//         if(j==4)
//         {
//             k++;
//             j=0;
//         }
//         people[j][k]=&card[i];
//         i++;
//         j++;
//     }
//     printf("Assigning Result:\n");
//     for(i=0;i<A;i++)
//     {
//         printf("No.%d:\n",i+1);
//         for(j=0;j<B;j++)
//         {
//             printf("%-8s.%-8s",people[i][j]->suit,people[i][j]->face);
//             if(j%4==0)
//             {
//                 printf("\n");
//             }
//         }
//         printf("\n");
//     }
// }

// void PrintPoker(Poker card[])
// {
//     int i;
//     for(i=0;i<M;i++)
//     {
//         printf("%-8s.%-8s",card[i].suit,card[i].face);
//         if((i+1)%4==0)
//         {
//             printf("\n");
//         }
//     }
// }

// int main(void)
// {
//     Poker card[M];
//     InitializingPoker(card);
//     PrintPoker(card);
//     printf("\n\n");
//     printf("Shffle pokers now.Please wait sometime...\n\n");
//     ShufflingPoker(card);
//     PrintPoker(card);
//     printf("\n\n");
//     AssigningPoker(card);
//     return 0;
// }


// 模拟投票
// #include <stdio.h>
// #include <string.h>
// #define N 10

// typedef struct{
//     char name[N];
//     int p;
// }Candidate;

// int main(void)
// {
//     Candidate candidate[3]={{"zhang",0},{"li",0},{"wang",0}};
//     int i,j;
//     char name[N];
//     printf("Input:\n");
//     for(i=0;i<N;i++)
//     {
//         scanf(" %s",name);
//         for(j=0;j<3;j++)
//         {
//             if(!strcmp(name,candidate[j].name))
//             {
//                 candidate[j].p++;
//             }
//         }
//     }
//     printf("\n");
//     for(i=0;i<3;i++)
//     {
//         printf("%s\t",candidate[i].name);
//         printf(" %d\t\n",candidate[i].p);
//     }
//     return 0;
// }


//大数相加
// #include <stdio.h>
// #include <stdlib.h>
// #define N 50

// int ReadNumber(int* p)
// {   
//     int t[N]={0};
//     char ch;
//     int i=0,len=0;
//     do
//     {
//         ch=getchar();
//         t[i]=atoi(&ch);
//         i++;
//     }while(ch!='\n');
//     len=i-2;
//     for(i=i-2;i>=0;i--)
//     {
//         p[len-i]=t[i];
//     }
//     return len;
// }

// int Calculating(int* a,int* b,int* c,int x,int y)
// {
//     int m=(x>=y?x:y);
//     int i,flag=0;
//     for(i=0;i<=m+1;i++)
//     {
//         c[i]=c[i]+a[i]+b[i];
//         if(c[i]>=10)
//         {
//             c[i]=c[i]-10;
//             c[i+1]=c[i+1]+1;
//         }
//     }
//     for(i=N;i>=0;i--)
//     {
//         if(c[i]!=0)
//         {
//             flag=1;
//             return i+1;
//         }    
//     }
//     if(flag==0)
//     {
//         return 1;
//     }
// }

// int main(void)
// {   
//     int n,x,y;
//     int a[N]={0};
//     int b[N]={0};
//     int c[N+1]={0};
//     x=ReadNumber(a);
//     y=ReadNumber(b);
//     n=Calculating(a,b,c,x,y);
//     for(int i=n-1;i>=0;i--)
//     {
//         printf("%d",c[i]);
//     }
//     printf("\n");
//     return 0;
// }


//字符串数字提取
// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>
// #define N 100

// int main(void)
// {
//     char str[N]={0};
//     int t;
//     char* pstr=str;
//     printf("Input:\n");
//     scanf("%s",str);
//     while(*pstr!='\0')
//     {
//         if(isdigit(*pstr))
//         {
//             t=atoi(pstr);
//             printf("%10d\n",t);
//             while(isdigit(*pstr))
//             {
//                 pstr++;
//             }
//         }
//         pstr++;
//     }
//     return 0;
// }


//使用栈的顺序结构实现逆波兰表达式的计算
// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h>
// #define INT 1
// #define FlT 2
// #define N 20

// typedef struct node
// {  
//    int type;
//    union
//    {
//       int ival;
//       double dval;
//    }dat;
// }NodeType;
// typedef struct stack
// {
//    NodeType data[N];
//    int top;            //控制栈顶
// }STACK;                 //栈的顺序存储

// void Push(STACK* stack,NodeType data);
// NodeType Pop(STACK* stack);
// NodeType Op(NodeType d1,NodeType d2,int op);
// NodeType OpData(NodeType* d1,NodeType* d2,int op);

// int main(void)
// {
//    char word[N];
//    NodeType d1,d2,d3;
//    int i;
//    STACK stack;
//    stack.top=0;    //初始化栈顶
    
//    while(scanf("%s",word)==1&&word[0]!='#')    //以空格为分隔符输入逆波兰表达式，以#结束
//    {
//          if(isdigit(word[0]))    //若为数字，则转化为整形后压栈
//          {
//             d1.type=0;
//             for(i=0;i<strlen(word);i++)
//             {
//                if(word[i]=='.')
//                {
//                   d1.type=1;
//                }
//             }
//             if(d1.type==0)
//             {
//                d1.dat.ival=atoi(word); //将word转换为整型数据
//             }
//             else
//             {
//                d1.dat.dval=atof(word);
//             }
//             Push(&stack,d1);
//          }
//          else                    //否则弹出两个操作数，执行相应的运算后再将结果压栈
//          {
//             d2=Pop(&stack);
//             d1=Pop(&stack);
//             d3=OpData(&d1,&d2,word[0]); //执行运算
//             Push(&stack,d3);            //运算结果压入堆栈
//          }
//    }
//    d1=Pop(&stack);     //弹出栈顶保存的最终计算结果
//    if(d1.type==0)
//    {
//       printf("%d\n",d1.dat.ival);
//    }
//    else
//    {
//       printf("%f\n",d1.dat.dval);
//    }
//     return 0;
// }

// void Push(STACK* stack,NodeType data)   //将数据data压入堆栈
// {
//     memcpy(&stack->data[stack->top],&data,sizeof(NodeType));
//     stack->top=stack->top+1;    //改变栈顶指针
// }

// NodeType Pop(STACK* stack)      //弹出栈顶数据并返回
// {
//     stack->top=stack->top-1;
//     return stack->data[stack->top];
// }

// NodeType Op(NodeType d1,NodeType d2,int op)    //对数据d1和d2执行运算op，并返回计算结果
// {
//     NodeType res;
//     if(d1.type==0&&d2.type==0)
//     {
//       res.type=0;
//       switch(op)
//       {
//          case '+':
//                res.dat.ival=d1.dat.ival+d2.dat.ival;
//                break;
//          case '-':
//                res.dat.ival=d1.dat.ival-d2.dat.ival;
//                break;
//          case '*':
//                res.dat.ival=d1.dat.ival*d2.dat.ival;
//                break;
//          case '/':
//                res.dat.ival=d1.dat.ival/d2.dat.ival;
//                break;
//       }
//    }
//    else if(d1.type==0&&d2.type==1)
//    {
//       res.type=1;
//       switch(op)
//       {
//          case '+':
//                res.dat.dval=d1.dat.ival+d2.dat.dval;
//                break;
//          case '-':
//                res.dat.dval=d1.dat.ival-d2.dat.dval;
//                break;
//          case '*':
//                res.dat.dval=d1.dat.ival*d2.dat.dval;
//                break;
//          case '/':
//                res.type=0;
//                res.dat.ival=d1.dat.ival/(int)d2.dat.dval;
//                break;
//       }
//    }
//    else if(d1.type==1&&d2.type==0)
//    {
//       res.type=1;
//       switch(op)
//       {
//          case '+':
//                res.dat.dval=d1.dat.dval+d2.dat.ival;
//                break;
//          case '-':
//                res.dat.dval=d1.dat.dval-d2.dat.ival;
//                break;
//          case '*':
//                res.dat.dval=d1.dat.dval*d2.dat.ival;
//                break;
//          case '/':
//                res.type=0;
//                res.dat.ival=d1.dat.dval/d2.dat.ival;
//                break;
//       }
//    }
//    else
//    {
//       res.type=1;
//       switch(op)
//       {
//          case '+':
//                res.dat.dval=d1.dat.dval+d2.dat.dval;
//                break;
//          case '-':
//                res.dat.dval=d1.dat.dval-d2.dat.dval;
//                break;
//          case '*':
//                res.dat.dval=d1.dat.dval*d2.dat.dval;
//                break;
//          case '/':
//                res.type=0;
//                res.dat.ival=(int)d1.dat.dval/(int)d2.dat.dval;
//                break;
//       }
//    }
//    return res;
// }

// NodeType OpData(NodeType* d1,NodeType* d2,int op)   //对d1和d2执行运算op，并返回计算结果
// {
//     NodeType res;
//     res=Op(*d1,*d2,op);
//     return res;
// }


//记账系统
// #include <stdio.h>
// #include <string.h>
// #define N 10

// typedef struct 
// {
//     int ID;
//     char Username[N];
//     int income;
//     int expense;
// }Acount;

// int EmptyRecord(Acount acount[]);
// int InputRecord(Acount acount[]);
// void SortRecord(Acount acount[],int n);
// void SearchRecord(Acount acount[],int n);
// void AverageRecord(Acount acount[],int n,float* averincome,float* averexpense);
// void LargerRecord(Acount acount[],int n,float averexpense);
// void OutputRecord(Acount acount[],int n);
// void WrintFile(Acount acount[],int n);
// void ReadFile(Acount acount[],int n,FILE* fp);

// int main(void)
// {
//     Acount acount[N]={0};
//     char str[N];
//     float averincome;
//     float averexpense;
//     FILE* fp;
//     int flag,n;
//     do
//     {
//         printf("1.Input record\n");
//         printf("2.Sort and list records in reverse order by user name\n");
//         printf("3.Search records by user name\n");
//         printf("4.Calculate and list per capita income and expenses\n");
//         printf("5.List records which have more expenses than per capita expenses\n");
//         printf("6.List all records\n");
//         printf("7.Write to file\n");
//         printf("8.Read from file\n");
//         printf("0.Exit\n");
//         printf("Please enter your choice:");
//         scanf("%d",&flag);
//         switch(flag)
//         {
//             case 0:
//                 break;
//             case 1:
//                 n=InputRecord(acount);
//                 break;
//             case 2:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 SortRecord(acount,n);
//                 break;
//             case 3:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 SearchRecord(acount,n);
//                 break;
//             case 4:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 AverageRecord(acount,n,&averincome,&averexpense);
//                 printf("Per capita income:%.2f\n",averincome);
//                 printf("Per capita expenses:%.2f\n",averexpense);
//                 break;
//             case 5:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 LargerRecord(acount,n,averexpense);
//                 break;
//             case 6:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 OutputRecord(acount,n);
//                 break;
//             case 7:
//                 if(!EmptyRecord(acount))
//                 {
//                     break;
//                 }
//                 WrintFile(acount,n);
//                 break;
//             case 8:
//                 printf("Please input the file name:");
//                 scanf("%s",str);
//                 fp=fopen(str,"r");
//                 if(fp==NULL)
//                 {
//                     printf("Cannot find this file!\n");
//                     break;
//                 }
//                 ReadFile(acount,n,fp);
//                 break;
//             default:
//                 printf("Input Error!\n");
//                 break;
//         }
//         printf("\n");
//     } while (flag!=0);
//     return 0;
// }

// int EmptyRecord(Acount acount[])
// {
//     int flag=1;
//     if(acount[0].ID==0)
//     {
//         printf("There is no data yet. Please choose 1 or 8 to input the data first.\n");
//         flag=0;
//     }
//     return flag;
// }

// int InputRecord(Acount acount[])
// {
//     int i,n;
//     printf("Input the total of people:");
//     scanf("%d",&n);
//     while(n<=0||n>=10)
//     {
//         if(n>=10)
//         {
//             printf("The system can only store the information of 10 people at most. Please re-enter.\n");           
//         }
//         else
//         {
//             printf("The system can only store the information of 1 people at least. Please re-enter.\n");
//         }
//         printf("\nInput the total of people:");
//         scanf("%d",&n);
//     }
//     printf("Please input user's ID, name, income and expenses: (format as:10001 Cindy 6000 1500)\n");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&acount[i].ID);
//         scanf(" %s",acount[i].Username);
//         scanf("%d",&acount[i].income);
//         scanf("%d",&acount[i].expense);
//     }
//     return n;
// }

// void SortRecord(Acount acount[],int n)
// {
//     Acount* pstr[N]={NULL};
//     Acount t;
//     int i,j;
//     for(i=0;i<n;i++)
//     {
//         pstr[i]=&acount[i];
//     }
//     for(i=0;i<n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             if(strcmp(pstr[i]->Username,pstr[j]->Username)<=0)
//             {
//                 t=*pstr[i];
//                 *pstr[i]=*pstr[j];
//                 *pstr[j]=t;
//             }
//         }
//     }
//     printf("ID\tUserName\tIncome\tExpenses\t\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d\t%s\t\t%d\t%d\t\n",pstr[i]->ID,pstr[i]->Username,pstr[i]->income,pstr[i]->expense);
//     }
// }

// void SearchRecord(Acount acount[],int n)
// {
//     char name[N]={0};
//     int i,find=0;
//     printf("Please input the user name:");
//     scanf(" %s",name);
//     for(i=0;i<n;i++)
//     {
//         if(strcmp(acount[i].Username,name)==0)
//         {
//             printf("ID\tUserName\tIncome\tExpenses\t\n");
//             printf("%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
//             find=1;
//         }
//     }
//     if(!find)
//     {
//         printf("Not Found!\n");
//     }
// }

// void AverageRecord(Acount acount[],int n,float* averincome,float* averexpense)
// {
//     float sum1=0,sum2=0;
//     int i;
//     for(i=0;i<n;i++)
//     {
//         sum1=sum1+(float)acount[i].income;
//         sum2=sum2+(float)acount[i].expense;
//     }
//     *averincome=sum1/n;
//     *averexpense=sum2/n;
// }

// void LargerRecord(Acount acount[],int n,float averexpense)
// {
//     int i;
//     printf("ID\tUserName\tIncome\tExpenses\t\n");
//     for(i=0;i<n;i++)
//     {
//         if(acount[i].expense>averexpense)
//         {          
//             printf("%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
//         }
//     }
// }

// void OutputRecord(Acount acount[],int n)
// {
//     Acount* pstr[N]={NULL};
//     Acount t;
//     int i,j;
//     for(i=0;i<n;i++)
//     {
//         pstr[i]=&acount[i];
//     }
//     for(i=0;i<n-1;i++)
//     {
//         for(j=i+1;j<n;j++)
//         {
//             if(pstr[i]->ID>=pstr[j]->ID)
//             {
//                 t=*pstr[i];
//                 *pstr[i]=*pstr[j];
//                 *pstr[j]=t;
//             }
//         }
//     }
//     printf("ID\tUserName\tIncome\tExpenses\t\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d\t%s\t\t%d\t%d\t\n",pstr[i]->ID,pstr[i]->Username,pstr[i]->income,pstr[i]->expense);
//     }
// }

// void WrintFile(Acount acount[],int n)
// {
//     char str[N];
//     FILE* fp;
//     int i;
//     printf("Please input the file name:");
//     scanf("%s",str);
//     fp=fopen(str,"w");
//     fprintf(fp,"ID\tUserName\tIncome\tExpenses\t\n");
//     for(i=0;i<n;i++)
//     {
//         fprintf(fp,"%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
//     }
//     printf("Save Successfully!\n");
//     fclose(fp);
// }

// void ReadFile(Acount acount[],int n,FILE* fp)
// {
//     int i;
//     for(i=0;i<n;i++)
//     {
//         fscanf(fp,"%d %s %d %d",&acount[i].ID,acount[i].Username,&acount[i].income,&acount[i].expense);
//     }
//     printf("ID\tUserName\tIncome\tExpenses\t\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d\t%s\t\t%d\t%d\t\n",acount[i].ID,acount[i].Username,acount[i].income,acount[i].expense);
//     }
//     fclose(fp);
// }