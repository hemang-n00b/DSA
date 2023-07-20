#include <bits//stdc++.h>
using namespace std;

vector<int> l;
struct Node{
    int data;
    Node* left;
    Node* right;
};
void inorder(Node* t)
{
    if(t==NULL)
    {
        return;
    }
    inorder(t->left);
    l.push_back(t->data);
    inorder(t->right);
}