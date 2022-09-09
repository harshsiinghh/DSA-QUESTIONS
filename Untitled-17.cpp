// search in bst
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

Node* bstSearch(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return bstSearch(root->left,key);
    }
    return bstSearch(root->right,key);
}

int main()
{
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node (5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    int key=5;
    Node* val=bstSearch(root,key);
    if (val==NULL){
        cout<<"Key not found"<<" ";
    }else{
        cout<<"Key found"<<" ";
    }
    return 0;
}