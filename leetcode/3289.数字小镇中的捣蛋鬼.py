#
# @lc app=leetcode.cn id=3289 lang=python3
#
# [3289] 数字小镇中的捣蛋鬼
#
# https://leetcode.cn/problems/the-two-sneaky-numbers-of-digitville/description/
#
# Q1. 数字小镇中的捣蛋鬼
# 简单
# 3 分
# 数字小镇 Digitville 中，存在一个数字列表 nums，其中包含从 0 到 n - 1 的整数。每个数字本应 只出现一次，然而，有 两个 顽皮的数字额外多出现了一次，使得列表变得比正常情况下更长。
# 为了恢复 Digitville 的和平，作为小镇中的名侦探，请你找出这两个顽皮的数字。
# 返回一个长度为 2 的数组，包含这两个数字（顺序任意）。
#
# 示例 1：
# 输入： nums = [0,1,1,0]
# 输出： [0,1]
# 解释：
# 数字 0 和 1 分别在数组中出现了两次。
#
# 示例 2：
# 输入： nums = [0,3,2,1,3,2]
# 输出： [2,3]
# 解释:
# 数字 2 和 3 分别在数组中出现了两次。
#
# 示例 3：
# 输入： nums = [7,1,5,4,3,4,6,0,9,5,8,2]
# 输出： [4,5]
# 解释:
# 数字 4 和 5 分别在数组中出现了两次。
#
# 提示：
#
# 2 <= n <= 100
# nums.length == n + 2
# 0 <= nums[i] < n
# 输入保证 nums 中 恰好 包含两个重复的元素。

from typing import List
from math import sqrt


# @lc code=start
class Solution:
    def getSneakyNumbers_bit(self, nums: List[int]) -> List[int]:
        """
        第一个循环计算的是
        nums: 0^1^2^...^(n-1)^x^y   x, y 是重复的数字
        idx:     0^1^2^...^(n-1)^n^(n+1)
        init:                                 n^(n+1)
        考虑到 1. 相同元素进行异或结果为 0，2. 0^x = x，所以第一个循环的结果是 x^y

        第二个循环中，非 x, y 的元素都会被异或运算两次，所以不影响结果，而 x, y 经过 shift & 1 之后的索引不同，从而将两个元素分开。
        """
        n = len(nums) - 2
        xor_all = n ^ (n + 1)
        for i, x in enumerate(nums):
            xor_all ^= i ^ x
        shift = xor_all.bit_length() - 1

        ans = [0, 0]
        for i, x in enumerate(nums):
            if i < n:
                ans[i >> shift & 1] ^= i
            ans[x >> shift & 1] ^= x
        return ans

    def getSneakyNumbers_math(self, nums: List[int]) -> List[int]:
        n = len(nums) - 2
        s, v = -(n - 1) * n // 2, -(n - 1) * n * (2 * n - 1) // 6
        for x in nums:
            s += x
            v += x * x
        x = int(s + sqrt(2 * v - s * s)) // 2
        return [x, s - x]


# @lc code=end
s = Solution()
nums = [7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2]
print(s.getSneakyNumbers(nums))
