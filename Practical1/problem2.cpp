#include<iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Enter the number of borrowed books: ";
    cin>>n;

    int bookID[n];

    cout<<"Enter the book IDs: ";
    for(int i=0;i<n;i++){
        cin>>bookID[i];
    }

    for(int i=0;i<n;i++){
        int count=0;
    if(bookID[i]==0){
        continue;
        }

    for(int j=i;j<n;j++){
        if(bookID[i]==bookID[j]){
           count++;
           if(j!=i)
    {
        bookID[j]=0;
    }}}

        if(count>1){
            cout<<"Book ID "<<bookID[i]<<" is duplicated "<<count<<" times."<<endl;
        }
    }

    return 0;
}
