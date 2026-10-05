#include<iostream>
#include<string>
using namespace std;

int main()
{
    string stack[1000];
    int top=0;
    int choice;
    string page;

    cout<<"Enter first page: ";
    cin>>page;
    stack[top]=page;

    while(true)
    {
        cout<<"\n1.Visit page";
        cout<<"\n2.Back";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter page: ";
            cin>>page;

            top++;
            stack[top]=page;

            cout<<"Current page: "<<stack[top];
        }
        else if(choice==2)
        {
            if(top==0)
            {
                cout<<"Error: No history left. Cannot go back.";
                cout<<"\nCurrent page: "<<stack[top];
            }
            else
            {
                top--;
                cout<<"Current page: "<<stack[top];
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