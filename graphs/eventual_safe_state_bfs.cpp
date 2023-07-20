#include <bits/stdc++.h>
using namespace std;
int n;
void traversal (int fri , int index, vector<int> &base , vector<int>& dist , int skip)
{
    if(index >= n)
    {
        if(dist[n-1] > skip)
                dist[n-1]= skip ;
        return;
    }
    if(fri == 1)
    {
        if(base[index]==1 )
        {
            if(dist[index] > skip+1)
                dist[index]= skip +1;
            traversal(!fri , index+1 , base, dist ,skip+1);
        }
        // if(base[index]==1 && base[index+1]==0)
        // {
        //     if(dist[index] > skip+1)
        //         dist[index]= skip +1;
        //     traversal(!fri , index+2 , base, dist ,skip+1);
        // }
        // else if(base[index]==1 )
        // {
        //     if(dist[index] > skip+1)
        //         dist[index]= skip +1;
        //     traversal(!fri , index+1 , base, dist ,skip+1);
        // }
        // else if(base[index]==0 && base[index+1]==0)
        // {
        //     if(dist[index] > skip)
        //         dist[index]= skip ;
        //     traversal(!fri , index+2 , base, dist ,skip);
        // }
        else
        {
            if(dist[index]>skip )
                dist[index] = skip  ;
            traversal(!fri , index+1 , base, dist ,skip);
        }
        if(base[index]==1 && base[index+1]==1)
        {
            // if(dist[index] > skip +2)
            //     dist[index]= skip +2 ;
            // traversal(!fri , index+2 , base, dist ,skip+2);
        }
        else if(base[index]==1 && base[index+1]==0)
        {
            if(dist[index] > skip)
                dist[index]= skip +1 ;
            traversal(!fri , index+2 , base, dist ,skip+1);
        }
        else if(base[index]==0 && base[index] ==0)
        {
            if(dist[index] > skip)
                dist[index]= skip ;
            traversal(!fri , index+2 , base, dist ,skip);
        }

    }
    else 
    {
        if(dist[index] > skip )
            dist[index] = skip ;
        traversal(!fri , index+2 , base, dist , skip);
        traversal(!fri , index+1 , base , dist , skip);
    }
}
int main()
{
    int t , k;
    cin>>t;
    for(int i=0 ; i<t ; i++)
    {
        cin>>n;
        vector<int> base ,dist;
        for(int j=0 ; j<n ; j++)
        {
            cin>>k;
            base.push_back(k);
            dist.push_back(INT_MAX);
        }
        traversal(1 , 0 , base , dist , 0);
        cout<<dist[n-1]<<"\n";

    }
}