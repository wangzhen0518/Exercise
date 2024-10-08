#
# @lc app=leetcode.cn id=1486 lang=python3
#
# [1486] 数组异或操作
#
# https://leetcode.cn/problems/xor-operation-in-an-array/description/
#
# algorithms
# Easy (84.04%)
# Likes:    158
# Dislikes: 0
# Total Accepted:    111.3K
# Total Submissions: 132.6K
# Testcase Example:  '5\n0'
#
# 给你两个整数，n 和 start 。
#
# 数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。
#
# 请返回 nums 中所有元素按位异或（XOR）后得到的结果。
#
#
#
# 示例 1：
#
# 输入：n = 5, start = 0
# 输出：8
# 解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
# ⁠    "^" 为按位异或 XOR 运算符。
#
#
# 示例 2：
#
# 输入：n = 4, start = 3
# 输出：8
# 解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
#
# 示例 3：
#
# 输入：n = 1, start = 7
# 输出：7
#
#
# 示例 4：
#
# 输入：n = 10, start = 5
# 输出：2
#
#
#
#
# 提示：
#
#
# 1 <= n <= 1000
# 0 <= start <= 1000
# n == nums.length
#
#
#

# @lc code=start
class Solution:
    def xorOperation_sim(self, n: int, start: int) -> int:
        s = 0
        for i in range(n):
            s ^= start + 2 * i
        return s

    def xorOperation_bit(self, n: int, start: int) -> int:
        def xor_n(n: int):
            return (n, 1, n + 1, 0)[n % 4]
            # match n % 4:
            #     case 0:
            #         return n
            #     case 1:
            #         return 1
            #     case 2:
            #         return n + 1
            #     case 3:
            #         return 0

        a = start // 2
        b = n & start & 1
        return (xor_n(a + n - 1) ^ xor_n(a - 1)) * 2 + b


# @lc code=end
