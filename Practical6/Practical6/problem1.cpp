#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter capacity: ";
    cin>>n;

    int stack[n];
    int top=-1;
    int choice,value;

    while(true)
    {
        cout<<"\n1.Place tray";
        cout<<"\n2.Take tray";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            if(top==n-1)
            {
                cout<<"Error: Stack is full. Cannot place tray.";
            }
            else
            {
                cout<<"Enter tray number: ";
                cin>>value;

                top++;
                stack[top]=value;

                cout<<"Current top tray: "<<stack[top];
            }
        }
        else if(choice==2)
        {
            if(top==-1)
            {
                cout<<"Error: Stack is empty. Cannot take tray.";
            }
            else
            {
                cout<<"Taken tray: "<<stack[top];
                top--;

                if(top!=-1)
                {
                    cout<<"\nCurrent top tray: "<<stack[top];
                }
                else
                {
                    cout<<"\nStack is empty.";
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