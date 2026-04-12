#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* next;

	Node(int val = 0) : data(val), next(nullptr) {}
	void print()
	{
		for (Node* v = this; v != nullptr; v = v->next)
		{
			cout << v->data << " ";
		}
		cout << endl;
	}
	void top()
	{
		if (this == nullptr) return;
		else cout << "top：" << this->data << endl;

	}
};

static bool IsEmpty(Node*& head)
{
	return (head == nullptr);
}

void push(Node*& head, int x)
{
	Node* newhead = new Node(x);
	newhead->next = head;
	head = newhead;
}

void pop(Node*& head)
{
	if (IsEmpty(head)) return;
	Node* temp = head;
	head = head->next;
	delete(temp);
}

int main()
{
	Node *head = nullptr; //记得初始化头指针为空
	push(head, 5);
	push(head, 3);
	head->print();
	pop(head);
	head->top();
	push(head, 2);
	head->print();
}