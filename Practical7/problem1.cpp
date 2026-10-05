#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter capacity: ";
    cin>>n;

    int queue[n];
    int front=-1;
    int rear=-1;
    int choice,value;

    while(true)
    {
        cout<<"\n1.Join";
        cout<<"\n2.Serve";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            if((rear+1)%n==front)
            {
                cout<<"Error: Queue is full. Cannot add token.";
            }
            else
            {
                cout<<"Enter token number: ";
                cin>>value;

                if(front==-1)
                {
                    front=0;
                }

                rear=(rear+1)%n;
                queue[rear]=value;

                cout<<"Current front token: "<<queue[front];
            }
        }
        else if(choice==2)
        {
            if(front==-1)
            {
                cout<<"Error: Queue is empty. Cannot serve.";
            }
            else
            {
                cout<<"Served token: "<<queue[front];

                if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }
                else
                {
                    front=(front+1)%n;
                }

                if(front!=-1)
                {
                    cout<<"\nCurrent front token: "<<queue[front];
                }
                else
                {
                    cout<<"\nQueue is empty.";
                }
            }
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cout<<"Invalid choice.";
        }
    }

    return 0;
}