#include <stdio.h>
#include <stdlib.h>

int*copyArray(int*A , int start , int end , int*B)
{
    for(int i=start ; i<=end ; i++)
    {
        B[i-start]=A[i];
    }
    return B;
}


int*merge(int*A , int*L , int*R , int lfi , int rfi)
{
    int c=0 , l=0 ,r=0;
    for(int i=0 ; i<lfi+rfi ; i++)
    {
    if(l==lfi)
    {
        A[c++]=R[r++];
    }
    else if(r==rfi)
    {
        A[c++]=L[l++];
    }
    else{
        if(L[l]>R[r])
        {
            A[c++]=R[r++];
        }
        else if(L[l]<=R[r])
        {
            A[c++]=L[l++];
        }
    }
    }
    return A;

}

int* sort(int*A ,int len)
{
    if(len==1)
    {
        return A;
    }
    int mid = (len-1)/2;
    int*L=(int*)malloc(sizeof(int)* (mid+3));
    L=copyArray(A ,0 , mid , L);
    int*R=(int*)malloc(sizeof(int)* (len-mid+4));
    R=copyArray(A , mid+1 , len-1 , R);
    L=sort(L ,mid+1);
    R=sort(R ,len-mid-1 );
    A = merge(A ,L,R ,mid+1 , len-mid-1);
    return A;
}

int main()
{
    int n;
    scanf("%d" , &n);
    int*arr=(int*)malloc(sizeof(int)*(n+1));
    for(int i=0 ; i<n; i++)
    {
        scanf("%d" , &arr[i]);
    }
    arr=sort(arr , n);
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
}