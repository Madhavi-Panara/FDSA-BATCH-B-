#include<iostream>
using namespace std;

int main()
{
    int table[10];

    for(int i=0;i<10;i++)
        table[i]=-1;

    int n;
    cout<<"Enter number of students: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int id;
        cout<<"Enter student ID: ";
        cin>>id;

        int h1=id%10;
        int h2=7-(id%7);
        int placed=0;

        for(int j=0;j<10;j++)
        {
            int index=(h1+j*h2)%10;

            if(table[index]==-1)
            {
                table[index]=id;
                cout<<"Student ID "<<id<<" placed at slot "<<index<<endl;
                placed=1;
                break;
            }
        }

        if(placed==0)
        {
            cout<<"Error: Table is full. Student ID "<<id<<" cannot be inserted."<<endl;
        }
    }

    cout<<"\nFinal hash table:\n";

    for(int i=0;i<10;i++)
    {
        if(table[i]==-1)
            cout<<"Slot "<<i<<": Empty"<<endl;
        else
            cout<<"Slot "<<i<<": "<<table[i]<<endl;
    }

    return 0;
}