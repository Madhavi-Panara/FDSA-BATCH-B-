#include<iostream>
using namespace std;

int iterative(int arr[],int n,int key){
    int low=0,high=n-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return 0;
}

int recursive(int arr[],int low,int high,int key){
    if(low>high)
        return 0;

    int mid=(low+high)/2;

    if(arr[mid]==key)
        return mid;
    else if(arr[mid]<key)
        return recursive(arr,mid+1,high,key);
    else
        return recursive(arr,low,mid-1,key);
}

int main(){
    int n,key;

    cout<<"Enter size: ";
    cin>>n;

    int arr[n];

    cout<<"Enter sorted elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter key: ";
    cin>>key;

    int pos=iterative(arr,n,key);

    if(pos!=0)
        cout<<"Iterative: Found at position "<<pos+1<<endl;
    else
        cout<<"Iterative: Not Found"<<endl;

    pos=recursive(arr,0,n-1,key);

    if(pos!=0)
        cout<<"Recursive: Found at position "<<pos+1;
    else
        cout<<"Recursive: Not Found";

    return 0;
}
