#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct DSU{
    int*parent;
    int*size;
}DSU;

DSU* initDSU( int h)
{
    int*parent=(int*)malloc(sizeof(int)*(h+1));
    int*size=(int*)malloc(sizeof(int)*(h+1));
}

DSU* make_sets(DSU*D , int i)
{
    D->parent[i]=i;
    D->size[i]=1;
    return D;
}

int find(DSU*D , int i)
{
    if(D->parent[i]==i)
        return i;
    D->parent[i]= find(D , i);
    return D->parent[i];
}

DSU*union_set (DSU*D , int a , int b)
{
    int a=find(D,a);
    int b = find(D , b);
    if(a!=b)
    {
        if(D->size[a]>=D->size[b])
        {
            D->parent[b] = D->parent[a];
            D->size[a]+=D->size[b];
        }
        else{
            D->parent[a] = D->parent[b];
            D->size[b]+=D->size[a];
        }
    }
    return D;
}

int main()
{
    int n,m;
    scanf("%d%d"  , &n , &m);
    DSU*D = initDSU(n+1);
    for(int i=1 ; i<=n ;i++ )
    {
        D=make_sets(D, i);
    }
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        scanf("%d%d" , &u , &v);
        D=union_set(D, u , v);
    }
    int q;
    scanf("%d" , &q);
    for(int i=0 ; i<q ; i++)
    {
        int u,v;
        scanf("%d%d" , &u , &v);
        if(find(D, u )==find(D,v))
        {
            printf("YES\n");
        }
        else{
            printf("NO");
        }
    }
}