// sorted array to bst
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

Node* sortedarray(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);
    root->left=sortedarray(arr, start, mid-1);
    root->right= sortedarray(arr, mid+1,end);
    return root;
}


void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int arr[]={10,20,30,40,50};
    Node* root= sortedarray(arr,0,4);
    preorder(root);
    cout<<endl;
    return 0;
}