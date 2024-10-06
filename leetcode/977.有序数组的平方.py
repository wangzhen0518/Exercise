#
# @lc app=leetcode.cn id=977 lang=python3
#
# [977] 有序数组的平方
#
# https://leetcode.cn/problems/squares-of-a-sorted-array/description/
#
# algorithms
# Easy (68.30%)
# Likes:    1032
# Dislikes: 0
# Total Accepted:    738.2K
# Total Submissions: 1.1M
# Testcase Example:  '[-4,-1,0,3,10]'
#
# 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
#
#
#
#
#
#
# 示例 1：
#
#
# 输入：nums = [-4,-1,0,3,10]
# 输出：[0,1,9,16,100]
# 解释：平方后，数组变为 [16,1,0,9,100]
# 排序后，数组变为 [0,1,9,16,100]
#
# 示例 2：
#
#
# 输入：nums = [-7,-3,2,3,11]
# 输出：[4,9,9,49,121]
#
#
#
#
# 提示：
#
#
# 1 10^4
# -10^4
# nums 已按 非递减顺序 排序
#
#
#
#
# 进阶：
#
#
# 请你设计时间复杂度为 O(n) 的算法解决本问题
#
#
#

from typing import List


# @lc code=start
class Solution:
    def sort1(self, nums: List[int]) -> List[int]:
        return sorted(x * x for x in nums)

    def sort2(self, nums: List[int]) -> List[int]:
        res = [x * x for x in nums]
        res.sort()
        return res

    def sortedSquares(self, nums: List[int]) -> List[int]:
        for idx, x in enumerate(nums):
            if x >= 0:
                break
        # arr1 = list(reversed([x * x for x in nums[:idx]]))
        arr1 = [x * x for x in nums[:idx]]
        arr2 = [x * x for x in nums[idx:]]
        i, j = len(arr1) - 1, 0
        res = []
        while i >= 0 and j < len(arr2):
            while j < len(arr2) and arr2[j] < arr1[i]:
                res.append(arr2[j])
                j += 1
            res.append(arr1[i])
            i -= 1
        while i >= 0:
            res.append(arr1[i])
            i -= 1
        while j < len(arr2):
            res.append(arr2[j])
            j += 1
        return res


# @lc code=end
s = Solution()
nums = [-4, -1, 0, 3, 10]
print(s.sortedSquares(nums))
