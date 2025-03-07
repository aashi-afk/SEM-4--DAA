#include<stdio.h>
#define N 8

enum color{ WHITE, GREY,BLACK};

char id[]={'s','t',u',v','w','x','y','z'};

struct DFSTable
{
int st;
int ft;
int pi;
int colour;
};
dfs[N];

int time=0;

void DFS-VISIT(int G[][N])
{
    dfs[u].color=GREY;
    dfs[u].st=++time;
    int v;
    for(v=0;v<N;v++)
    {
        if((G[u][v]))
        {

        }
    }
}
void DFS(int G[][N])
{
    int  v;
    for(v=0;v<N;v++)
    {
        dfs[v].color=WHITE;
        dfs[v].pi=-1;

        u=0
    }
}

void printtable()
{
    int v;
    printf("\n id \t st\t ft \t clr \t pi \t");
    printf("---------------------------------------");
    for(v=0;v<n;v++)
    {
        printf(\n %c \t %d \t %d \t %c \t %c \t );
    }
}

intmain()
{
    int G[][N]={{1,0,0,0,0}
                {0,1,0,0,0}
                {0,0,1,0,0}
                {0,0,0,1,0}
                {0,0,0,0,1}};
    DFS(G);

    printTable();
}
