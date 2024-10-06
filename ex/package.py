# 背景:当前有一种发送策略，只在整点发送
# 1. 给你一个整数 n 表示可推送的时间点，编号从 0 到 n-1
# 2. 另给你一个二维整数数组， plans[i]=[start_i, end i, gain_i].
# 其中 i 表示第 i 种发送方案: 在 [start i，end i] 这个左闭右闭的时间区间内连续在整点发推送消息，gain i 表示这第i种发送方案的预期收益，
# 3. 但是为降低对用户的打扰，每个整点时刻只能发送一次推送消息，但是允许在某些时间不发送推送
# 4. 一种发送方案不能被拆分，但是可以多种发送方案组合
# 求解: 发送的预期最大收益

from typing import List


def max_gain(n: int, plans: List[List[int]]) -> int:
    # 初始化 dp 数组，dp[t] 表示在时间点 t 之前（包括 t）所能获得的最大收益
    gain = [0] * len(n)
    for starti, endi, gaini in plans:
        # 如果 start_i 为 0，则 start_i-1 为 -1，表示从初始状态转移
        if starti != 0:
            gaini += gain[starti - 1]
        gain[endi] = max(gain[endi], gaini)
        # 更新 dp[t] 的值，确保 dp[t] 是当前时间点之前的最大收益
        if endi < n - 1:
            gain[endi + 1] = max(gain[endi], gain[endi + 1])
    # 返回最终的最大收益
    return gain[-1]


# 示例
n = 5
plans = [[0, 2, 1], [1, 2, 3], [3, 4, 4]]
print(max_gain(n, plans))  # 输出: 8
