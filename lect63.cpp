#include<iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


bool isBST(Node*node,int min,int max){
    if(node==nullptr){
        return true;
    }
    if(node->data<min || node->data>max){
        return false;
    }

    return isBST(node->left,min,node->data-1) && isBST(node->right,node->data+1,max);
}

bool isBST(Node*root){
    return isBST(root,INT_MAX,INT_MIN);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}