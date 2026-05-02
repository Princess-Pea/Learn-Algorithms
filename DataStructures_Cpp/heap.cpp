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
void recursive_siftup(int i) // i 是需要堆化的节点索引
{
    if (i == 0)
    {
        return;
    }
    if (heap[i] > heap[parent(i)])
    {
        swap(heap[i], heap[parent(i)]);
        recursive_siftup(parent(i)); // 写在if内，只在需要交换时才继续向上调整
    }
}

void iterative_siftup(int i)
{
    while (i > 0)
    {
        if (heap[i] > heap[parent(i)])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i); // 交换后继续向上调整
        }
        else
        {
            break; // 如果不需要交换，直接退出循环
        }
    }
}

void heapify(int i, int size)
{
    int largest = i; // 假设当前节点是最大的
    int l = left(i);
    int r = right(i);

    if (l < size && heap[l] > heap[largest])
    {
        largest = l; // 更新最大值索引为左子节点
    }
    if (r < size && heap[r] > heap[largest])
    {
        largest = r; // 更新最大值索引为右子节点
    }
    if (largest != i)
    {
        swap(heap[i], heap[largest]); // 交换当前节点与最大值节点
        heapify(largest, size);       // 递归调整被交换的子树
    }
}

void heapify(int i, int size)
{
    while (true)
    {
        int largest = i;
        int l = left(i);
        int r = right(i);
        if (l < size && heap[l] > heap[largest])
        {
            largest = l;
        }
        if (r < size && heap[r] > heap[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            i = largest;
        }
        else
        {
            break;
        }
    }
}

// 通常，调用 siftDown(i) 时，已经保证：
// 以节点 i 的左孩子 left(i) 为根的子树，本身是一个合法的大顶堆。
// 以节点 i 的右孩子 right(i) 为根的子树，本身也是一个合法的大顶堆。
// 所以此时可能破坏堆性质的，只有节点 i 与它的直接子节点。
void siftdown(int i, int size)
{
    while (true)
    {
        int l = left(i), r = right(i), ma = i;
        if (l < size && heap[l] > heap[ma])
        {
            ma = l;
        }
        if (r < size && heap[r] > heap[ma])
        {
            ma = r;
        }
        if (ma != i)
        {
            swap(heap[i], heap[ma]);
            i = ma;
        }
        else
        {
            break;
        }
    }
}

void pop(int &size)
{
    if (size == 0)
    {
        throw out_of_range("堆为空");
    }
    swap(heap[0], heap[size - 1]); // 将堆顶元素与最后一个元素交换
    size--;                        // 减小堆的大小
    siftdown(0, size);             // 从堆顶开始调整堆
}