// Double-ended LinkedList Implementation of Deque
#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class Deque
{
private:
    DNode *front, *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}
    bool IsEmpty() const
    {
        return front == nullptr && rear == nullptr;
    }
    ~Deque()
    {
        while (!IsEmpty())
            pop_front();
        cout << "Oops!" << endl;
    }

    void push_front(int x)
    {
        DNode *newNode = new DNode(x);
        if (!IsEmpty())
        {
            newNode->next = front;
            front->prev = newNode;
        }
        else
        {
            rear = newNode;
        }
        front = newNode;
    }
    void push_back(int x)
    {
        DNode *newNode = new DNode(x);
        if (!IsEmpty())
        {
            rear->next = newNode;
            newNode->prev = rear;
        }
        else
        {
            front = newNode;
        }
        rear = newNode;
    }

    void pop_front()
    {
        if (IsEmpty())
            return;
        DNode *temp = front;
        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    void pop_back()
    {
        if (IsEmpty())
            return;
        DNode *temp = rear;
        if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    int getFront() const
    {
        if (IsEmpty())
            throw "Deque is empty";
        return front->data;
    }

    int getBack() const
    {
        if (IsEmpty())
            throw "Deque is empty";
        return rear->data;
    }

    void print() const
    {
        DNode *cur = front;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};