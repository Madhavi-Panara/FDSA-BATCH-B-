#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of buildings: ";
    cin>>n;

    int graph[100][100];

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }

    int start;
    cout<<"Enter starting building: ";
    cin>>start;

    start--;

    int visited[100]={0};
    int stack[100];
    int top=-1;

    cout<<"DFS: ";

    top++;
    stack[top]=start;
    visited[start]=1;

    while(top!=-1)
    {
        int current=stack[top];
        top--;

        cout<<current+1<<" ";

        for(int i=n-1;i>=0;i--)
        {
            if(graph[current][i]==1&&visited[i]==0)
            {
                top++;
                stack[top]=i;
                visited[i]=1;
            }
        }
    }

    cout<<"\n";

    for(int i=0;i<n;i++)
        visited[i]=0;

    int queue[100];
    int front=0;
    int rear=-1;

    cout<<"BFS: ";

    rear++;
    queue[rear]=start;
    visited[start]=1;

    while(front<=rear)
    {
        int current=queue[front];
        front++;

        cout<<current+1<<" ";

        for(int i=0;i<n;i++)
        {
            if(graph[current][i]==1&&visited[i]==0)
            {
                rear++;
                queue[rear]=i;
                visited[i]=1;
            }
        }
    }

    return 0;
}