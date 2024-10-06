#
# @lc app=leetcode.cn id=3177 lang=python3
#
# [3177] 求出最长好子序列 II
#
# https://leetcode.cn/problems/find-the-maximum-length-of-a-good-subsequence-ii/description/
#
# algorithms
# Hard (36.37%)
# Likes:    10
# Dislikes: 0
# Total Accepted:    3.5K
# Total Submissions: 7.5K
# Testcase Example:  '[1,2,1,1,3]\n2'
#
# 给你一个整数数组 nums 和一个 非负 整数 k 。如果一个整数序列 seq 满足在范围下标范围 [0, seq.length - 2] 中存在 不超过
# k 个下标 i 满足 seq[i] != seq[i + 1] ，那么我们称这个整数序列为 好 序列。
#
# 请你返回 nums 中 好 子序列 的最长长度
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,1,1,3], k = 2
#
# 输出：4
#
# 解释：
#
# 最长好子序列为 [1,2,1,1,3] 。
#
#
# 示例 2：
#
#
# 输入：nums = [1,2,3,4,5,1], k = 0
#
# 输出：2
#
# 解释：
#
# 最长好子序列为 [1,2,3,4,5,1] 。
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 5 * 10^3
# 1 <= nums[i] <= 10^9
# 0 <= k <= min(50, nums.length)
#
#
#

from typing import List


# @lc code=start
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[-1] * (k + 1) for _ in range(len(nums))]
        res = 0
        for i in range(len(nums)):
            dp[i][0] = 1
            for ki in range(k + 1):
                for j in range(i):
                    add = 1 if nums[i] != nums[j] else 0
                    if ki - add >= 0 and dp[j][ki - add] != -1:
                        dp[i][ki] = max(dp[i][ki], dp[j][ki - add] + 1)
                res = max(res, dp[i][ki])
        return res


# @lc code=end
