#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
void checkEachTwo(stack<int> st_passed){
    int bigger,smaller,number1,number2,result = 0;
    while(!(st_passed.empty())){
        number1 = st_passed.top();
        st_passed.pop();
        if(!st_passed.empty()){
            number2 = st_passed.top();
            st_passed.pop();
        }
        else{
            number2 = 0;
            s.push(number1);
            cout<<" "<<number1;
            return;
        }
        if(number1<number2){
            result = number2-number1;
            s.push(result);
            cout<<" "<<result;
            s.push(number1);
            cout<<" "<<number1;
        }
        else if(number1>number2){
            result = number1 - number2;
            s.push(result);
            cout<<" "<<result;
            s.push(number2);
            cout<<" "<<number2;
        }
        
    }
}
int main(int argc, char const *argv[])
{
    stack<int> Stack;
    Stack.push(0);
    Stack.push(3);
    Stack.push(5);
    Stack.push(4);
    Stack.push(3);
    Stack.push(1);
    Stack.push(2);
    checkEachTwo(Stack);

    return 0;
}
