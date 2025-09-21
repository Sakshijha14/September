#include<iostream>
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
Node*reversel(Node*head){
    Node*temp=head;
    Node*prev=NULL;
    while(temp!=NULL){
        Node*front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;

}

Node*getk(Node*temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* kreverse(Node*head,int k){

    Node*temp=head;
    Node*prevlast=NULL;
    while(temp!=NULL){
        Node*kthnode=getk(temp,k);
        if(kthnode==NULL){

            if(prevlast){
                prevlast->next=temp;
            }
            break;
        }
        Node*nextnode=kthnode->next;
        kthnode->next=NULL;
        reversel(temp);

        if(temp==head){
            head=kthnode;
        }
        else{
            prevlast->next=kthnode;
        }
        prevlast=temp;
        temp=nextnode;
    }
    return head;
    

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

    Node*head=new Node(5);
    head->next=new Node(4);
    head->next->next=new Node(3);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(9);
    head->next->next->next->next->next=new Node(2);

    print(head);
    head=kreverse(head,4);
    cout<<endl;
    print(head);

    return 0;
}