#include <bits//stdc++.h>
using namespace std;

int n;
vector<int> final;
void store(int u , int v , vector<int> adj[] )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void bfs_ofGraph(int k , vector<int> adj[] )
{
    int vis[n+1];    
    queue<int> q;
    q.push(k);
    vis[k]=1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        final.push_back(node);
        for(auto it:adj[node])
        {
            if(vis[it] != 1)
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }

}

int main()
{
    int  m ,u , v, wt,k;
    
    cin>>n>>m;
    vector <int> adj[n+1];
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v;
        store(u , v , adj);
    }
    cin>>k;
    bfs_ofGraph(k ,adj  );
    for(auto it:final)
    {
        cout<<it<<" ";
    }

}