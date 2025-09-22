#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minwidth(TreeNode*root){
    if(!root){
        return 0;
    }

    int output=0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});

    while(!q.empty()){
        int size=q.size();
        int position=q.front().second;

        int last,first;

        for(int i=0;i<size;i++){
            int currentid=q.front().second-position;
            TreeNode*node=q.front().first;
            q.pop();

            if(i==0){
                first=currentid;
            }
            if(i==size-1){
                last=currentid;
            }
            if(node->left){
                q.push({node->left,2*currentid+1});
            }
            if(node->right){
                q.push({node->right,2*currentid+2});
            }
        }
        output=max(output,last-first+1);
    }
    return output;
}
int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int diameter=minwidth(root);
    cout<<"the diameter "<<diameter<<endl;
}
