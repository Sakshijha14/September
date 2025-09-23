#include<iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int minsum(Node*root,int &maxi){
    if(root==NULL){
        return 0;
    }
    int leftmax=minsum(root->left,maxi);
    int rightmax=minsum(root->right,maxi);

    maxi=max(maxi,leftmax+rightmax+root->data);


    return max(leftmax,rightmax)+root->data;
}

int minpath(Node*root){
    int maxi=INT_MIN;
    minsum(root,maxi);
    return maxi;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    int output=minpath(root);
    cout<<output;
}