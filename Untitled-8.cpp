// calculate the diameter of the tree
// diamtere has two cases One in which root is included and one in which root is not included in the sum of the diameters
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

int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return (max(calcHeight(root->left),calcHeight(root->right)) +1 );
}

int calcDiameter(Node* root){
    if (root==NULL){
        return 0;
    }
    int lh=calcHeight(root->left);
    int rh=calcHeight(root->right);
    int currHeight(lh+rh+1);
    int ld =calcDiameter(root->left);
    int rd = calcDiameter(root->right);
    return max(currHeight ,max(ld,rd));
}





int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node (3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calcDiameter(root)<<" ";
    return 0;

}