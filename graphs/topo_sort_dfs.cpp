#include <bits/stdc++.h>
using namespace std;

int n,m;
void topology(int k , vector<int> adj[],vector<int> &topo , int vis[] , stack <int> &s)
{
    vis[k]=1;
    for(auto it: adj[k])
    {
        topology(it , adj , topo , vis ,s);
    }
    s.push(k);
}
int main()
{
    int u,v;
    cin>>n>>m;
    vector<int> adj[n],topo;
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<int> s;
    int vis[n];
    for(int i=0 ; i<n;i++)
    {
        if(vis[i]!=1)
           topology(i , adj , topo , vis , s);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}