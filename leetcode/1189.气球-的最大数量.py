#
# @lc app=leetcode.cn id=1189 lang=python3
#
# [1189] “气球” 的最大数量
#
# https://leetcode.cn/problems/maximum-number-of-balloons/description/
#
# algorithms
# Easy (68.17%)
# Likes:    141
# Dislikes: 0
# Total Accepted:    64.1K
# Total Submissions: 94.1K
# Testcase Example:  '"nlaebolko"'
#
# 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
#
# 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
#
#
#
# 示例 1：
#
#
#
# 输入：text = "nlaebolko"
# 输出：1
#
#
# 示例 2：
#
#
#
# 输入：text = "loonbalxballpoon"
# 输出：2
#
#
# 示例 3：
#
# 输入：text = "leetcode"
# 输出：0
#
#
#
#
# 提示：
#
#
# 1 <= text.length <= 10^4
# text 全部由小写英文字母组成
#
#
#

# @lc code=start
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = {"b": 0, "a": 0, "l": 0, "o": 0, "n": 0}
        for c in text:
            if c in cnt:
                if c == "l" or c == "o":
                    cnt[c] += 0.5
                else:
                    cnt[c] += 1
        return int(min(cnt.values()))


# @lc code=end
