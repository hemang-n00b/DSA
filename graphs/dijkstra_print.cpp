#include <bits/stdc++.h>
using namespace std;

int n,m;
int main()
{
    int u,v,k ,wt;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    vector<int> dist;
    vector<int> memo;
    set <pair<int , pair<int,int>> > s;
    for(int i=0 ; i<m ; i++)
    {
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    cin>>k>>m;
    for(int i=0 ; i<n ;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[k] = 0;
    s.insert({ 0,{k ,-1} });
    while(!s.empty())
    {
        int distB = (*(s.begin())).first;
        int node = (*(s.begin())).second.first;
        int prevNode =(*(s.begin())).second.second;
        s.erase(s.begin());
        for(auto it: adj[node])
        {
            if(distB + it.second < dist[it.first])
            {
                dist[it.first] = distB + it.second;
                s.insert({dist[it.first] , {it.first , node}});
                memo[it.first] = node;
            }
        }  
    }

    int i = m;
    while(memo[i] == -1)
    {
         i =memo[i];
    }


}