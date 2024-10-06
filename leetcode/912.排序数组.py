#
# @lc app=leetcode.cn id=912 lang=python3
#
# [912] 排序数组
#

import random
from typing import List


# @lc code=start
class Solution:
    def _partition(self, nums: List[int], low: int, high: int) -> int:
        pivot = random.randint(low, high)
        nums[pivot], nums[low] = nums[low], nums[pivot]
        pivot = low
        i, j = low, high
        while i < j:
            while nums[j] >= nums[pivot] and i < j:
                j -= 1
            while nums[i] <= nums[pivot] and i < j:
                i += 1
            if i < j:
                nums[i], nums[j] = nums[j], nums[i]
        nums[j], nums[pivot] = nums[pivot], nums[j]
        return j

    def _quick_sort(self, nums: List[int], low: int, high: int):
        if low < high:
            pivot = self._partition(nums, low, high)
            i, j = pivot - 1, pivot + 1
            while i > low and nums[i] == nums[pivot]:
                i -= 1
            while j < high and nums[j] == nums[pivot]:
                j += 1
            self._quick_sort(nums, low, i)
            self._quick_sort(nums, j, high)

    def sortArray(self, nums: List[int]) -> List[int]:
        self._quick_sort(nums, 0, len(nums) - 1)
        return nums


# @lc code=end
