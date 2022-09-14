// Count No of leaves
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

int countLeaves(Node* root)
{
  int count;
  if(root==NULL){
      return 0;
  }
  if(root->left==NULL && root->right==NULL){
      return 1;
  }
  return countLeaves(root->left)+countLeaves(root->right);
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
    cout<<countLeaves(root)<<" ";
    return 0;
}