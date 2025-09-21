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

};/*brute
Node*deletenode(Node*head,int N){
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node*temp=head;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(count==N){
        Node*newhead=head->next;
        delete(head);
        return newhead;
    }

    int left=count-N;
    temp=head;
    while(temp!=NULL){
        left--;
        if(left==0){
            break;
        }
        temp=temp->next;
    }
    Node*deleted=temp->next;
    temp->next=temp->next->next;
    delete(deleted);
    return head;

}
*/

Node*deletenode(Node*head,int N){
    Node*slow=head;
    Node*fast=head;

    for(int i=0;i<N;i++){
        fast=fast->next;
    }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    
    Node*delnode=slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){

    int N = 3;
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);

    head=deletenode(head,N);
    print(head);
}