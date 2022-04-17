#include <iostream>
using namespace std;
#define size 5
int Arr[size];
int front = -1;
int rear = -1;

bool isEmpty(){
    if ((rear+1)%size == front)
        return true;
    else
        return false;
}

void enqueue(int num){
    if ((rear+1)%size == front){
        cout << "Queue is Full\n";
    }
    else{
        if (front == -1){
            front = 0;
        }
        rear = (rear+1)%size;
        Arr[rear] = num;
    }
}
void dequeue(){
    if (front == -1 && rear == -1){
        cout << "Queue is Empty\n";
    }
    else{
        if (front == rear){
            front = rear = -1;
        }
        else
            front = (front+1)%size;
    }
}
void getFront(){
    if(front == -1 && rear == -1){
        cout<<"Queue is Empty\n";
    }
    else{
        cout<<"Front = "<<Arr[front]<<endl;
    }
}
void Display(){
    if (isEmpty())
        cout << "Queue is empty\n";
    else{
        int i;
        if (front <= rear){
            for (i = front; i <= rear; i++)
                cout << Arr[i] << " ";
        }
        else{
            i = front;
            while (i < size){
                cout << Arr[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear){
                cout << Arr[i] << " ";
                i++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    dequeue();
    enqueue(16);
    getFront();
    Display();
    getchar();
    return 0;
}
