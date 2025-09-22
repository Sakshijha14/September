#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode* left; 
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


vector<vector<int>>levelorder(TreeNode*root){
    vector<vector<int>>output;
    if(root==NULL){
        return output;
    }

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;

        int size=q.size();
        for(int i=0;i<size;i++){

        TreeNode*node=q.front();
        q.pop();

        level.push_back(node->val);
        if(node->left!=nullptr){
            q.push(node->left);
        }
        if(node->right!=nullptr){
            q.push(node->right);
        }
    }
    output.push_back(level);
    }
    return output;

}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>>input=levelorder(root);
    for(auto it:input){
        for(auto m:it){
            cout<<m<<" ";
        }
    }
}