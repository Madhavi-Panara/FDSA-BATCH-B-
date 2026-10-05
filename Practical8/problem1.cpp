#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode=new Node();
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

Node* createTree()
{
    int value;
    cin>>value;

    if(value==-1)
        return NULL;

    Node* root=createNode(value);

    cout<<"Enter left child of "<<value<<": ";
    root->left=createTree();

    cout<<"Enter right child of "<<value<<": ";
    root->right=createTree();

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(Node* root)
{
    if(root==NULL)
        return;

    Node* queue[100];
    int front=0;
    int rear=0;

    queue[rear]=root;

    while(front<=rear)
    {
        Node* current=queue[front];
        front++;

        cout<<current->data<<" ";

        if(current->left!=NULL)
        {
            rear++;
            queue[rear]=current->left;
        }

        if(current->right!=NULL)
        {
            rear++;
            queue[rear]=current->right;
        }
    }
}

int main()
{
    cout<<"Enter root value: ";
    Node* root=createTree();

    cout<<"\nInorder: ";
    inorder(root);

    cout<<"\nPreorder: ";
    preorder(root);

    cout<<"\nPostorder: ";
    postorder(root);

    cout<<"\nLevel order: ";
    levelorder(root);

    return 0;
}