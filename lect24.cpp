#include<iostream>
using namespace std;

class Node {
public:

    int data;  
    Node* next;     

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

/*brute
Node*findmid(Node*head){

    Node*temp=head;
    if(temp==NULL || temp->next==NULL){
        return temp;
    }
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    int mid=count/2+1;
    temp=head;
    while(temp!=NULL){
        mid=mid-1;
        if(mid==0){
            break;
        }
        temp=temp->next;
    }
    return temp;
}*/

Node*findmid(Node*head){
    Node*slow=head;
    Node*fast=head;
    if(head==NULL || head->next==NULL){
        return head;
    }

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}



int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node*middle=findmid(head);
    cout<<middle->data;
}