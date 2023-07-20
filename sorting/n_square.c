// Selection Sort

for(int i=n-1 ; i>=0 ;i--)
    {
        int max=arr[i];
        int index =i;
        for(int j=0 ; j<=i ; j++)
        {
            if(arr[j]>max)
            {
                max=arr[j];
                index=j;
            }
        }
        swap(&arr[i] , &arr[index]);
    }

// bubble sort

for(int i=n-1 ; i>=0 ; i--)
{
    for(int j=0 ; j<i ;j++ )
    {
        if(arr[j]>arr[j+1])
        {
            swap(&arr[j] , &arr[j+1]);
        }
    }
}

// insertion sort

for(int i=1 ; i<n ;i++)
{
    for(int j=i ; j>0 ; j--)
    {
        if(arr[j]<arr[j-1])
            swap(&arr[j-1] , &arr[j]);
    }
}