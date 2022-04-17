#include <iostream>
#include <stack>
using namespace std;
bool checkIsBalanced(string expression) {
    stack<char> s;
    char ch;
    for (int i = 0; i < expression.length(); i++){
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
            s.push(expression[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (expression[i])
        {
        case ')': 
            ch = s.top();
            s.pop();
            if (ch == '{' || ch == '[')
                return false;
            break;
        case '}': 
            ch = s.top();
            s.pop();
            if (ch == '(' || ch == '[')
                return false;
            break;
        case ']':
            ch = s.top();
            s.pop();
            if (ch == '(' || ch == '{')
                return false;
            break;
        }
    }
    return (s.empty());
}
main() {
    string expression = "[{}(){()}]";
    if (checkIsBalanced(expression))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}