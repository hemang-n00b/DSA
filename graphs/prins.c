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

typedef struct Node{
    int node ;
    int w;
    struct Node* next;
}Node;

Node** initList(int n)
{
    Node** arr=(Node**)malloc(sizeof(Node*)*(n+1));
    for(int i=1 ; i<=n ; i++)
    {
        arr[i]=(Node*)malloc(sizeof(Node));
        arr[i]->next=NULL;
    }
    return arr;
}

Node** createNode(Node** arr ,int u ,int v, int w)
{
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));
    n1->node = u;
    n1->w = w;
    n2->w = w;
    n2->node = v;
    n1->next = arr[v]->next;
    arr[v]->next = n1;
    n2->next = arr[u]->next;
    arr[u]->next = n2;
    return arr;
}

typedef struct Hemang{
    int u;
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
Hemang* createHemang(int u , int w)
{
    Hemang*n = (Hemang*)malloc(sizeof(Hemang));
    n->u=u;
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
        else{
            break;
        }
    }  
    return H;
}

int main()
{
    int n,m;
    scanf("%d%d" , &n , &m);
    Node** arr = initList(n);
    for(int i=0 ; i<m ; i++)
    {
        int u,v,w;
        scanf("%d%d%d" , &u , &v , &w);
        arr = createNode(arr , u , v , w);
    }
    int*visited=(int*)malloc(sizeof(int)*(n+1));
    int sum=0;
    Heap*H=createHeap(2*m +4);
    H=insertHeap(H , createHemang(1 , 0));
    for(int i=0 ; i<n ; i++)
    {
        Hemang*t = front(H);
        H=extractMin(H);
        if(visited[t->u]==1)
        {
            i--;
            continue;
        }
        visited[t->u] =1;
        sum+=t->w;
        Node*temp = arr[t->u]->next;
        while(temp!=NULL)
        {
            H=insertHeap(H , createHemang(temp->node , temp->w));
            temp=temp->next;
        }
    }
    printf("%d" , sum);
}