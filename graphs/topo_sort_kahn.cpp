#include <bits/stdc++.h>
using namespace std;

void kahn(vector<int> &topo , int indegree[] , vector<int> adj[] )
{
    queue <int> q;
    for(int i=0 ; i<n ; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }

}
int n,m;
int main()
{
    int  u,v;
    cin>>n>>m;
    vector<int> adj[n];
    int indegree[n];
    queue <int> q;
    vector<int> topo;
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v] ++;
    }
    
    kahn(topo , indegree , adj);

    //to detect whether the given combination is a cycle
    if(topo.size()==n)
        cout<<"True";
    else
        cout<<"False";

    for(int i=0 ; i<n ; i++)
    {
        cout<<topo[i];
    }
    
    
}