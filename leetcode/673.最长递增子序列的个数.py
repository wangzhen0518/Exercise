#
# @lc app=leetcode.cn id=673 lang=python3
#
# [673] 最长递增子序列的个数
#
# https://leetcode.cn/problems/number-of-longest-increasing-subsequence/description/
#
# algorithms
# Medium (45.01%)
# Likes:    883
# Dislikes: 0
# Total Accepted:    109.1K
# Total Submissions: 242.4K
# Testcase Example:  '[1,3,5,4,7]'
#
# 给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
#
# 注意 这个数列必须是 严格 递增的。
#
#
#
# 示例 1:
#
#
# 输入: [1,3,5,4,7]
# 输出: 2
# 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
#
#
# 示例 2:
#
#
# 输入: [2,2,2,2,2]
# 输出: 5
# 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
#
#
#
#
# 提示:
#
#
#
#
# 1 <= nums.length <= 2000
# -10^6 <= nums[i] <= 10^6
#
#
#

from typing import List


# @lc code=start
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        max_pre_len = [1] * len(nums)
        cnt_list = [1] * len(nums)
        for i, val in enumerate(nums):
            for j in reversed(range(i)):
                if val > nums[j]:
                    if max_pre_len[i] == max_pre_len[j] + 1:
                        cnt_list[i] += cnt_list[j]
                    elif max_pre_len[i] < max_pre_len[j] + 1:
                        max_pre_len[i] = max_pre_len[j] + 1
                        cnt_list[i] = cnt_list[j]

        max_len = max_pre_len[0]
        cnt = 0
        for pre_len, path_cnt in zip(max_pre_len, cnt_list):
            if pre_len > max_len:
                max_len = pre_len
                cnt = path_cnt
            elif pre_len == max_len:
                cnt += path_cnt
        return cnt


# @lc code=end
s = Solution()
nums = [1, 1, 1, 2, 2, 2, 3, 3, 3]
# nums = [1, 3, 5, 4, 7]
print(s.findNumberOfLIS(nums))
