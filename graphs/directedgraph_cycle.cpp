#include <bits/stdc++.h>
using namespace std;

bool dfs(int k , vector<int> adj[],vector<int> vis , vector<int> path)
{
    vis[k] = 1;
    path[k]=1 ;
    for (auto it:adj[k])
    {
        if(vis[it] ==1 && path[it] == 1)
            return true;
        else if(vis[it] == 0)
        {
            if(dfs(it , adj , vis, path)==true)
                return true;
        }
    }
    path[k]=0;
    return false;
}
int main()
{
    int n , m ,u  ,v , count=0;
    cin>>n>>m;
    vector<int> adj[n+1] ,vis,path;
    
    for(int i= 0 ; i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i= 0 ;i<=n ; i++)
    {
        vis.push_back(0);
        path.push_back(0);
    }
    for(int i= 1 ; i<=n ; i++)
    {
        if(vis[i] == 0)
        {
            if(dfs(i , adj , vis , path) == true)
            {
                cout<<"True";
                count++;
            }
        }
    }
    if(count==0)
    {
        cout<<"False";
    }
}