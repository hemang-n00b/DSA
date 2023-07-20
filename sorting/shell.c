#include <stdio.h>
#include <stdlib.h>

void swap(int*a , int*b)
{
    int temp =(*a);
    (*a)=(*b);
    (*b)=temp;
}

int main()
{
    int n;
     scanf("%d" , &n);
     int arr[n+1];
    for(int i=0 ; i< n ;i++)
    {
        scanf("%d" , &arr[i]);
    }
    for(int gap=n/2 ; gap>0 ; gap=gap/2)
    {
        for(int i= 1; i<n ; i++)
        {
            // for (int j = i; j < N; j += gap)
            int j=i;
            while(j>=gap && arr[j-gap]>arr[j])
            {
                swap(&arr[j] , &arr[j-gap]);
                j=j-gap;
            }
        }
    }
    
    for(int i=0 ; i<n;i++)
    {
        printf("%d " , arr[i]);
    }
}