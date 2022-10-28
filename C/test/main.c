#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 50

int Levenshtein(char* str,char* dst);
int Min(int a,int b,int c);

int main(void)
{
    FILE* fp1;
    FILE* fp2;
    FILE* fp3;
    int ch,ch1,ch2;
    int i,j,n,min=0,cnt=0,f=1;
    char str[N]={0};
    char dst[N]={0};
    char temp[N]={0};
    int flag=1;
    ch=ch1=ch2=0;
    fp1=fopen("words.txt","r");
    fp2=fopen("vocabulary.txt","r");
    fp3=fopen("words_correct.txt","w");
    while(!feof(fp1))
    {
        
        do
        {
            ch=fgetc(fp1);
            printf("%c",ch);
            fputc(ch,fp3);
        } while (!(ch==' '||ch==-1));
        flag=1;
        while(flag)
        {
            for(i=0;i<N;i++)
            {
                str[i]=0;
            }
            i=0;

            do
            {
                ch1=fgetc(fp1);
                if(isalpha((char)ch1))
                {
                    str[i]=(char)ch1;
                    i++;
                }
                if((!isprint((char)ch1))&&ch1!='\n'&&ch1!=-1)
                {
                    while(ch1>=127||ch1<=64)
                    {
                        ch1 = fgetc(fp1);
                    }
                }
                if(ch1==' '||ch1=='\n'||ch1=='/'||ch1==-1)
                {
                    flag=0;
                }
            }while(flag);

            flag=1;
            while(!feof(fp2))
            {
                for(i=0;i<N;i++)
                {
                    dst[i]=0;
                }
                i=0;
                do
                {
                    ch2=fgetc(fp2);
                    if(isalpha((char)ch2))
                    {
                        dst[i]=(char)ch2;
                    }
                    i++;
                    if(ch2=='\n'||ch2==' '||ch2==-1)
                    {
                        flag=0;
                    }
                }while(flag);

                flag=1;

                for(i=0;i<strlen(dst);i++)
                {
                    if(dst[i]==' ')
                    {
                        f=0;
                        break;
                    }
                }

                if(f)
                {
                    cnt++;
                    if(cnt==1)
                    {
                        for(i=0;i<N;i++)
                        {
                            temp[i]=0;
                        }
                        min=Levenshtein(str,dst);
                        strcpy(temp,str);
                    }
                    n= Levenshtein(str,dst);
                    if(n==0)
                    {
                        strcpy(temp,str);
                        goto out;
                    }
                    else if(min>n)
                    {
                        min=n;
                        for(i=0;i<N;i++)
                        {
                            temp[i]=0;
                        }
                        strcpy(temp,dst);
                    }                  
                }   
            }  
            out:
            cnt=0;
            rewind(fp2);
            printf("%s",temp);
            fputs(temp,fp3);
            if(isprint((char)ch1)||ch1=='\n')
            {
                printf("%c",ch1);
                fputc(ch1,fp3);
            }
            if(ch1=='\n'||ch1==-1)
            {
                flag=0;
            }   
             
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}

int Levenshtein(char* str,char* dst)
{
    int distance[strlen(str)+1][strlen(dst)+1];
    int i,j;
    for(i=0;i<=strlen(dst);i++)
    {
        distance[0][i]=i;
    }
    for(i=0;i<=strlen(str);i++)
    {
        distance[i][0]=i;
    }
    for(i=1;i<=strlen(str);i++)
    {
        for(j=1;j<=strlen(dst);j++)
        {
            if(str[i-1]==dst[j-1])
            {
                distance[i][j]=Min(distance[i-1][j]+1,distance[i][j-1]+1,distance[i-1][j-1]);
            }
            else
            {
                distance[i][j]=Min(distance[i-1][j]+1,distance[i][j-1]+1,distance[i-1][j-1]+1);
            }
        }
    }
    return distance[strlen(str)][strlen(dst)];
}

int Min(int a,int b,int c)
{
    int min;
    if(a>=b)
    {
        min=b;
    }
    else
    {
        min=a;
    }
    if(c<=min)
    {
        min=c;
    }
    return min;
}