#include <bits//stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* create_tree(){
    Node*n = NULL;
    return n;
}
Node* add_a_node(Node* l , int data)
{
    Node* n = new(Node);
    n->data = data;
    Node*i  =l;
    //do required operations to store the data in trees
    //example
    i->left->right->right->left = n;
    return l ;
}
int main()
{
    Node* j = create_tree();
    Node* j = add_a_node(j , 5);
}