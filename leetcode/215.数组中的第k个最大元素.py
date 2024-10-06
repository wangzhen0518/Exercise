#
# @lc app=leetcode.cn id=215 lang=python3
#
# [215] 数组中的第K个最大元素
#

from typing import List
import random


# @lc code=start
class Solution:
    def _partition(self, nums: List[int], low: int, high: int):
        pivot = random.randint(low, high)
        nums[low], nums[pivot] = nums[pivot], nums[low]
        pivot = low
        i, j = low, high
        while i < j:
            while nums[j] >= nums[pivot] and i < j:
                j -= 1
            while nums[i] <= nums[pivot] and i < j:
                i += 1
            nums[i], nums[j] = nums[j], nums[i]
        nums[j], nums[pivot] = nums[pivot], nums[j]
        return j

    def _find(self, nums: List[int], k: int, low: int, high: int) -> int:
        pivot = self._partition(nums, low, high)
        i, j = pivot - 1, pivot + 1
        while i > low and nums[i] == nums[pivot]:
            i -= 1
        while j < high and nums[j] == nums[pivot]:
            j += 1

        delta_large = high - i
        delta_small = high - j + 2
        if delta_small <= k <= delta_large:
            target = nums[pivot]
        elif delta_small > k:
            target = self._find(nums, k, j, high)
        elif delta_large < k:
            target = self._find(nums, k - delta_large, low, i)
        return target

    def findKthLargest(self, nums: List[int], k: int) -> int:
        # nums = nums.copy()
        return self._find(nums, k, 0, len(nums) - 1)


# @lc code=end

s = Solution()
a = [3, 2, 1, 5, 6, 4]
k = 2
print(s.findKthLargest(a, k))
