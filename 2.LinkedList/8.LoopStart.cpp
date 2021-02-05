#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val=0;
    Node* next=NULL;
    Node(int v){
        val=v;
        next=NULL;
    }
};

void printList(Node* head){
    while(head!=NULL){
        cout<<head->val<<"-->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

Node* LoopStartDetect(Node* head){
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)break;
    }
    if(fast==NULL || fast->next==NULL)return NULL;
    fast=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}


int main(){
    Node *head=new Node(7);
    head->next = new Node(8);
    head->next->next = new Node(5);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = head->next->next;
    Node* cycleStart=LoopStartDetect(head); 
    if(cycleStart==NULL){
        cout<<"No Cycle"<<endl;
    }
    else {
        cout<<"Loop started at "<<cycleStart->val<<"."<<endl;
    }
}