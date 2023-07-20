# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int value;
    struct  Node* next;
}Node;

Node* createNode(int value){
    Node*n=(Node*)malloc(sizeof(Node));
    n->value=value;
    n->next=NULL;
    return n;
}

void insert(Node**head , int value)
{
    Node*n=createNode(value);
    n->next=*head;
    *head=n;
}

void printL(Node*head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d " , head->value);
    printL(head->next);
}


Node* Merge(Node*first , Node*second)
{
    Node* answer=NULL;
    if(first==NULL)
    {
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
    else if(first->value< second->value)
    {
        answer=first;
        answer->next=Merge(first->next , second);
    }
    else
    {
        answer=second;
        answer->next=Merge(first, second->next );
    }
    return answer;
}





void Find_Middle(Node*head , Node**first , Node**second)
{
    Node*cur=head;
    Node*fast=(head)->next;
    Node*slow=head;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *first=cur;
    *second=slow->next;
    slow->next=NULL;
}
void Mergesort(Node**head)
{
    Node*cur=*head;
    Node*first;
    Node*second;
    if(cur==NULL || cur->next==NULL)
    {
        return;
    }
    Find_Middle(cur , &first , &second);
    Mergesort(&first);
    Mergesort(&second);
    *head=Merge(first , second);
}


int main()
{
    int n;
    scanf("%d" , &n);
    Node*L=NULL;
    Node*first=NULL;
    Node*second=NULL;
    for(int i=0 ; i<n ; i++)
    {
        int k;
        scanf("%d" , &k);
        insert(&L , k);
    }
    // Find_Middle(L ,&first , &second );
    Mergesort(&L);
    printL(L);
}