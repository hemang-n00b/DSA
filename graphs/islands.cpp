#include <bits//stdc++.h>
using namespace std;
int n_row , n_col;

void bfs(int row , int col , vector <vector<int>> mat )
{
    queue<pair<int,int>> q;
    q.push({row ,col});
    mat[row][col] = 0;
    while(!q.empty())
    {
        n_row = q.front().first;
        n_col = q.front().second;
        q.pop();
        for(int del_i = -1 ; del_i<=1 ; del_i++)
        {
            for(int del_j = -1 ; del_j<=1 ; del_j++)
            {
                if(mat[n_row +del_i][n_col+del_j] ==1)
                {
                    q.push({n_row +del_i  , n_col+del_j});
                    mat[n_row +del_i][n_col+del_j] = 0;
                }
            }
        }

    }
}
int main()
{
    int n,m , k , c=0;
    cin>>n>>m;
    vector<vector<int>> mat;
    vector<int> level;
    for(int i=1 ; i<n+1 ; i++)
    {
        level.clear();
        for(int j=1 ; j<n+1 ; j++)
        {
            cin>>k;
            level.push_back(k) ;
        }
        mat.push_back(level);
    }
    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<n+1 ; j++)
        {
            if(mat[i][j]==1)
            {
                c++;
                bfs(i , j ,mat);
            }
        }
    }
    cout<<c;
}