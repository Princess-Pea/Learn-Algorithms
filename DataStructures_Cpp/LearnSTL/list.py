# ps: Python 中所有数据都是对象，即使是数字也不例外；
# 列表只是存放这些对象的“引用”（类似指针），而不是对象本身。
# 比如，lst = [5, 5] 并不会在列表的内存块中直接存放两个 5 的值，而是存放两个指针（引用），每个指针指向堆上的某个整数对象。因此，列表的内存布局是一段连续的内存块（存放指针），但指针指向的对象在堆中可以是任意位置，不要求连续。

num: list[int] = [6]
nums: list[float] = [1,2,3]


nums.append(1.3)

nums.insert(2,3.14)

nums.pop(1)

print(nums)

nums+=num

nums.sort()

print(nums)