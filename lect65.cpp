#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int data1){
        data=data1;
        left=NULL;
        right=NULL;
    }
};
bool getnode(Node*root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    else if(key<root->data){
        return getnode(root->left,key);
    }
    else{
        return getnode(root->right,key);
    }
}

Node*insert(Node*root,int key){
    if(root==NULL){
        return new Node(key);
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    if(key>root->data){
        root->right=insert(root->right,key);
    }

    return root;

}



int main(){

    Node*root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);

    int key=60;

    if(getnode(root,key)){
        cout<<"key got";
    }
    else{
        cout<<"key not";
    }



}