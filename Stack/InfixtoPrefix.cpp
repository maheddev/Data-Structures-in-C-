#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int precedence_Check(char c)
{
    switch (c)
    {
    case '^':
        return 3;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return -1;
        break;
    }
}
void Infix_to_Postfix_Function(string str)
{
    stack<char> myStack;
    string output;
    for (int i = 0; i < str.length(); i++)
    {
        char character = str[i];
        if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9'))
        {
            output += character;
        }
        else if (character == '(')
        {
            myStack.push('(');
        }
        else if (character == ')')
        {
            while (myStack.top() != '(')
            {
                output += myStack.top();
                myStack.pop();
            }
            myStack.pop();
        }
        else
        {
            while (!myStack.empty() && precedence_Check(str[i]) <= precedence_Check(myStack.top()))
            {
                output += myStack.top();
                myStack.pop();
            }
            myStack.push(character);
        }
    }
    while (!myStack.empty())
    {
        output += myStack.top();
        myStack.pop();
    }
    cout << "Your PostFix Expression is: " << output << endl;
}
int main()
{
    string myString;
    cout << "Enter the Expression to Convert (InFix to PostFix): ";
    cin >> myString;
    Infix_to_Postfix_Function(myString);
    return 0;
}