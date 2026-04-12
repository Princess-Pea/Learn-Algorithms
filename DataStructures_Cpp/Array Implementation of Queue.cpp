#include <iostream>
using namespace std;

#define N 100

int A[N];
int front = -1, rear = -1;

static bool IsEmpty()
{
	return front == -1 && rear == -1;
}

static bool IsFull()
{
	return (rear + 1) % N == front;
}

void enqueue(int val)
{
	if (IsFull()) return;
	else
	{
		if (IsEmpty()) front = 0;
		rear = (rear + 1) % N;
		A[rear] = val;
	}
}

void dequeue()
{
	if (IsEmpty()) return;
	else
	{
		if (front == rear) front = rear = -1;
		else front = (front + 1) % N;
	}
}

static void print() {
	if (IsEmpty()) {
		cout << "Queue is empty" << endl;
		return;
	}
	for (int i = front; i != rear; i = (i + 1) % N)
	{
		cout << A[i] << ' ';
	}
	cout << A[rear] << endl;
}