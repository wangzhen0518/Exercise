#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#
# https://leetcode.cn/problems/edit-distance/description/
#
# algorithms
# Medium (62.96%)
# Likes:    3461
# Dislikes: 0
# Total Accepted:    529.1K
# Total Submissions: 839.3K
# Testcase Example:  '"horse"\n"ros"'
#
# 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
#
# 你可以对一个单词进行如下三种操作：
#
#
# 插入一个字符
# 删除一个字符
# 替换一个字符
#
#
#
#
# 示例 1：
#
#
# 输入：word1 = "horse", word2 = "ros"
# 输出：3
# 解释：
# horse -> rorse (将 'h' 替换为 'r')
# rorse -> rose (删除 'r')
# rose -> ros (删除 'e')
#
#
# 示例 2：
#
#
# 输入：word1 = "intention", word2 = "execution"
# 输出：5
# 解释：
# intention -> inention (删除 't')
# inention -> enention (将 'i' 替换为 'e')
# enention -> exention (将 'n' 替换为 'x')
# exention -> exection (将 'n' 替换为 'c')
# exection -> execution (插入 'u')
#
#
#
#
# 提示：
#
#
# 0 <= word1.length, word2.length <= 500
# word1 和 word2 由小写英文字母组成
#
#
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        cnt = list(range(len(word2) + 1))
        for x in word1:
            pre = cnt[0]
            cnt[0] += 1
            for j, y in enumerate(word2):
                tmp = cnt[j + 1]
                if x == y:
                    cnt[j + 1] = pre
                else:
                    cnt[j + 1] = min(cnt[j + 1], cnt[j], pre) + 1
                pre = tmp
        return cnt[-1]


# @lc code=end
s = Solution()
word1 = "horse"
word2 = "ros"
print(s.minDistance(word1, word2))
