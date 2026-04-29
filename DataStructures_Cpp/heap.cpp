#include <iostream>
#include <string>
#define N 100
using namespace std;

// 获取左子节点的索引
int left(int i)
{
    return 2 * i + 1;
}
// 获取右子节点的索引
int right(int i)
{
    return 2 * i + 2;
}
// 获取父节点的索引
int parent(int i)
{
    if (i == 0)
    {
        return -1;
    }
    return (i - 1) / 2;
}

int heap[N] = {0}; // 堆数组
int size = 0;      // 堆的大小

// 堆化，此处为大顶堆
void siftup(int i) // i 是需要堆化的节点索引
{
    if (i == 0)
    {
        return;
    }
    if (heap[i] > heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        siftup(parent(i)); // 写在if内，只在需要交换时才继续向上调整
    }
}