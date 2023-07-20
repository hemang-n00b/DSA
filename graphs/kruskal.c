#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int parent(int i)
{
    return i/2;
}
int left(int i)
{
    return 2*i;
}
int right(int i)
{
    return 2*i + 1;
}

typedef struct DSU{
    int*parent;
    int* size;
}DSU;

DSU* createDSU(int n)
{
    DSU* d = (DSU*)malloc(sizeof(DSU));
    d->parent=(int*)malloc(sizeof(int)*(n+1));
    d->size=(int*)malloc(sizeof(int)*(n+1));
    return d;
}
DSU* make_set(DSU*d,int n)
{
    d->parent[n] =n;
    d->size[n] =1;
    return d;
}

int find(DSU*d , int v)
{
    if(v==d->parent[v])
    {
        return v;
    }
    d->parent[v] =find(d ,d->parent[v]);
    return d->parent[v];
}

DSU* union_sets(DSU*d , int a, int b)
{
    a=find(d,a);
    b=find(d,b);
    if(a!=b)
    {
        if(d->size[a]>d->size[b])
        {
            d->parent[b]=a;
            d->size[a]+= d->size[b];
        }
        else{
            d->parent[a]=b;
            d->size[b] += d->size[a];
        }
    }
}

typedef struct Hemang{
    int u;
    int v;
    int w;
}Hemang;

typedef struct Heap{
    int size;
    int current;
    Hemang** arr;
}Heap;

Heap* createHeap(int size)
{
    Heap* h= (Heap*)malloc(sizeof(Heap));
    h->size=size;
    h->current=0;
    h->arr= (Hemang**)malloc(sizeof(Hemang*)*size);
    return h;
}

Hemang*front(Heap*H)
{
    return H->arr[1];
}
bool IsEmpty(Heap*H)
{
    if(H->current==0)
    {
        return true;
    }
    return false;
}
Hemang* createHemang(int u , int v, int w)
{
    Hemang*n = (Hemang*)malloc(sizeof(Hemang));
    n->u=u;
    n->v=v;
    n->w=w;
    return n;
}

Heap* insertHeap(Heap*H , Hemang*h)
{
    H->current++;
    H->arr[H->current]=h;
    int t = H->current;
    while(t>1 && H->arr[t]->w < H->arr[parent(t)]->w)
    {
        H->arr[parent(t)]=H->arr[t];
        t=parent(t);
    }
    H->arr[t]=h;
    return H;
}

Heap* extractMin(Heap*H)
{
    Hemang* value=H->arr[H->current--];
    int t=1;
    H->arr[1]=value;
    int child;
    while (left(t)<=H->current)
    {
        if(right(t)<=H->current && H->arr[left(t)]->w > H->arr[right(t)]->w)
        {
            child = right(t);
        }
        else{
            child=left(t);
        }
        if(H->arr[child]->w < value->w)
        {
            Hemang*temp = H->arr[t];
            H->arr[t] = H->arr[child];
            H->arr[child] = H->arr[t];
            t=child;
        }
    }  
    return H;
}

int main()
{
    int n,m;
    scanf("%d%d" , &n,&m);
    Heap*H = createHeap(2*m+10);
    DSU* d = createDSU(n+1);
    for(int i=0 ; i<m ; i++)
    {
        int u,v,w;
        scanf("%d%d%d" , &u , &v , &w);
        H=insertHeap(H ,createHemang(u,v,w) );
    }
    for(int i=1 ; i<=n ; i++)
    {
        make_set(d , i);
    }
    int sum=0 ,a,b;
    for(int i=0 ; i<n-1 ; i++)
    {
        Hemang*h = front(H);
        H = extractMin(H);
        a=find(d , h->u);
        b= find(d , h->v);
        if(a!=b)
        {
            union_sets(d , h->u , h->v);
            sum+=h->w;
        }
        else{
            i--;
        }        
    }
    printf("%d" , sum);
}