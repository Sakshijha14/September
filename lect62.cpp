#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isbst(TreeNode*root,long long minvalue,long long maxval){
    if(!root)
    return true;
    if(root->val<=minvalue || maxval<=root->val){
        return false;
    }
    return isbst(root->left,minvalue,root->val) && isbst(root->right,root->val,maxval);

}
int main(){
     TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(25);

     cout << (isbst(root) ? "Tree is a BST" : "Tree is NOT a BST") << endl;

    root->right->left->val = 5; 
    cout << (isbst(root) ? "Tree is a BST" : "Tree is NOT a BST") << endl;

    return 0;
}
