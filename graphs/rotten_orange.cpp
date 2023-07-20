#include <bits//stdc++.h>
using namespace std;

int main()
{
    int n, m ,k ,ll;
    int d_row[]={0,-1,0,1};
    int d_col[] ={-1 ,0,1,0};
    cin>>n>>m;
    vector<vector<int>> l;
    vector<int> level;
    queue<pair< pair <int,int>, int>> q;
    for(int i=0 ; i<n ;i++)
    {
        level.clear();
        for(int j=0 ;j<m ;j++)
        {
            cin>>k;
            level.push_back(k); //0 implies empty, 1 implies fresh oranges , 2 implies rotten oranges , find the min time taken to rotten max oranges 
            //for every fresh orange to rotten it needs a rotten orange adjacent to it
            if(k==2)
                q.push({{i , j} , 0});
        }
        l.push_back(level);
    }
    vector <vector<int>> ans =l;
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        ll = q.front().second;
        q.pop();
        for(int i=0 ;i<4 ;i++)
        {
            int nrow = row +d_row[i];
            int ncol = col +d_col[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && ans[nrow][ncol]==1)
            {
                q.push({{nrow , ncol} , ll+1});
            }
        }
    }
    cout<<ll<<endl;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ;j<m ; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}