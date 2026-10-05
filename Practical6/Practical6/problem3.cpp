#include<iostream>
#include<string>
using namespace std;

int priority(char op)
{
    if(op=='+'||op=='-')
        return 1;

    if(op=='*'||op=='/')
        return 2;

    if(op=='^')
        return 3;

    return 0;
}

int main()
{
    string infix;
    char stack[100];
    int top=-1;

    cout<<"Enter infix expression: ";
    cin>>infix;

    string postfix="";

    for(int i=0;i<infix.length();i++)
    {
        char ch=infix[i];

        if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            top++;
            stack[top]=ch;
        }
        else if(ch==')')
        {
            while(top!=-1&&stack[top]!='(')
            {
                postfix+=stack[top];
                top--;
            }

            if(top!=-1&&stack[top]=='(')
            {
                top--;
            }
        }
        else
        {
            while(top!=-1&&stack[top]!='('&&priority(stack[top])>=priority(ch))
            {
                postfix+=stack[top];
                top--;
            }
            top++;
            stack[top]=ch;
        }
    }

    while(top!=-1)
    {
        postfix+=stack[top];
        top--;
    }

    cout<<"Postfix expression: "<<postfix;

    return 0;
}