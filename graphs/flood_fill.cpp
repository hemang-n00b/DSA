#include <bits//stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> l;
void flood_fill(int row ,int col , int ini_colour , int new_colour )
{
    l[row][col] = new_colour;
    int d_row[] = {-1 , 0 , +1 , 0};
    int d_col[] = {0 , -1 , 0 , +1};
    for(int i=0 ; i<4 ; i++)
    {
        int nrow = row + d_row[i] ;
        int ncol = col + d_col[i] ;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && l[nrow][ncol]==ini_colour && l[nrow][ncol]!= new_colour)
        {
            flood_fill(nrow,ncol , ini_colour , new_colour) ;
        }
    }   
}
int main()
{
    int  k , row , col , new_colour , ini_colour;
    cin>>n>>m;
    vector<vector<int>> motu;
    vector<int> level;
    for(int i=0 ; i<n ; i++)
    {
        level.clear();
        for (int j= 0 ;j<m ; j++ )
        {
            cin>>k;
            level.push_back(k);
        }
        motu.push_back(level);
    }
    cin>>row>>col;
    cin>>new_colour;
    ini_colour = motu[row][col] ;
    l = motu;
    
}