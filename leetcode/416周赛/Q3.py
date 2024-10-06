# Q3. 统计重新排列后包含另一个字符串的子字符串数目 I
# 中等
# 5 分
# 给你两个字符串 word1 和 word2 。

# 如果一个字符串 x 重新排列后，word2 是重排字符串的
# 前缀
#  ，那么我们称字符串 x 是 合法的 。

# 请你返回 word1 中 合法
# 子字符串
#  的数目。


# 示例 1：

# 输入：word1 = "bcca", word2 = "abc"

# 输出：1

# 解释：

# 唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。

# 示例 2：

# 输入：word1 = "abcabc", word2 = "abc"

# 输出：10

# 解释：

# 除了长度为 1 和 2 的所有子字符串都是合法的。

# 示例 3：

# 输入：word1 = "abcabc", word2 = "aaabc"

# 输出：0


# 解释：

# 1 <= word1.length <= 105
# 1 <= word2.length <= 104
# word1 和 word2 都只包含小写英文字母。
from collections import defaultdict


class Solution:
    def judgeAvailable(self, word1_dict, word2_dict: dict) -> bool:
        for k, v in word2_dict.items():
            if k not in word1_dict or word1_dict[k] < v:
                return False
        return True

    def validSubstringCount(self, word1: str, word2: str) -> int:
        word1_dict = defaultdict(int)
        word2_dict = defaultdict(int)
        for c in word2:
            word2_dict[c] += 1

        for pos, c in enumerate(word1):
            word1_dict[c] += 1
            if self.judgeAvailable(word1_dict, word2_dict):
                break
