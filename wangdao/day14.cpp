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
    if((pG=(LGraph*)calloc(1,sizeof(LGraph)))==NULL)//空间申请失败
        return NULL;
    //memset(pG,0,sizeof(LGraph));//效果等同于calloc
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
        {
            pG->vexs[p1].first_edge=node1;
        }      
        else{
            link_last(pG->vexs[p1].first_edge,node1);
        }
            
    }
    return pG;
}
void BFS(LGraph G)
{
    int head = 0;
    int rear = 0;
    int queue[MAX];     // 辅组队列
    int visited[MAX];   // 顶点访问标记
    int i, j, k;
    ENode *node;

	//每个顶点未被访问
    for (i = 0; i < G.vexnum; i++)
        visited[i] = 0;
	//从零号顶点开始遍历
    //printf("BFS: ");
    for (i = 0; i < G.vexnum; i++)//对每个连同分量均调用一次BFS
    {
        if (!visited[i])//如果没访问过，就打印，同时入队,最初是A
        {
            visited[i] = 1;//标记已经访问过
            printf(" %c", G.vexs[i].data);
            queue[rear++] = i;  // 入队列
        }
        while (head != rear) //第一个进来的是A，遍历A的每一条边
        {
            j = queue[head++];  // 出队列
            node = G.vexs[j].first_edge;
            while (node != NULL)
            {
                k = node->ivex;
                if (!visited[k])
                {
                    visited[k] = 1;
                    printf(" %c", G.vexs[k].data);
                    queue[rear++] = k;//类似于树的层次遍历，遍历到的同时入队
                }
                node = node->next_edge;
            }
        }
    }
    printf("\n");
}
static void DFS(LGraph G, int i, int *visited)
{
    ENode* node;
    visited[i]=1;
    printf(" %c",G.vexs[i].data);
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
    //printf("DFS: ");
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
	pG = create_example_lgraph_directed();
    DFSTraverse(*pG);//深度优先遍历
	BFS(*pG);//广度优先遍历
	return 0;
}