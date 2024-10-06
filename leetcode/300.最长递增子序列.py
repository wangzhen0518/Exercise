#
# @lc app=leetcode.cn id=300 lang=python3
#
# [300] 最长递增子序列
#
# https://leetcode.cn/problems/longest-increasing-subsequence/description/
#
# algorithms
# Medium (56.24%)
# Likes:    3727
# Dislikes: 0
# Total Accepted:    1M
# Total Submissions: 1.8M
# Testcase Example:  '[10,9,2,5,3,7,101,18]'
#
# 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
#
# 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
# 的子序列。
#
#
# 示例 1：
#
#
# 输入：nums = [10,9,2,5,3,7,101,18]
# 输出：4
# 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
#
#
# 示例 2：
#
#
# 输入：nums = [0,1,0,3,2,3]
# 输出：4
#
#
# 示例 3：
#
#
# 输入：nums = [7,7,7,7,7,7,7]
# 输出：1
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 2500
# -10^4 <= nums[i] <= 10^4
#
#
#
#
# 进阶：
#
#
# 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
#
#
#

from typing import List


# @lc code=start
class Solution:
    def lengthOfLIS_dp(self, nums: List[int]) -> int:
        max_end_len = [1] * len(nums)
        for i, val in enumerate(nums):
            for idx in reversed(range(i)):
                if val > nums[idx]:
                    max_end_len[i] = max(max_end_len[i], max_end_len[idx] + 1)
        return max(max_end_len)

    def binary_search(self, a: List[int], value: int) -> int:
        low, high = 0, len(a) - 1
        res = 0
        while high >= low:
            mid = (low + high) // 2
            if value <= a[mid]:
                high = mid - 1
                res = mid
            else:
                low = mid + 1
        return res

    def lengthOfLIS_bs(self, nums: List[int]) -> int:
        p = [nums[0]]
        for val in nums[1:]:
            if val > p[-1]:
                p.append(val)
            elif val < p[-1]:
                idx = self.binary_search(p, val)
                p[idx] = val
        return len(p)

    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        return self.lengthOfLIS_bs(nums)


# @lc code=end
s = Solution()
nums = [0, 1, 0, 3, 2, 3]
print(s.lengthOfLIS(nums))
