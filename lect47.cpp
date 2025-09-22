#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val),
        left(nullptr), right(nullptr) {}
};

void recurleft(Node*root,int level,vector<int>&output){
    if(root==NULL){
        return ;
    }
    if(output.size()==level){
        output.push_back(root->data);
    }
    recurleft(root->left,level+1,output);
    recurleft(root->right,level+1,output);
}

void recuright(Node*root,int level,vector<int>&output){
    if(root==NULL){
        return ;
    }
    if(output.size()==level){
        output.push_back(root->data);
    }
    recuright(root->right,level+1,output);
    recuright(root->left,level+1,output);
}

vector<int>leftnode(Node*root){
    vector<int>arr;

    recurleft(root,0,arr);
    return arr;
}

vector<int>rightnode(Node*root){
    vector<int>arr;
    recuright(root,0,arr);

    return arr;
}



int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    vector<int>rightide=rightnode(root);
    for(auto it:rightide){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int>leftide=leftnode(root);
    for(int it:leftide){
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;

    
}