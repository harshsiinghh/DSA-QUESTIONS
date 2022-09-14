// postorder with the use of vector
#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void spostOrder(vector<int> &pos, Node* root){
    if(root == NULL){
        return ;
    }
    
    spostOrder(pos, root->left);
    spostOrder(pos, root->right);
    pos.push_back(root->data);
    return;
}

vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> post;
  if(root == NULL){
      return post;
  } 
  spostOrder(post, root);
  return post;
  
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node (3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(5);
    root->right->left->left = new Node(7);
    vector<int>v=postOrder(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}