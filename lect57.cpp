#include<iostream>
#include<vector>
#include<queue>
using namespace  std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>>zigzag(Node*root){
    vector<vector<int>>output;
    if(root==NULL){
        return output;
    }
    queue<Node*>nodesq;
    nodesq.push(root);
    bool ltor=true;
    while(!nodesq.empty()){
        int size=nodesq.size();
        vector<int>row(size);
        for(int i=0;i<size;i++){
            Node*node=nodesq.front();
            nodesq.pop();

            row[i]
        }
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
}

