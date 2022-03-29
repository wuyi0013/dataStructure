#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxlen 255
typedef struct
{
    char ch[maxlen];
    int length;    
}SqString;
//顺序串的初始化
void InitString(SqString &s)
{
    for(int i=1;i<maxlen;i++)
        s.ch[i]='\0';
    s.length=0;
}
//赋值操作(把串s赋值为chars)
bool StrAssign(SqString &s,char chars[])
{
    int i=0;
    int j=1;
    while(chars[i]!='\0')
        i++;
    if(i>maxlen-1)
        return false;
    for(j;j<=i;j++)
        s.ch[j]=chars[j-1];
    s.length=i;
    return true;
}
//复制操作（由串t复制得到串s）
bool StrCopy(SqString &s,SqString t)
{
    int i=1;
    for(i;i<=t.length;i++)
        s.ch[i]=t.ch[i];
    s.length=t.length;
    return true;
}
//判断空操作
bool EmptyString(SqString s)
{
    if(s.length==0)
        return true;
    else 
        return false;
}
//求串长度
int StrLength(SqString s)
{
    return s.length;
}
//清空操作，将串s清为空串
bool ClearString(SqString &s)
{
    for(int i=1;i<=s.length;i++)
        s.ch[i]='\0';
    s.length=0;
    return true;
} 
//销毁串s 回收存储空间
void DestoryString(SqString &s)
{
    s.length=0;
}
//串链接，用t返回s1和s2连接而成的串
bool Contact(SqString &t,SqString s1,SqString s2)
{
    if(s1.length+s2.length>maxlen)
        return false;
    int i=1;
    while(i<=s1.length)
    {
        t.ch[i]=s1.ch[i];
        i++;
    }
    for(i;i<=s1.length+s2.length;i++)
        t.ch[i]=s2.ch[i-s1.length];
    t.length=s1.length+s2.length;
    return true;
}
//输出串
void PrintString(SqString s)
{
    int i=1;
    while(i<=s.length)
    {
        printf("%c",s.ch[i]);
        i++;
    }
    printf("\n");
}
//求子串 用sub返回串s的第pos个字符起长度为len的子串
bool SubString(SqString &sub,SqString s,int pos,int len)
{
    if(pos+len-1>s.length||pos<1||pos>s.length||len<0)
        return false;
    for(int i=pos;i<=s.length;i++)
        sub.ch[i-pos+1]=s.ch[i];
    sub.length=len;
    return true;
}
//比较操作 若s>t则返回值>0 反之亦然
int StrCompare(SqString s,SqString t)
{
    for(int i=1;i<=s.length&&i<=t.length;i++)
    {
        if(s.ch[i]!=t.ch[i])
            return s.ch[i]-t.ch[i];
    }
    return s.length-t.length;
}
//定位操作，若主串s中存在与串t值相同的子串，则返回它在主串s中第一次出现的位置，否则函数值为0
int Index(SqString s,SqString t)
{
    int i=1,n=s.length,m=t.length;
    SqString sub;
    while (i<=n-m+1)
    {
        SubString(sub,s,i,m);
        if(StrCompare(sub,t)!=0)
            i++;
        else 
            return i;
    }
    return 0;
}
//定位操作
int index(SqString s,SqString t)
{
    int i=1;
    int j=1;
    while(i<=s.length&&j<=t.length)
    {
        if(s.ch[i]==t.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
    }
    if(j>t.length)
        return i-t.length;
    else
        return 0;
}
//KMP算法
int Index_KMP(SqString s,SqString t,int next[])
{
    int i=1;
    int j=1;
    while(i<=s.length&&j<=t.length)
    {
        if(j==0||s.ch[i]==t.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
    }
    if(j>t.length)
        return i-t.length;
    else
        return 0;
}
//求模式串的next数组
void GetNext(SqString s,int next[])
{
    int i=1;
    int j=0;
    next[1]=0;
    while(i<s.length)
    {
        if(j==0||s.ch[i]==s.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
//求模式串的nextval数组
void GetNextval(SqString s,int nextval[],int next[])
{
    nextval[1]=0;
    for(int j=2;j<=s.length;j++)
    {
        if(s.ch[next[j]]=s.ch[j])
            nextval[j]=nextval[next[j]];
        else
            nextval[j]=next[j];
    }
}
int main()
{
    SqString s,t,p,sub;
    char chars[]="abcd123";
    char a[]="123";
    InitString(s);
    InitString(t);
    InitString(p);
    InitString(sub);
    StrAssign(s,chars);
    PrintString(s);
    if(!EmptyString(s))
        printf("%d\n",StrLength(s));
    ClearString(s);
    printf("%d\n",StrLength(s));
    PrintString(s);
    StrAssign(s,chars);
    StrAssign(p,chars);
    Contact(t,s,p);
    PrintString(t);
    SubString(sub,t,3,4);
    PrintString(sub);
    printf("%d\n",StrCompare(s,p));
    StrAssign(s,a);
    printf("%d\n",Index(t,s));
    StrCopy(sub,t);
    PrintString(sub);
    char b[20];
    printf("PLease Input your chuan:\n");
    scanf("%s",b);
    StrAssign(s,b);
    PrintString(s);
    system("pause");//
}
/*int main()
{
    SqString s,t,p;
    char chars[]="abcd123";
    InitString(s);
    InitString(t);
    InitString(p);
    StrAssign(s,chars);
    StrAssign(p,chars);
    Contact(t,s,p);
    PrintString(t);
    system("pause");
}*/















