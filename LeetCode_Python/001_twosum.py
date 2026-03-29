class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]+nums[j]==target:
                    return [i,j]
                
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # 这是一个“记事本”，记录 {数字: 下标}
        hashmap = {}
        
        for i, num in enumerate(nums):
            # 我们不找加数，我们找“差值”
            complement = target - num
            
            # 查一下记事本，以前有没有见过这个差值？
            if complement in hashmap:
                # 找到了！返回以前记录的下标和现在的下标
                return [hashmap[complement], i]
            
            # 没找到就把现在的数字和下标存进记事本
            hashmap[num] = i