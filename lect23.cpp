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
Node*reversedl(Node*head){
    Node*temp=head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();

        temp=temp->next;
    }

    return head;
}*/


Node*reversedl(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*prev=NULL;
    while(head!=NULL){
    Node*front=head->next;
    head->next=prev;
    prev=head;
    head=front;
    }
    return prev;
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

    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);

    cout<<"the original one is: ";
    print(head);

    head=reversedl(head);
    cout<<"the modified one is: ";
    print(head);
    return 0;
}