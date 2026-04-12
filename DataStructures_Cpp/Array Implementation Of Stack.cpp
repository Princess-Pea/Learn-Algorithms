#include <iostream>
using namespace std;

class STACK {
private:
    int a[10] = {0};
    int top = -1;

public:
    void push(int x) {
        if (top < 9)
            a[++top] = x;
        else
            cout << "Stack overflow!" << endl;
    }

    void pop() {
        if (!IsEmpty())
            a[top--] = 0;
        else
            cout << "Stack underflow!" << endl;
    }

    void printTop() const {
        if (!IsEmpty())
            cout << "Top of the stack: " << a[top] << endl;
        else
            cout << "Stack is empty!" << endl;
    }

    bool IsEmpty() const {
        return top == -1;
    }
};