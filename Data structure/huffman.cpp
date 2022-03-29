#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define maxnumber 10000000
typedef struct art
{
    char *code;
    char letter;
    int num;
} ART, *INK;
typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;
typedef char **HuffmanCode;
void PutArticle()
{
    FILE *fp;
    char ch = '0';
    if ((fp = fopen("article.txt", "w")) == NULL) //打开文件，不存在此文件则新建
    {
        fp = fopen("article.txt", "w");
    }
    printf("Please enter a paragraph in English and end with #\n");
    while (ch != '#')
    {
        ch = getchar();
        fputc(ch, fp);
    }
    fclose(fp);
}
int SearchArticle(INK &p, int &n)
{
    FILE *fp;
    int i, k;
    char *INK, ch = '0';
    if ((fp = fopen("article.txt", "r")) == NULL) //打开文件
    {
        printf("\n 记录文件不存在!");
        exit(0);
    }
    while (ch != '#')
    {
        ch = fgetc(fp);
        if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
        {
            for (i = 0, k = 0; i <= n; i++)
            {
                if (ch == p[i].letter)
                {
                    p[i].num++;
                    k = 1;
                }
            }
            if (k == 0)
            {
                p[n].letter = ch;
                p[n].num = 1;
                n++;
            }
        }
    }
    fclose(fp);
    return 0;
}
int *CreatW(int n, INK p)
{
    int *w = (int *)malloc((n) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        w[i] = p[i].num;
    }
    return w;
}
void select(HTNode *HT, int n, int &s1, int &s2)
{
    int min = maxnumber;
    int min2 = maxnumber + 1;
    int p, q;
    for (int i = 1; i <= n; i++)
    {
        if (HT[i].parent == 0)
        {
            if (HT[i].weight <= min && HT[i].weight < min2)
            {
                min2 = min;
                min = HT[i].weight;
                q = p;
                p = i;
            }
            if (HT[i].weight < min2 && HT[i].weight > min)
            {
                min2 = HT[i].weight;
                q = i;
            }
        }
    }
    s1 = p;
    s2 = q;
}
void HuffmanCreat(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1, s1 = 0, s2 = 0;
    int i;
    HTNode *p;
    HT = (HTNode *)malloc((m + 1) * sizeof(HTNode)); //因为为了号码方便，第 0 号不用
    p = HT;
    for (i = 1; i <= n; ++i)
        p[i] = {w[i - 1], 0, 0, 0};
    for (; i <= m; ++i)
        p[i] = {0, 0, 0, 0};
    for (i = n + 1; i <= m; ++i)
    {
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0'; //字符串结尾标志
    for (int i = 1; i <= n; ++i)
    {
        int start = n - 1; //编码中的倒数第二位
        for (int c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char)); //1.防止浪费过多空间 2.编码中没有赋值的不用输出
        strcpy(HC[i], &cd[start]);
    }
    free(cd); //动态存储记得 free
}
void CodeArticle(char *a, int n, INK p)
{
    FILE *fp1, *fp2;
    int i;
    fp1 = fopen("article.txt", "r");
    if ((fp2 = fopen("barticle.txt", "w")) == NULL)
    {
        fp2 = fopen("barticle.txt", "w");
    }
    char ch = fgetc(fp1);
    while (ch != '#')
    {
        for (i = 0; i < n; i++)
            if (ch == p[i].letter)
                break;
        if (i < n)
        {
            fprintf(fp2, "%s", p[i].code);
        }
        else
        {
            fputc(ch, fp2);
        }
        ch = fgetc(fp1);
    }
    fputc('#', fp2);
    fclose(fp1);
    fclose(fp2);
}
void TransCode(HuffmanTree HT, int n, INK p) //依次读入电文，根据哈夫曼树译码
{
    printf("\nThe decoding results are as follows\n");
    char ch;
    int i = 2 * n - 1; //从根节点开始往下搜索
    FILE *fp = fopen("barticle.txt", "r");
    ch = fgetc(fp);
    while (ch != '#')
    {
        if (ch != '0' && ch != '1')
            printf("%c", ch);
        if (ch == '0')
            i = HT[i].lchild; //走向左孩子
        else if (ch == '1')
            i = HT[i].rchild;                       //走向右孩子
        if (HT[i].lchild == 0 && HT[i].lchild == 0) //tree[i]是叶结点
        {
            printf("%c", p[i - 1].letter);
            i = n * 2 - 1; //回到根结点
        }
        ch = fgetc(fp);
    }
    printf("\n");
    if (i != n * 2 - 1 && ch == '#') //电文读完，但尚未到叶子结点
        printf("\nERROR\n");         //输入电文有错
    fclose(fp);
} //decode
int main()
{
    INK p = (INK)malloc(52 * sizeof(ART));
    int n1 = 0;
    PutArticle();
    SearchArticle(p, n1);
    printf("Total number is:%d\n", n1);
    HuffmanTree HT;
    HuffmanCode HC;
    int s1, s2;
    int *w = CreatW(n1, p);
    FILE *fp2;
    HuffmanCreat(HT, HC, w, n1);
    printf("letter Weight encoing \n");
    for (int i = 0; i < n1; i++)
    {
        printf("%c\t", p[i].letter);
        printf("%d\t", p[i].num);
        p[i].code = HC[i + 1];
        printf("%s\n", p[i].code);
    }
    CodeArticle("article.txt", n1, p);
    TransCode(HT, n1, p);
    free(HT);
    free(HC);
    free(w);
    system("pause");
    return 0;
}