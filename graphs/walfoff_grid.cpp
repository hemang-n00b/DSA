//in this question we have 1 as land and 0 as water 
//we need to convert all land into water that are surrounded by water in all four directions
#include <bits//stdc++.h>
using namespace std;

void dfs(int row , int col , vector<vector<int>> &adj , vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int drow[]={0 , -1 , 0 , +1};
    int dcol[]={-1 , 0 , 1 , 0};
    for(int i= 0 ;i<4 ; i++)
    {
        int nrow = row +drow[i];
        int ncol = col + dcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && adj[nrow][ncol]==1 && vis[nrow][ncol]==0)
        {
            dfs(nrow , ncol , adj , vis);
        }
    }
}
int n , m;
int main()
{
    
    int k , count=0;
    cin>>n>>m;
    vector<vector<int>> l , ans , vis;
    vector<int> level , vis_l;
    for(int i=0 ; i<n ; i++)
    {
        level.clear();
        vis_l.clear();
        for(int j=0;j<m ; j++)
        {
            cin>>k;
            level.push_back(k);
            vis_l.push_back(0);
            if(k==1)
            {
                count++;
            }
        }
        l.push_back(level);
        vis.push_back(vis_l);
    }
    ans =l;
    for(int i=0 ; i<n ; i++)
    {
        if(l[i][0]= 1 && vis[i][0] == 0)
        {
            dfs(i , 0 , ans , vis);
        }
        if(l[i][m-1]= 1 && vis[i][m-1] == 0)
        {
            dfs(i , m-1 , ans , vis);
        }
    }
    for(int i=0 ; i<m ; i++)
    {
        if(l[0][i]= 1 && vis[0][i] == 0)
        {
            dfs(0 , i , ans , vis);
        }
        if(l[m-1][i]= 1 && vis[m-1][i] == 0)
        {
            dfs(m-1 , i , ans , vis);
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j= 0 ;j<m ; j++)
        {
            if(vis[i][j] ==1)
            {
                count--;
            }
        }
    }
    cout<<count;
}
