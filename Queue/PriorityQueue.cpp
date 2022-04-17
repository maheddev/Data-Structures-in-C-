#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int> gq){
	priority_queue<int> g = gq;
	while (!g.empty()) {
		cout <<" "<< g.top();
		g.pop();
	}
	cout << '\n';
}
int main()
{
	
	priority_queue<int> pqueue;
	pqueue.push(10);
	pqueue.push(30);
	pqueue.push(20);
	pqueue.push(5);
	pqueue.push(1);

	cout << "The priority queue pqueue is : ";
	showpq(pqueue);

	cout << "\npqueue.size() : " << pqueue.size();
	cout << "\npqueue.top() : " << pqueue.top();

	cout << "\npqueue.pop() : ";
	pqueue.pop();
	showpq(pqueue);

	return 0;
}
