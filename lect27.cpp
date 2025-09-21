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

Node*numbers(Node*list1,Node*list2){
    Node*dummynode=new Node(-1);
    Node*temp=dummynode;
    int carry=0;
    while(list1!=NULL || list2!=NULL || carry){
        int sum=0;
        if(list1!=NULL){
            sum+=list1->data;
            list1=list1->next;
        }
        if(list2!=NULL){
            sum+=list2->data;
            list2=list2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node*node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }

    return dummynode->next;



}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}




int main(){
    Node*list1=new Node(2);
    list1->next=new Node(4);
    list1->next->next=new Node(3);

    Node*list2=new Node(5);
    list2->next=new Node(6);
    list2->next->next=new Node(4);

    print(list1);
    cout<<endl;
    print(list2);

    Node*sumed=numbers(list1,list2);
    print(sumed);

}