# Q1. 举报垃圾信息
# 中等
# 4 分
# 给你一个字符串数组 message 和一个字符串数组 bannedWords。
# 如果数组中 至少 存在两个单词与 bannedWords 中的任一单词 完全相同，则该数组被视为 垃圾信息。
# 如果数组 message 是垃圾信息，则返回 true；否则返回 false。

# 示例 1：
# 输入： message = ["hello","world","leetcode"], bannedWords = ["world","hello"]
# 输出： true
# 解释：
# 数组 message 中的 "hello" 和 "world" 都出现在数组 bannedWords 中。

# 示例 2：
# 输入： message = ["hello","programming","fun"], bannedWords = ["world","programming","leetcode"]
# 输出： false
# 解释：
# 数组 message 中只有一个单词（"programming"）出现在数组 bannedWords 中。

# 提示：
# 1 <= message.length, bannedWords.length <= 105
# 1 <= message[i].length, bannedWords[i].length <= 15
# message[i] 和 bannedWords[i] 都只由小写英文字母组成。
from typing import List


class Solution:
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        bannedWordsSet = set(bannedWords)
        cnt = 0
        for word in message:
            if word in bannedWordsSet:
                cnt += 1
            if cnt >= 2:
                return True
        return False


s = Solution()
message = ["hello", "programming", "fun"]
bannedWords = ["world", "programming", "leetcode"]
res = s.reportSpam(message, bannedWords)
print(res)
