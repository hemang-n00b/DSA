#include <bits//stdc++.h>
using namespace std;

int n;
bool dfs(int k ,vector<int> adj[] , int vis[] )
{
    vis[k] = 1;
    for(auto it:adj[k])
    {
        if(vis[it]==1 && it !=k)
        {
            return true;
        }
        else if(vis[it] != 1)
        {
            if(dfs(it , adj , vis) == true);
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int m,u,v ,k ;
    cin>>n>>m;
    int vis[n];
    vector<int> adj[n];
    for(int i=0 ;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>k;
    cout<<dfs(k , adj , vis);
}