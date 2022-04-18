#include<bits/stdc++.h>
#include<iostream>
#include<queue>

using namespace std;

void print(queue<int> Q){
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
}
queue<int> Queue;
void summerize(queue<int> Q){
    while(!(Q.empty())){
        int number1=0, number2=0;
        number1 = Q.front();
        Q.pop();
        if(!Q.empty()){
            number2 = Q.front();
            Q.pop();
        }
        else{
            number2 = 1;
        }
        int average = 0;
        average = (number1 + number2)/2;
        Queue.push(average);
    }
    print(Queue);
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(2);
    q.push(7);
    q.push(1);
    summerize(q);
}
