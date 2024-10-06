#
# @lc app=leetcode.cn id=3174 lang=python3
#
# [3174] 清除数字
#
# https://leetcode.cn/problems/clear-digits/description/
#
# algorithms
# Easy (81.82%)
# Likes:    26
# Dislikes: 0
# Total Accepted:    19.8K
# Total Submissions: 24.2K
# Testcase Example:  '"abc"'
#
# 给你一个字符串 s 。
#
# 你的任务是重复以下操作删除 所有 数字字符：
#
#
# 删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
#
#
# 请你返回删除所有数字字符以后剩下的字符串。
#
#
#
# 示例 1：
#
#
# 输入：s = "abc"
#
# 输出："abc"
#
# 解释：
#
# 字符串中没有数字。
#
#
# 示例 2：
#
#
# 输入：s = "cb34"
#
# 输出：""
#
# 解释：
#
# 一开始，我们对 s[2] 执行操作，s 变为 "c4" 。
#
# 然后对 s[1] 执行操作，s 变为 "" 。
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 100
# s 只包含小写英文字母和数字字符。
# 输入保证所有数字都可以按以上操作被删除。
#
#
#

from typing import List


# @lc code=start
class Solution:
    def clearDigits(self, s: str) -> str:
        stack: List[str] = []
        for c in s:
            if c.isdigit():
                if len(stack) > 0 and not stack[-1].isdigit():
                    stack.pop()
            else:
                stack.append(c)
        return "".join(stack)


# @lc code=end

solver = Solution()
s = "1cb34"
print(solver.clearDigits(s))
