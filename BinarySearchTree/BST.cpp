#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node *buildTree(){
    int d;
    cin>>d;
    Node *root;
    if(d==-1) return NULL;

    root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Preorder traversal
void printTree(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int main(){
    Node*root=buildTree();  
    printTree(root);
    return 0;
}