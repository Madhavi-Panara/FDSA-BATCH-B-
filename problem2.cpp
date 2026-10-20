#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* shelf[10];

    for(int i=0;i<10;i++)
        shelf[i]=NULL;

    int n;
    cout<<"Enter number of books: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int code;
        cout<<"Enter book code: ";
        cin>>code;

        int index=code%10;

        Node* newNode=new Node();
        newNode->data=code;
        newNode->next=shelf[index];
        shelf[index]=newNode;
    }

    cout<<"\nFinal contents of shelves:\n";

    for(int i=0;i<10;i++)
    {
        cout<<"Shelf "<<i<<": ";

        if(shelf[i]==NULL)
        {
            cout<<"Empty";
        }
        else
        {
            Node* current=shelf[i];

            while(current!=NULL)
            {
                cout<<current->data<<" ";
                current=current->next;
            }
        }

        cout<<endl;
    }

    return 0;
}