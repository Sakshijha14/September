#include<iostream>
#include<map>
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
bool detectl(Node*head){
    Node*temp=head;
    map<Node*,int>mp;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            return true;
        }
        mp[temp]=1;
        temp=temp->next;
    }
    return 0;

}
*/


bool detectl(Node*head){

    Node*slow=head;
    Node*fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    Node*head=new Node(1);
    Node*second=new Node(2);
    Node*third=new Node(3);
    Node*fourth=new Node(4);
    Node*fifth=new Node(5);

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    fifth->next=third;

    if(detectl(head)){
        cout<<"got it"<<endl;
    }
    else{
        cout<<"not in"<<endl;
    }

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}