#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode*lcalowest(TreeNode*p,TreeNode*q,TreeNode*root){
    if(!root){
        return nullptr;
    }
    if(p->val<root->val && root->val>q->val){
        return lcalowest(p,q,root->left);
    }
    if(p->val>root->val && q->val>root->val){
        return lcalowest(p,q,root->right);
    }

    return root;
}

int main(){

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left->left;  
    TreeNode* q = root->left->right;

    TreeNode*lca=lcalowest(p,q,root);
    cout<<lca->val;
}