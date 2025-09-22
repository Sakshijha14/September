#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node*root,int &diameter){
    if(!root){
        return 0;
    }

    int lh=height(root->left,diameter);
    int rh=height(root->right,diameter);

    diameter=max(lh+rh,diameter);

    return 1+max(lh,rh);

}

int diametertree(Node*root){
    int diameter=0;
    height(root,diameter);
    return diameter;
}

int main(){
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int output=diametertree(root);
    cout<<output<<endl;
}