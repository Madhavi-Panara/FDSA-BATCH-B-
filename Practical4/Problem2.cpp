#include<iostream>
using namespace std;

int main(){

    int queue[100];
    int length=0;
    int n;

    cout<<"Enter number of patients: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Enter patient token: ";
        cin>>queue[i];
        length++;
    }

    int value;

    cout<<"Enter patient token to delete: ";
    cin>>value;

    int position=-1;

    for(int i=0;i<length;i++){
        if(queue[i]==value){
            position=i;
            break;
        }
    }

    if(position==-1){
        cout<<"Token not found"<<endl;
    }
    else{
        for(int i=position;i<length-1;i++){
            queue[i]=queue[i+1];
        }

        length--;

        cout<<"Token deleted"<<endl;
    }

    cout<<"Forward Queue: ";

    for(int i=0;i<length;i++){
        cout<<queue[i]<<" ";
    }

    cout<<endl;

    cout<<"Reverse Queue: ";

    for(int i=length-1;i>=0;i--){
        cout<<queue[i]<<" ";
    }

    cout<<endl;

    return 0;
}