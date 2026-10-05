#include<iostream>
#include<string>
using namespace std;

int main()
{
    string queue[1000];
    int front=0;
    int rear=-1;
    int choice;
    string patient;

    while(true)
    {
        cout<<"\n1.Arrive";
        cout<<"\n2.Attend";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice: ";
        cin>>choice;

        if(choice==1)
        {
            cout<<"Enter patient name: ";
            cin>>patient;

            rear++;
            queue[rear]=patient;

            cout<<"Current front patient: "<<queue[front];
        }
        else if(choice==2)
        {
            if(front>rear)
            {
                cout<<"Error: No patients waiting.";
            }
            else
            {
                cout<<"Attended patient: "<<queue[front];
                front++;

                if(front<=rear)
                {
                    cout<<"\nCurrent front patient: "<<queue[front];
                }
                else
                {
                    cout<<"\nWard is empty.";
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