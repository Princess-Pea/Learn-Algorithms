#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, string> map;

    map[12836] = "小哈";
    map[15937] = "小啰";
    map[16750] = "小算";
    map[13276] = "小法";
    map[10583] = "小鸭";

    string name = map[15937];
    cout << name << endl; // 输出：小啰

    /* 遍历哈希表 */
    // 遍历键值对 key->value
    for (auto kv : map)
    {
        cout << kv.first << " -> " << kv.second << endl;
    }
    // 使用迭代器遍历 key->value
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        cout << iter->first << " -> " << iter->second << endl;
    }
    // 前一种方式是基于范围的for循环，后一种方式是基于迭代器的遍历。
    // 区别是使用迭代器可以在遍历过程中修改哈希表的内容，而使用范围for循环则不行。因为范围for循环会创建一个临时变量来存储每个元素的副本，而迭代器则直接访问哈希表中的元素。

    map.erase(10583);
    name = map[10583];
    cout << ((name == " ") ? name : "Oops") << endl;

    auto it = map.find(10583);
    cout << ((it != map.end()) ? it->second : "Oops") << endl;

    return 0;
}