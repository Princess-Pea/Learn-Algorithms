#include <iostream>
using namespace std;

class Queue
{
private:
	struct Node
	{
		int data;
		Node *next;
		Node(int x = 0) : data(x), next(nullptr) {}
	};
	Node *head = new Node(), *front = nullptr, *rear = nullptr;

public:
	~Queue()
	{
		while (!IsEmpty())
			dequeue();
		cout << "Oops!" << endl;
		delete head;
	}
	bool IsEmpty() const
	{
		return front == nullptr && rear == nullptr;
	}
	void enqueue(int x)
	{
		Node *temp = new Node(x);
		if (IsEmpty())
		{
			head->next = temp;
			front = rear = temp;
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void dequeue()
	{
		if (IsEmpty())
			return;
		Node *temp = front;
		if (front == rear)
		{
			head->next = front = rear = nullptr;
		}
		else
		{
			head->next = front->next;
			front = front->next;
		}
		delete (temp);
	}
	void show() const
	{
		for (Node *v = head->next; v; v = v->next)
			cout << v->data << ' ';
		cout << endl;
	}
};
int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(1);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(1);
	q.enqueue(4);
	q.show();
	q.dequeue();
	q.show();
}