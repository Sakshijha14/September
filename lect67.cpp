#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;

    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }
};

Node* insert(Node*root,int key){
    if(!root){
        return new Node(key);   
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;

}


int floortree(Node*root,int key){
    int floor=-1;
    while(root){
        if(root->data==key){
            return root->data;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }

    return floor;
}

int ceiling(Node*root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            return root->data;
        }
        else if(root->data<key){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
int main(){
    Node*root=nullptr;
    int keys[]={10,5,15,2,7,20};
    for(int key:keys){
        root=insert(root,key);
    }
    int x=6;
        int floordata=floortree(root,x);
        if(floordata==-1){
            cout<<"no floor"<<endl;
        }
        else{
            cout<<"floor of"<<floordata<<endl;
        }
        int ceildata=ceiling(root,x);
        if(ceildata==-1){
            cout<<"not";
        }
        else{
            cout<<"it is"<<ceildata;
        }
}