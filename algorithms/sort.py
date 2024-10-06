from typing import List, TypeVar
import random
import unittest

T = TypeVar("T")


def partition(a: List[T], low: int, high: int) -> int:
    pivot = random.randint(low, high)
    a[pivot], a[low] = a[low], a[pivot]
    pivot = low
    i, j = low, high
    while i < j:
        while a[j] >= a[pivot] and i < j:
            j -= 1
        while a[i] <= a[pivot] and i < j:
            i += 1
        a[i], a[j] = a[j], a[i]
    a[j], a[pivot] = a[pivot], a[j]
    return j


def quick_sort(a: List[T], low: int, high: int):
    if high > low:
        pivot = partition(a, low, high)
        i, j = pivot - 1, pivot + 1
        while i > low and a[i] == a[pivot]:
            i -= 1
        while j < high and a[j] == a[pivot]:
            j += 1
        quick_sort(a, low, i)
        quick_sort(a, j, high)
    return a


def merge_sort(a: List[T]) -> List[T]:
    if len(a) > 1:
        mid = len(a) // 2
        arr1 = merge_sort(a[:mid])
        arr2 = merge_sort(a[mid:])
        i, j = 0, 0
        res = []
        while i < len(arr1) and j < len(arr2):
            while i < len(arr1) and arr1[i] < arr2[j]:
                res.append(arr1[i])
                i += 1
            res.append(arr2[j])
            j += 1
    else:
        res = a
    return res


class QuickSortTest(unittest.TestCase):
    def setUp(self) -> None:
        print("start test")

    def tearDown(self) -> None:
        print("finish test")

    def test_case1(self):
        a = [1, 4, 2, 3, 6, 34, 41, 5, 234, 1, 5, 4361, 4, 1235, 641, 234, 1]
        target = sorted(a)
        quick_sort(a, 0, len(a) - 1)
        self.assertEqual(a, target)

    def test_case2(self):
        a = [1, 4, 2, 3, 6, 34, 41, 5, 234, 1, 5, 4361, 4, 1235, 641, 234, 1]
        target = sorted(a)
        res = merge_sort(a)
        self.assertEqual(res, target)


# if __name__ == "__main__":
#     unittest.main()
a = [1, 4, 2, 3, 6, 34, 41, 5, 234, 1, 5, 4361, 4, 1235, 641, 234, 1]
print(merge_sort(a))
