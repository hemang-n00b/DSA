#include <bits//stdc++.h>
using namespace std;

int n , m;
bool bfs(int k , int vis[] , vector<int> adj[] )
{
    for(int i=0 ; i<n+1 ; i++)
    {
        vis[i] =-1;
    }
    queue <int> q;
    q.push(k);
    vis[k] =0;
    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(vis[it]==-1)
            {
                q.push(it);
                vis[it] = !vis[node];
            }
            else if(vis[it]== vis[node] )
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int u, v;
    cin>>n>>m;
    vector<int> adj[n+1];
    int vis[n+1];
    for(int i= 0 ;i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<bfs(1,vis , adj);

}