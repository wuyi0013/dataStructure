#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX 100
#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)  (sizeof(a)/sizeof(a[0]))

// 邻接表中表对应的链表的顶点
typedef struct _ENode
{
    int ivex;                   // 该边所指向的顶点的位置,是数组的下标
    struct _ENode *next_edge;   // 指向下一条弧的指针
}ENode, *PENode;

// 邻接表中表的顶点
typedef struct _VNode
{
    char data;              // 顶点信息
    ENode *first_edge;      // 指向第一条依附该顶点的弧
}VNode;

// 邻接表
typedef struct _LGraph
{
    int vexnum;             // 图的顶点的数目
    int edgnum;             // 图的边的数目
    VNode vexs[MAX];
}LGraph;
//返回ch在vexs数组下标
static int get_position(LGraph g, char ch)
{
    for(int i=0;i<g.vexnum;i++)
    {
        if(g.vexs[i].data==ch)
            return i;
    }
    return -1;
}
static void link_last(ENode *list, ENode *node)
{
    ENode *p=list;
    while(p->next_edge)
    {
        p=p->next_edge;
    }
    p->next_edge=node;
}
LGraph* create_example_lgraph_directed()
{
    char c1, c2;
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'}, 
        {'B', 'C'}, 
        {'B', 'E'}, 
        {'B', 'F'}, 
        {'C', 'E'}, 
        {'D', 'C'}, 
        {'E', 'B'}, 
        {'E', 'D'}, 
        {'F', 'G'}}; 
    int vlen=LENGTH(vexs);
    int elen=LENGTH(edges);
    int i,p1,p2;
    ENode *node1;
    LGraph* pG;
    if((pG=(LGraph*)malloc(sizeof(LGraph)))==NULL)//空间申请失败
        return NULL;
    memset(pG,0,sizeof(LGraph));//效果等同于calloc
    pG->edgnum=elen;
    pG->vexnum=vlen;
    for(i=0;i<pG->vexnum;i++) // 初始化"邻接表"的顶点
    {
        pG->vexs[i].data=vexs[i];
        pG->vexs[i].first_edge=NULL;
    }
    for(i=0;i<pG->edgnum;i++)
    {
        c1=edges[i][0];// 读取边的起始顶点和结束顶点
        c2=edges[i][1];
        p1=get_position(*pG,c1);
        p2=get_position(*pG,c2);
        node1=(ENode*)calloc(1,sizeof(ENode));
        node1->ivex=p2;
        if(pG->vexs[p1].first_edge==NULL)
            pG->vexs[p1].first_edge=node1;
        else
            link_last(pG->vexs[p1].first_edge,node1);
    }
    return pG;
}
void BFS(LGraph G)
{
    int head=0;
    int rear=0;
    int queue[MAX];
    int visited[MAX];
    int i,j,k;
    ENode* node;
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=0;
    }
    printf("BFS: ");
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            printf("%c ",G.vexs[i].data);
            queue[rear++]=i;
        }
        while(head!=rear)
        {
            j=queue[head++];
            node=G.vexs[i].first_edge;
            while(node!=NULL)
            {
                k=node->ivex;
                if(!visited[k])
                {
                    visited[k]=1;
                    printf("%c ", G.vexs[k].data);
                    queue[rear++] = k;
                }
                node=node->next_edge;
            }
        }
    }
    printf("\n");
}
static void DFS(LGraph G, int i, int *visited)
{
    ENode* node;
    visited[i]=1;
    printf("%c ",G.vexs[i].data);
    node=G.vexs[i].first_edge;
    while(node!=NULL)
    {
        if(!visited[node->ivex])
            DFS(G,node->ivex,visited);
        node=node->next_edge;
    }
}
void DFSTraverse(LGraph G)
{
    int i;
    int visited[MAX];
    for(i=0;i<MAX;i++)
    {
        visited[i]=0;
    }
    printf("DFS: ");
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}
void print_lgraph(LGraph G)
{
    ENode* node;
    for(int i=0;i<G.vexnum;i++)
    {
        printf("%d(%c):",i,G.vexs[i].data);
        node=G.vexs[i].first_edge;
        while(node!=NULL)
        {
            printf("%d(%c)",node->ivex,G.vexs[node->ivex].data);
            node=node->next_edge;
        }
        printf("\n");
    }
}
int main()
{
    LGraph* pG;

    // 无向图自定义"图"(自己输入数据，输入的方法可以参考create_example_lgraph初始化好的数据)
    //pG = create_lgraph();
    //// 无向图的创建，采用已有的"图"
    //pG = create_example_lgraph();
	//有向图的创建
	pG = create_example_lgraph_directed();
    // 打印图
    print_lgraph(*pG);
    DFSTraverse(*pG);//深度优先遍历
	BFS(*pG);//广度优先遍历
	return 0;
}