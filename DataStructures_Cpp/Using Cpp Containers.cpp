// using cpp containers
// 下面我们使用C++中内置的栈、队列与双向队列
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    stack<int> stk;
    queue<int> que;
    deque<int> deq;

    stk.push(1);
    stk.push(2);
    stk.pop();

    que.push(1);
    que.push(2);
    que.pop();

    deq.push_back(1);
    deq.push_front(3);
    deq.pop_back();

    // 如何把它们输出到屏幕上呢？

    // 对于 std::stack，它是一个适配器容器，不支持 begin() 和 end()，也没有迭代器。
    // 不能像遍历 std::vector 或 std::deque 那样遍历 std::stack。
    stack<int> tempStack = stk; // 创建一个临时栈来保存原始栈的内容
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " "; // 输出栈顶元素
        tempStack.pop();                // 弹出栈顶元素
    }

    // 对于 std::queue，它也是一个适配器容器，同样不支持 begin() 和 end()，也没有迭代器。
    queue<int> tempQueue = que; // 创建一个临时队列来保存原始队列的内容
    while (!tempQueue.empty())
    {
        cout << tempQueue.front() << " "; // 输出队列头元素
        tempQueue.pop();                  // 弹出队列头元素
    }

    // 对于 std::deque，它是一个双端队列，支持 begin() 和 end()，也有迭代器。
    for (deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        cout << *it << " "; // 输出双端队列中的元素
    }
    // 当然我们也可以简单用auto来简化迭代器的声明
    for (auto it = deq.begin(); it != deq.end(); ++it)
    {
        cout << *it << " "; // 输出双端队列中的元素
    }
}
