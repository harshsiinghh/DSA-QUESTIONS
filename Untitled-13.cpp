//Lowest common ancestor
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
bool getpath(Node* root,int key,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==key){
        return true;
    }
    if(getpath(root->left,key,path)|| getpath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}

int lca(Node* root, int n1, int n2)
{
    vector<int>path1;
    vector<int>path2;

    if(!getpath(root,n1, path1) || getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<=path1.size() && path2.size();pc++){
        if(path1[pc]!=path2[pc]){
        break;
        }
    }
    return path1[pc-1];
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node (3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    int n1=7;
    int n2=6;
    int lca1= lca(root,n1,n2);

    if(lca1==-1){
        cout<<"LCA dosent exist"<<" ";
    }else{
        cout<<"LCA:"<<lca1<<" ";
    }

    return 0;
}