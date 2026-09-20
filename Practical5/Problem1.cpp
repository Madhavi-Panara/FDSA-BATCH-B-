#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }

};

int main(){
    Node*head=NULL;
    Node*tail=NULL;


    Node*new1=new Node(10);
    new1->next=head;
    head->prev=new1;
    head=new1;


    Node*temp=head;
    Node*new2=new Node(60);
    tail->next=new2;
    new2->prev=tail;
    tail=new2;



    int k=2;
    Node*temp=head;
    Node*new3=new Node(60);
    for(int i=0;i<k-1 &&  temp!=NULL ;i++){
        temp=temp->next;
    }
    new3->prev=temp;
    new3->next=temp->next;
    temp->next=new3;



    Node*temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;



    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    cout<<"total song:"<<count<<endl;




    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
}
