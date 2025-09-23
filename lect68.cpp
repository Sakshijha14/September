#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data1){
        data=data1;
        left=NULL;
        right=NULL;
    }
};

Node* insert(Node*root,int key){
    if(!root)
    return new Node(key);

    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}
void inorder(Node*root,vector<int>&nums){
    if(!root)
    return;
    inorder(root->left,nums);
    nums.push_back(root->data);
    inorder(root->right,nums);
}
bool findpair(Node*root,int target){
    vector<int>output;
    inorder(root,output);
    int left=0;
    int right=output.size()-1;
    while(left<right){
        int sum=output[left]+output[right];
        if(sum==target){
            cout<<"pair found: "<<output[left]<<","<<output[right]<<endl;
            return true;
        }
        else if(sum<target){
            ++left;
        }
        else{
            --right;
        }
    }
    cout<<"no pair";
    return false;
}



int main(){
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);
    int target=22;
    findpair(root,target);
}