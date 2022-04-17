#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void deleteByIndex(int Arr[],int index, int n){
    int i;
    for (i = 0; i < n; i++)
        if(i == index)
            break;

    if(i<n){
        n = n-1;
        for (int j = i; j < n; j++){
            Arr[j]=Arr[j+1];
        }
    }
    
}

void deleteByValue(int Arr[],int number, int n){
    int i;
    for (i = 0; i < n; i++)
        if(Arr[i] == number)
            break;

    if(i<n){
        n = n-1;
        for (int j = i; j < n; j++){
            Arr[j]=Arr[j+1];
        }
    }
    
}
void display(int Arr[]){
    for (int i = 0; i < 7; i++)
    {
        cout<<Arr[i]<<endl;
    }
}
int main(int argc, char const *argv[]){
    int array[8] = {1,2,3,4,5,6,7,8};
    deleteByIndex(array,3,7);
    deleteByValue(array,5,6);
    display(array);
    
}
