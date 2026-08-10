#include<iostream>
using namespace std;

int main(){
int n;

cout<<"enter number of colours: ";
cin>>n;

int colours[100];

cout<<"enter colour codes: ";
for(int i=0;i<n;i++){
    cin>>colours[i];
}

int low=0;
int mid=0;
int high=n-1;

while(mid<=high){
    if(colours[mid]==0){
        int temp=colours[low];
        colours[low]=colours[mid];
        colours[mid]=temp;
        low++;
        mid++;
    }

    else if(colours[mid]==1){
        mid++;
    }

    else{
        int temp=colours[mid];
        colours[mid]=colours[high];
        colours[high]=temp;
        high--;
    }
}

cout<<"sorted colours: ";
for(int i=0;i<n;i++){
    cout<<colours[i]<<" ";
}

return 0;
}