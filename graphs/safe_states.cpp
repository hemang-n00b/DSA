#include <bits/stdc++.h>
using namespace std;

bool dfs(int k , vector<int> adj[] , int vis[] , int path[] )
{
    vis[k]=1;
    path[k]=1;
    for(auto it:adj[k])
    {
        if(vis[it] == 1 && path[it]==1)
        {
            return true;
        }
        else if(vis[it]!=1)
        {
            if(dfs(it , adj , vis , path)==true)
                return true;
        }
    }
    path[k]=0;
}
int n , m;
int main()
{
    int u , v;
    cin>>n>>m;
    int vis[n] , path[n];
    vector<int> adj[n];
    for(int i =0 ; i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i= 0 ;i<n ; i++)
    {
        if(vis[i]!=1)
        {
            bool p= dfs(i , adj , vis , path);
        }
    }
    for(int i=0 ; i<n ; i++)
    {
        if(path[i] != 1)
            cout<<i<<" ";
    }

}