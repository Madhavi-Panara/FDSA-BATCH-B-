#include<iostream>
using namespace std;

struct Node{
    string song;
    Node*prev;
    Node*next;
};

Node*head=NULL;

void addBeginning(string song){
    Node*newNode=new Node();
    newNode->song=song;
    newNode->prev=NULL;
    newNode->next=head;

    if(head!=NULL)
        head->prev=newNode;

    head=newNode;
}

void addEnd(string song){
    Node*newNode=new Node();
    newNode->song=song;
    newNode->next=NULL;

    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }

    Node*temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

void insertAfter(string givenSong,string newSong){
    Node*temp=head;

    while(temp!=NULL && temp->song!=givenSong)
        temp=temp->next;

    if(temp==NULL){
        cout<<"Song not found"<<endl;
        return;
    }

    Node*newNode=new Node();
    newNode->song=newSong;

    newNode->next=temp->next;
    newNode->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=newNode;

    temp->next=newNode;
}

void removeFirst(){
    if(head==NULL){
        cout<<"Playlist is empty"<<endl;
        return;
    }

    Node*temp=head;
    head=head->next;

    if(head!=NULL)
        head->prev=NULL;

    delete temp;
}

void display(){
    Node*temp=head;

    cout<<"Playlist: ";

    while(temp!=NULL){
        cout<<temp->song;

        if(temp->next!=NULL)
            cout<<" <-> ";

        temp=temp->next;
    }

    cout<<endl;
}

void countSongs(){
    int count=0;
    Node*temp=head;

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }

    cout<<"Number of songs: "<<count<<endl;
}

int main(){

    addBeginning("Song A");
    display();

    addEnd("Song B");
    display();

    addEnd("Song C");
    display();

    insertAfter("Song B","Song X");
    display();

    countSongs();

    removeFirst();
    display();

    insertAfter("Song Z","Song Y");
    display();

    return 0;
}