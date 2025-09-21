#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data1,Node*next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node*convertarr(vector<int>&arr){
    Node* dummynode=new Node(-1);
    int n=arr.size();
    Node*temp=dummynode;
    for(int i=0;i<n;i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return dummynode->next;
}
/*brute
Node*merged(Node*list1,Node*list2){
    vector<int>arr;
    Node*temp1=list1;
    Node*temp2=list2;
    while(temp1!=NULL){
        arr.push_back(temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        arr.push_back(temp2->data);
        temp2=temp2->next;
    }
    sort(arr.begin(),arr.end());
    Node*head=convertarr(arr);
    return head;

}*/

Node*merged(Node*list1,Node*list2){
    Node*dummynode=new Node(-1);
    Node*temp=dummynode;

    while(list1!=NULL && list2!=NULL){
        if(list1->data <=list2->data){
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1!=NULL){
        temp->next=list1;
    }
    else{
        temp->next=list2;
    }

    return dummynode->next;
}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main(){
    Node*list1=new Node(1);
    list1->next=new Node(3);
    list1->next->next=new Node(5);

    Node*list2=new Node(2);
    list2->next=new Node(4);
    list2->next->next=new Node(6);

    cout<<"first sorted linked list: ";
    print(list1);
    
    cout<<"second sorted linked list: ";
    print(list2);

    Node*sortmerge=merged(list1,list2);
    print(sortmerge);
}