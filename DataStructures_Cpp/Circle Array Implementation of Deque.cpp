// Circle Array Implementation of Deque
// 实际上在前面queue的基础上，增加在front端插入和rear端删除的功能即可
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

void push_back(int val)
{
    if (IsFull())
        return;
    else if (IsEmpty())
    {
        front = rear = 0;
        A[rear] = val;
        return;
    }
    else
    {
        rear = (rear + 1) % N;
        A[rear] = val;
    }
}

void push_front(int val)
{
    if (IsFull())
        return;
    else if (IsEmpty())
    {
        front = rear = 0; // 统一从 0 开始
        A[front] = val;
        return;
    }
    else
    {
        front = (front - 1 + N) % N;
        A[front] = val;
    }
}

void pop_back()
{
    if (IsEmpty())
        return;
    else
    {
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + N) % N;
    }
}

void pop_front()
{
    if (IsEmpty())
        return;
    else
    {
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % N;
    }
}

static void print()
{
    if (IsEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % N)
    {
        cout << A[i] << ' ';
    }
    cout << A[rear] << endl;
}