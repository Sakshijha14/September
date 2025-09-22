#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int>topview(Node*root){
    vector<int>output;
    if(root==NULL){
        return output;
    }

    map<int,int>mp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node*node=it.first;
        int line=it.second;
        
        if(mp.find(line)==mp.end()){
            mp[line]=node->data;
        }
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:mp){
        output.push_back(it.second);
    }
    return output;

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

    vector<int>top=topview(root);
    for(auto it:top){
        cout<<it<<" ";
    }
    cout<<endl;


    return 0;

}