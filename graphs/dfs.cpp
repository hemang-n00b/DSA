#include <bits//stdc++.h>
using namespace std;

int n;
vector <int> final;
void store(int u , int v , vector<int> adj[] )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void dfs_ofGraph(int k , vector <int> adj[] , int vis[])
{
    vis[k] =1;
    final.push_back(k);
    for(auto it: adj[k])
    {
        if(vis[it]!= 1)
        {
            dfs_ofGraph(it , adj, vis);
        }
    }
}
int main()
{
    int m,u,v,k;
    cin>>n>>m;
    vector <int> adj[n+1];
    int vis[n+1];
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v;
        store(u , v , adj);
    }
    cin>>k;
    dfs_ofGraph(k , adj , vis);
    for (auto it: final)
    {
        cout<<it<<" ";
    }

}