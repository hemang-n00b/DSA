#include <bits//stdc++.h>
using namespace std;

vector<int> l;
struct Node{
    int data;
    Node* left;
    Node* right;
};
vector<vector<int>> level_order(Node* l)
{
    int ll;
   queue <pair<Node*,int>> q;
//    vector<vector<pair<int,int>>> final;
   vector<pair<int,int>> level;
   Node*i = l;
   q.push({i , 0});
   level.push_back({i->data ,0});
   while(!q.empty())
   {
    Node *next_left = q.front().first->left;
    Node* next_right = q.front().first->right;
    ll = q.front().second;
    level.push_back({q.front().first->data , q.front().second});
    q.pop();
    if(next_left !=NULL)
    {
        q.push({next_left , ll+1});
    }
    if(next_right !=NULL)
    {
        q.push({next_right , ll+1});
    }
   } 
}