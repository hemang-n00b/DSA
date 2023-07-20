#include <bits/stdc++.h>
using namespace std;

int main()
{
    int drow[] = {-1 ,0 , 1, 0};
    int dcol[] = {0 ,-1 , 0, 1};
    int n ,nrow , ncol, m,k,trow,tcol ,srow,scol,count=0;
    cin>>n>>m;
    vector<vector<int>> v ,dist;
    vector<int> level ;
    queue<pair<int,pair<int , int>>> q;
    for (int i=0 ; i<n ; i++)
    {
        level.clear();
        for (int j=0;j<m ; j++)
        {
            cin>>k;
            level.push_back(k);
            dist[i][j] = INT_MAX;
        }
        v.push_back(level);
    }
    cin>>srow>>scol>>trow>>tcol;
    dist[srow][scol]=0;
    q.push({0 , {srow ,scol}});
    while(!q.empty())
    {
        
        int row = q.front().second.first;
        int col = q.front().second.second;
        int level = q.front().first;
        if(row==trow && col==tcol)
        {
            count++;
            break;
        }
        q.pop();
        for(int i=0 ; i<4 ;i++)
        {
            nrow = row +drow[i];
            ncol = col + dcol[i];
            if(nrow>=0 && ncol >=0 &&nrow<n &&ncol<m)
            {
                q.push({level +1 , {nrow ,ncol}});
            }
        }
    }

}