#include<iostream>
using namespace std;

int main()
{
    int parking[10];

    for(int i=0;i<10;i++)
        parking[i]=-1;

    int n;
    cout<<"Enter number of vehicles: ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int number;
        cout<<"Enter vehicle registration number: ";
        cin>>number;

        int slot=number%10;
        int start=slot;
        int placed=0;

        while(parking[slot]!=-1)
        {
            slot=(slot+1)%10;

            if(slot==start)
            {
                cout<<"Error: Parking lot is full. Vehicle cannot be parked.";
                break;
            }
        }

        if(parking[slot]==-1)
        {
            parking[slot]=number;
            placed=1;
            cout<<"Vehicle parked at slot "<<slot<<endl;
        }
    }

    cout<<"\nFinal parking lot:\n";

    for(int i=0;i<10;i++)
    {
        if(parking[i]==-1)
            cout<<"Slot "<<i<<": Empty"<<endl;
        else
            cout<<"Slot "<<i<<": "<<parking[i]<<endl;
    }

    return 0;
}