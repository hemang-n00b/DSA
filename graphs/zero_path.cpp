#include <bits/stdc++.h>
using namespace std;

int n , m;
bool dfs(int row ,int col , int sum , vector<vector<int>> &mat)
{
    if(row==n-1 && col==m-1)
    {
        if(sum + mat[row][col] == 0)
            return true;
    }
    else
    {
    if(row+1<n)
    { 
        if(dfs(row+1 , col ,sum+mat[row][col] , mat) == true)
            return true;
    }
    if(col+1<m)
    {
        if(dfs(row,col+1 , sum+mat[row][col] , mat)==true)
            return true;
    }
    }
    return false;
}
int main()
{
    int k , t;
    cin>>t;
    int temp[t];
    for(int h=0 ; h<t ; h++)
    {
        cin>>n>>m;
        vector<vector<int>> l;
        vector<int> level;
        for(int i=0 ; i<n ; i++)
        {
            level.clear();
            for(int j=0 ; j<m ; j++)
            {
                cin>>k;
                level.push_back(k);
            }
            l.push_back(level);
        }
        if(dfs(0 , 0 , 0 , l)==true)
            temp[h]=1;
        else
            temp[h] = 0;
    }
    for(int i=0 ; i<t ; i++)
    {
        if(temp[i]==1)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}