#include <stdio.h>
#include <stdlib.h>
int n;
void swap(int*a , int*b)
{
    int temp =(*a);
    (*a)=(*b);
    (*b)=temp;
}

int partition(int*A , int mid , int start , int end)
{
    swap(&A[mid] , &A[start]);
    int i=start+1;
    int j=end;
    while(i<=j)
    {
        while(A[i]<=A[start] && i<=j){i++;}
        while(A[j]>A[start] &&i<=j){j--;}
        if(i<=j)
        {
            swap(&A[i] , &A[j]);
            i++;
            j--;
        }
    }
    swap(&A[start] ,&A[j]);
    return j;
}

void sort(int*A, int start , int end)
{
    if(start>=end)
    {
        return ;
    }
    int mid=(start+end)/2;
    int pivot=partition(A , mid , start , end);
    // print(A,n);
    sort(A , start ,pivot-1 );
    sort(A ,pivot+1 ,end);
}
void print(int*A , int len)
{
    for(int i=0 ; i<len ; i++)
    {
        printf("%d " , A[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%d" , &n);
    int*arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0 ; i<n; i++)
    {
        scanf("%d" , &arr[i]);
    }
    sort(arr , 0 , n-1);
    // partition(arr , (n-1)/2 ,0 ,n-1 );
    
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
}