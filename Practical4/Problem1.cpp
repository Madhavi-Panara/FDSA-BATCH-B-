#include <iostream>
using namespace std;

int main(){
    int queue[100];
    int length=0;
    int n;

    cout<<"Enter number of operations: ";
    cin>>n;

    for (int i=0;i<n;i++){
        int type,value,position;

        cout<<"Enter operation type(1-Front,2-End,3-Position): ";
        cin>>type;

        if(type==1){
            cout<<"Enter patient token: ";
            cin>>value;

            for(int j=length;j>0;j--){
                queue[j]=queue[j-1];
            }

            queue[0]=value;
            length++;
        }
        else if(type==2){
            cout<<"Enter patient token: ";
            cin>>value;

            queue[length]=value;
            length++;
        }
        else if(type==3){
            cout<<"Enter patient token: ";
            cin>>value;

            cout<<"Enter position: ";
            cin>>position;

            if(position>length){
                queue[length]=value;
                length++;
            }
            else{
                for(int j=length;j>position;j--) {
                    queue[j]=queue[j-1];
                }
            queue[position]=value;
                length++;
            }
        }
        else{
            cout<<"Invalid operation";
            continue;
        }
        cout<<"Queue: ";

        for(int j=0;j<length;j++){
            cout<<queue[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}