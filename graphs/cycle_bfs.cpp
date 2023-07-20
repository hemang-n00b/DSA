#include <bits//stdc++.h>
using namespace std;


int main()
{
    int n, m ,u,v,k ;
    cin>>n>>m;
    vector<int> adj[n+1] ;
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);//this line occurs only if graph is undirected
    }
    cin>>k;
    queue <pair<int, int>> q;
    int vis[n];
    q.push({k , 0});
    vis[k] =1;
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                q.push({it , node});
                vis[it] =1;
            }
            else if(it != parent)
            {
                cout<<"the given graph is a cycle";
                return 0;                
            }
        }

    }
    cout<<" the given graph is not a cycle";
    return 0;
}