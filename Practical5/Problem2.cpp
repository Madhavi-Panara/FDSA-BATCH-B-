#include<iostream>
using namespace std;

struct Node{
    string name;
    Node*next;
    Node*prev;
};

Node*head1=NULL;
Node*head2=NULL;

// Singly Circular Linked List

void insertSingly(string name){
    Node*newNode=new Node();
    newNode->name=name;

    if(head1==NULL){
        head1=newNode;
        newNode->next=head1;
        return;
    }

    Node*temp=head1;

    while(temp->next!=head1)
        temp=temp->next;

    temp->next=newNode;
    newNode->next=head1;
}

void deleteSingly(string name){
    if(head1==NULL)
        return;

    Node*current=head1;
    Node*previous=NULL;

    do{
        if(current->name==name)
            break;

        previous=current;
        current=current->next;
    }while(current!=head1);

    if(current->name!=name)
        return;

    if(current==head1){
        if(head1->next==head1){
            delete head1;
            head1=NULL;
            return;
        }

        Node*temp=head1;

        while(temp->next!=head1)
            temp=temp->next;

        head1=head1->next;
        temp->next=head1;
        delete current;
        return;
    }

    previous->next=current->next;
    delete current;
}

void displaySingly(){
    if(head1==NULL){
        cout<<"Empty"<<endl;
        return;
    }

    Node*temp=head1;

    do{
        cout<<temp->name<<" ";
        temp=temp->next;
    }while(temp!=head1);

    cout<<endl;
}


// Doubly Circular Linked List

void insertDoubly(string name){
    Node*newNode=new Node();
    newNode->name=name;

    if(head2==NULL){
        head2=newNode;
        newNode->next=head2;
        newNode->prev=head2;
        return;
    }

    Node*last=head2->prev;

    newNode->next=head2;
    newNode->prev=last;

    last->next=newNode;
    head2->prev=newNode;
}

void deleteDoubly(string name){
    if(head2==NULL)
        return;

    Node*current=head2;

    do{
        if(current->name==name)
            break;

        current=current->next;
    }while(current!=head2);

    if(current->name!=name)
        return;

    if(current->next==current){
        delete current;
        head2=NULL;
        return;
    }

    current->prev->next=current->next;
    current->next->prev=current->prev;

    if(current==head2)
        head2=current->next;

    delete current;
}

void displayDoubly(){
    if(head2==NULL){
        cout<<"Empty"<<endl;
        return;
    }

    Node*temp=head2;

    do{
        cout<<temp->name<<" ";
        temp=temp->next;
    }while(temp!=head2);

    cout<<endl;
}


int main(){

    cout<<"Singly Circular Linked List"<<endl;

    insertSingly("A");
    cout<<"After joining A: ";
    displaySingly();

    insertSingly("B");
    cout<<"After joining B: ";
    displaySingly();

    insertSingly("C");
    cout<<"After joining C: ";
    displaySingly();

    deleteSingly("B");
    cout<<"After B leaves: ";
    displaySingly();

    insertSingly("D");
    cout<<"After D joins: ";
    displaySingly();


    cout<<endl<<"Doubly Circular Linked List"<<endl;

    insertDoubly("A");
    cout<<"After joining A: ";
    displayDoubly();

    insertDoubly("B");
    cout<<"After joining B: ";
    displayDoubly();

    insertDoubly("C");
    cout<<"After joining C: ";
    displayDoubly();

    deleteDoubly("B");
    cout<<"After B leaves: ";
    displayDoubly();

    insertDoubly("D");
    cout<<"After D joins: ";
    displayDoubly();

    return 0;
}