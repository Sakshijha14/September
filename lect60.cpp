#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

void connect(Node*root){
    if(!root){
        return ;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        Node*prev=nullptr;

        for(int i=0;i<size;i++){
            Node*curr=q.front();
            q.pop();
            if(prev){
                prev->next=curr;
            }
            prev=curr;
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
}