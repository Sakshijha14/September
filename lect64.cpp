#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*right;
    Node*left;

    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};

bool issymmetr(Node*t1,Node*t2){
    if(!t1 && !t2)
    return true;
    if(!t1 || !t2)
    return false;

    return (t1->data==t2->data) && issymmetr(t1->left,t2->right) && issymmetr(t1->right,t2->left);
}

bool issymmetric(Node*root){
    if(!root){
        return true;
    }
    return issymmetr(root->left,root->right);
}

int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(4);
    root->right->right=new Node(3);

    if(issymmetric(root)){
        cout<<"the tree is symmteric ";
    }
    else{
        cout<<"the tree is not symmetric ";
    }
}