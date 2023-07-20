#include <bits//stdc++.h>
using namespace std;

bool dfs(int k , int colour ,vector<int>adj[] ,vector<int> &vis )
{
    vis[k] = colour;
    for(auto it:adj[k])
    {
        if(vis[k]==-1)
        {
            if(dfs(it , !colour , adj , vis) == false)
                return false;
        }
        else if(vis[it] == vis[k])
        {
            return false;
        }
    }
    return true;
}
int n, m;
int main()
{
    int u , v;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis;
    for(int i= 0 ;i<n+1 ; i++)
    {
        vis.push_back(-1);
    }
    cout<<dfs(1,0,adj,vis);
}