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

Node*insert(Node*root,int key){
    if(root==NULL){
        return new Node(key);
    }

    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if(key>root->data){
        root->right=insert(root->right,key);
    }
    return root;
}

void inorder(Node*root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int>keys={50,30,70,20,40,60,80};
    Node*root=nullptr;
    for(auto it:keys){
        root=insert(root,it);
    }

    inorder(root);
    cout<<endl;

    return 0;
}