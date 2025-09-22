#include<iostream>
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

Node* lca(Node*one,Node*two,Node*root){

    if(root==NULL || root==one || root==two){
        return root;
    }
    Node*left=lca(one,two,root->left);
    Node*right=lca(one,two,root->right);

    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    else{
        return root;
    }

}



int main(){
    Node*head=new Node(1);
    head->left=new Node(2);
    head->right=new Node(3);
    head->left->left=new Node(4);
    head->left->right=new Node(5);
    head->right->left=new Node(6);
    head->right->right=new Node(7);

    Node*one=head->left->left;
    Node*two=head->left->right;


    Node*output=lca(one,two,head);
    cout<<output->data;



}