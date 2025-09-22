#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>>fivertical(Node*root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>>store;
    store.push({root,{0,0}});
    while(!store.empty()){
        auto p=store.front();
        store.pop();
        Node*node=p.first;
        int x=p.second.first;
        int y=p.second.second;

        nodes[x][y].insert(node->data);

        if(node->left){
            store.push({node->left,{x-1,y+1}});
        }
        if(node->right){
            store.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>>output;
    for(auto it:nodes){
        vector<int>col;
        for(auto m:it.second){
            col.insert(col.end(),m.second.begin(),m.second.end());
        }
        output.push_back(col);
    }
    return output;
}

void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
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
    vector<vector<int>> verticalTraversal =fivertical(root);

    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);
}