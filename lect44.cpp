#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};

void inorder(Node*root,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

vector<int>inordered(Node*root){
    vector<int>arr;
    inorder(root,arr);
    return arr;
}


int main(){

    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    vector<int>output=inordered(root);
    cout<<"inorder traversal: ";
    for(int data:output){
        cout<<data<<" ";
    }
    return 0;
}