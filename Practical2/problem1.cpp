#include<iostream>
using namespace std;

int iterativeSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }}
    return 0;
}
int recursiveSearch(int arr[],int n,int target,int index){
    if(index==n){
        return 0;
    }
    if(arr[index]==target){
        return index;
    }
   return recursiveSearch(arr,n,target,index+1);
}

int main(){
    int n;

    cout<<"Enter number of license plates: ";
    cin>>n;

    int plate[n];

    cout<<"Enter the license plate numbers: ";
    for(int i=0;i<n;i++){
        cin>>plate[i];
    }

    int target;
    cout<<"Enter the target plate: ";
    cin>>target;

    int pos1=iterativeSearch(plate,n,target);

    if(pos1!=0){
        cout<<"Iterative Search: Plate found at position "<<pos1+1<<endl;}
    else{
        cout<<"Iterative Search: Plate not found."<<endl;
    }

    int pos2=recursiveSearch(plate,n,target,0);

    if(pos2!=0){
        cout<<"Recursive Search: Plate found at position "<<pos2+1<<endl;}
    else{
        cout<<"Recursive Search: Plate not found."<<endl;
    }

    return 0;
}
