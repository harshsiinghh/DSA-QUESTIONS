// to find all the nodes at k distance

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
// wcase 1 when you have to find the subtree nodes node only
void subtreenode(Node* root, int k){
    if(k<0|| root == NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    subtreenode(root->left , k-1);
    subtreenode(root->right ,k-1);
    return;
}

// case 2 when you have to find the ancestor node

int calculatenode( Node* root ,Node* target,int k){
    if(root==NULL){
        return -1;
    }
    if (root== target){
        subtreenode(root , k);
        return 0;
    }
    int dl=calculatenode(root->left,target,k);
        if (dl!=-1){
            if(dl+1==k){
                cout<<root->data<<" ";
            }else{
                subtreenode(root->right,k-dl-2);
            }
            return dl+1;
        }
        int dr=calculatenode(root->right, target,k);
        if (dr!=-1){
            if(dr+1==k){
                cout<<root->data<<" ";
            }else{
                subtreenode(root->left,k-dr-2);
            }
            return dr+1;
        } 
    return -1;
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node (3);
    root->left->left = new Node(4);
    // root->left->right = new Node(3);
    // root->right->right = new Node(6);
    calculatenode(root ,root->left,1);

    return 0;
}