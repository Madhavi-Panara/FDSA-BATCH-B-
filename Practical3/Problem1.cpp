#include<iostream>
using namespace std;

int main(){
int n;

cout<<"enter number of students: ";
cin>>n;

int marks[100];

    cout<<"enter marks: ";
    for(int i=0;i<n;i++){
        cin>>marks[i];
    }

    int bubble[100];
    for(int i=0;i<n;i++){
        bubble[i]=marks[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(bubble[j]>bubble[j+1]){
                int temp=bubble[j];
                bubble[j]=bubble[j+1];
                bubble[j+1]=temp;
            }
        }
    }

cout<<"bubble sort: ";
    for(int i=0;i<n;i++){
        cout<<bubble[i]<<" ";
    }

int selection[100];
    for(int i=0;i<n;i++){
        selection[i]=marks[i];
}

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(selection[j]<selection[min]){
            min=j;
        }
    }

int temp=selection[i];
    selection[i]=selection[min];
    selection[min]=temp;
}

cout<<"\nselection sort: ";
    for(int i=0;i<n;i++){
        cout<<selection[i]<<" ";
    }

int insertion[100];
    for(int i=0;i<n;i++){
        insertion[i]=marks[i];
    }

    for(int i=1;i<n;i++){
        int key=insertion[i];
        int j=i-1;

    while(j>=0&&insertion[j]>key){
        insertion[j+1]=insertion[j];
        j--;
    }
    insertion[j+1]=key;
    }

cout<<"\ninsertion sort: ";
    for(int i=0;i<n;i++){
    cout<<insertion[i]<<" ";
}
    return 0;
}







