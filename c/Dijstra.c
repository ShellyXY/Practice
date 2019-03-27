#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX          100
#define INF          65535   
#define isLetter(a)  ((((a)>='a')&&((a)<='z'))||(((a)>='A')&&((a)<='Z')))
#define LENGTH(a)    (sizeof(a)/sizeof(a[0]))

//图的邻接矩阵
typedef struct _graph
{
    char vexs[MAX];       //顶点集合
    int  vexnum;          //顶点数
    int  edgnum;          //边数
    int  matrix[MAX][MAX];//邻接矩阵
}Graph,*PGraph;

//边的结构体
typedef struct _EdgeData
{
    char start; //边的起点
    char end;   //边的终点
    int  weight;//边的权重
}EData;

//返回ch在matrix中的权重
static int get_position(Graph G,char ch)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==ch)
        {
            return i;
        }
    }
    return -1;
}

//读取一个输入字符
static char read_char()
{
    char ch;

    do
    {
        ch=getchar();
    } while (!isLetter(ch));
    return ch;
        
}

//创建图
Graph* create_graph()
{
    char   c1,c2;
    int    v,e;
    int    i,j,weight,p1,p2;
    Graph* pG;

    //输入顶点数和边数
    printf("请输入项目顶点的数目:\n");
    scanf("%d",&v);
    printf("请输入边的数目:\n");
    scanf("%d",&e);
    if(v<1||e<1||(e>(v*(v-1))))
    {
        printf("输入有误！！\n");
        return NULL;
    }

    if((pG=(Graph*)malloc(sizeof(Graph)))==NULL)
    {
        return NULL;
    }
    memset(pG,0,sizeof(Graph));              //初始化，memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值

    //初始化“顶点数”和“边数”
    pG->vexnum=v;
    pG->edgnum=e;
    //初始化“顶点”
    for(i=0;i<pG->vexnum;i++)
    {
        printf("vertex(%d)",i);
        pG->vexs[i]=read_char();
    }

    //1.初始化“边”的权值
    for(i=0;i<pG->vexnum;i++)
    {
        for(j=0;j<pG->vexnum;j++)
        {
            if(i==j)
            {
                pG->matrix[i][j]=0;
            }
            else
            {
                pG->matrix[i][j]=INF;
            }           
        }
    }
    //2.初始化“边”的权值，根据用户的输入进行初始化
    for(i=0;i<pG->edgnum;i++)
    {
        //读取边的起始顶点，结束顶点，权值
        printf("edge(%d):",i);
        c1=read_char();
        c2=read_char();
        scanf("%d",&weight);

        p1=get_position(*pG,c1);
        p2=get_position(*pG,c2);
        if(p1==-1||p2==-1)
        {
            printf("输入有误!!!\n");
            free(pG);
            return NULL;
        }

        pG->matrix[p1][p2]=weight;
        pG->matrix[p2][p1]=weight;
    }
    return pG;
}

//创建图（用已经提供的矩阵）
Graph* create_example_graph()
{
    char vexs[]={'A','B','C','D','E','F','G'};
    int matrix[][9]={
              /*A*//*B*//*C*//*D*//*E*//*F*//*G*/
      /*A*/ {   0,  12, INF, INF, INF,  16,  14},
      /*B*/ {  12,   0,  10, INF, INF,   7, INF},
      /*C*/ { INF,  10,   0,   3,   5,   6, INF},
      /*D*/ { INF, INF,   3,   0,   4, INF, INF},
      /*E*/ { INF, INF,   5,   4,   0,   2,   8},
      /*F*/ {  16,   7,   6, INF,   2,   0,   9},
      /*G*/ {  14, INF, INF, INF,   8,   9,   0}};
      int vlen=LENGTH(vexs);
      int i,j;
      Graph* pG;

      //输入“顶点数”和“边数”
      if((pG=(Graph*)malloc(sizeof(Graph)))==NULL)
      {
          return NULL;
      }
      memset(pG,0,sizeof(Graph));

      //初始化“顶点数”
      pG->vexnum=vlen;
      //初始化“顶点”
      for(i=0;i<pG->vexnum;i++)
      {
          pG->vexs[i]=vexs[i];
      }

      //初始化“边”
      for(i=0;i<pG->vexnum;i++)
      {
          for(j=0;j<pG->vexnum;j++)
          {
              pG->matrix[i][j]=matrix[i][j];
          }
      }
     
      //统计边的数目
      for(i=0;i<pG->vexnum;i++)
      {
          for(j=0;j<pG->vexnum;j++)
          {
              if(i!=j&&pG->matrix[i][j]!=INF)
              {
                  pG->edgnum++;
              }
          }
      }
      pG->edgnum/=2;
      return pG;
}

//返回顶点v的第一个邻接顶点的索引，失败则返回-1
static int first_vertex(Graph G,int v)
{
    int i;

    if(v<0||v>(G.vexnum-1))
    {
        return -1;
    }

    for(i=0;i<G.vexnum;i++)
    {
        if(G.matrix[v][i]!=0&&G.matrix[v][i]!=INF)
        {
            return i;
        }
    }
    return i;
}



 //返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
static int next_vertix(Graph G, int v, int w)
{
    int i;
 
    if (v<0 || v>(G.vexnum-1) || w<0 || w>(G.vexnum-1))
        return -1;
 
    for (i = w + 1; i < G.vexnum; i++)
        if (G.matrix[v][i]!=0 && G.matrix[v][i]!=INF)
            return i;
 
    return -1;
}

/*
//深度优先搜索遍历图
void DFSTraverse(Graph G)
{
    int i;
    int visited[MAX];    //顶点访问标记

    //初始化所有顶点没有被访问
    for(i=0;i<G.vexnum;i++)
    {
        visited[i]=0;
    }

    printf("DFS:");
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            DFS(G,i,visited);
        }        
    
    printf("\n");
    }
}

void BFS(Graph G)
{
    int head=0;
    int rear=0;
    int queue[MAX];   //辅助队列
    int visited[MAX]; //顶点访问标记
    int i,j,k;

    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            
        }
    }
}
*/
void print_graph(Graph G)
{
    int i,j;

    printf("Matrix Graph:\n");
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            printf("%10d",G.matrix[i][j]);
        }
        printf("\n");
    }
}

/*
*Dijkstra是最短路径
*即，统计图（G）中“顶点vs”到其他顶点的最短距离
*参数说明：
*      G -- 图
*     vs -- 起始顶点（start vertex）。即计算“顶点vs”到其他顶点的最短距离
*   prev -- 前驱顶点数组。即，prev[i]的值是“顶点vs”到“顶点i”的最短路径所经历的全部顶点中，位于顶点i之前的哪个顶点
*   dist -- 长度数组，即，dist[i]是“顶点vs”到“顶点i”的最短路径长度
*/
void Dijkstra(Graph G,int vs,int prev[],int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];

    //初始化
    for(i=0;i<G.vexnum;i++)
    {
        flag[i]=0;              //顶点i的最短路径还没获取到。
        prev[i]=0;              //顶点i的前驱结点为0。
        dist[i]=G.matrix[vs][i];//顶点i的最短路径为“顶点vs”到“顶点i”的权。
    }

    //对“顶点vs”进行初始化
    flag[vs]=1;
    dist[vs]=0;

    //遍历G.vexnum-1次：每次找出一个顶点的最短路径
    for(i=1;i<G.vexnum;i++)
    {
        //寻找当前最小的路径
        //即，在未获取最短路径的顶点中，找到离vs最近的顶点（k）
        min=INF;
        for(j=0;j<G.vexnum;j++)
        {
            if(flag[j]==0&&dist[j]<min)
            {
                min=dist[j];
                k=j;
            }
        }
        //标记“顶点k” 为已经获取到的最短路径
        flag[k]=1;

        //修正当前最短路径和前驱顶点
        //即，当已经“顶点k的最短路径”之后，更新“未获取最短路径的顶点的最短路径和前驱顶点”
        for(j=0;j<G.vexnum;j++)
        {
            tmp=(G.matrix[k][j]==INF?INF:(min+G.matrix[k][j]));//防止溢出
            if(flag[j]==0&&(tmp<dist[j]))
            {
                dist[j]=tmp;
                prev[j]=k;
            }
        }
    }

    //打印dijkstra最短路径的结果
    printf("dijkstra(%c):\n",G.vexs[vs]);
    for(i=0;i<G.vexnum;i++)
    {
        printf(" shortest(%c,%c)=%d\n",G.vexs[vs],G.vexs[i],dist[i]);
    }
}

int main()
{
    int prev[MAX]={0};
    int dist[MAX]={0};
    Graph* pG;

    pG=create_example_graph();
    print_graph(*pG);
    Dijkstra(*pG,3,prev,dist);

    system("pause");
    return 0;
    
}