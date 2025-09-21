#include<iostream>
#include<stack>
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
/*brute
bool ispalindrome(Node*head){
    Node*temp=head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}*/
Node* reversel(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
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

bool ispalindrome(Node*head){

    if(head==NULL || head->next==NULL){
        return true;
    }
    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node*newnode=reversel(slow->next);
    Node*first=head;
    Node*second=newnode;
    while(second!=NULL){
        if(first->data!=second->data){
            return false;
        }
        first=first->next;
        second=second->next;
    }
    return true;

}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

int main(){
    Node*head=new Node(1);
    head->next=new Node(5);
    head->next->next=new Node(2);
    head->next->next->next=new Node(5);
    head->next->next->next->next=new Node(1);

    cout<<"the orginal ";
    print(head);
    if(ispalindrome(head)){
        cout<<"the linked list is ";
    }
    else{
        cout<<"the linked list not ";
    }

    return 0;
}