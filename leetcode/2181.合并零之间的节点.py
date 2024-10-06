#
# @lc app=leetcode.cn id=2181 lang=python3
#
# [2181] 合并零之间的节点
#
# https://leetcode.cn/problems/merge-nodes-in-between-zeros/description/
#
# algorithms
# Medium (84.08%)
# Likes:    39
# Dislikes: 0
# Total Accepted:    22.2K
# Total Submissions: 26K
# Testcase Example:  '[0,3,1,0,4,5,2,0]'
#
# 给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。
#
# 对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。
#
# 返回修改后链表的头节点 head 。
#
#
#
# 示例 1：
#
#
#
# 输入：head = [0,3,1,0,4,5,2,0]
# 输出：[4,11]
# 解释：
# 上图表示输入的链表。修改后的链表包含：
# - 标记为绿色的节点之和：3 + 1 = 4
# - 标记为红色的节点之和：4 + 5 + 2 = 11
#
#
# 示例 2：
#
#
#
# 输入：head = [0,1,0,3,0,2,2,0]
# 输出：[1,3,4]
# 解释：
# 上图表示输入的链表。修改后的链表包含：
# - 标记为绿色的节点之和：1 = 1
# - 标记为红色的节点之和：3 = 3
# - 标记为黄色的节点之和：2 + 2 = 4
#
#
#
#
# 提示：
#
#
# 列表中的节点数目在范围 [3, 2 * 10^5] 内
# 0 <= Node.val <= 1000
# 不 存在连续两个 Node.val == 0 的节点
# 链表的 开端 和 末尾 节点都满足 Node.val == 0
#
#
#

from typing import Optional, List


# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next: Optional["ListNode"] = None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes_inplace(self, head: Optional[ListNode]) -> Optional[ListNode]:
        new_head = new_tail = head
        cnt = 0
        node = head.next
        while node is not None:
            if node.val == 0:
                new_tail.next.val = cnt
                new_tail = new_tail.next
                cnt = 0
            else:
                cnt += node.val
            node = node.next
        new_tail.next = None
        return new_head.next

    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        new_head = ListNode()
        new_tail = new_head
        node = head.next
        cnt = 0
        while node is not None:
            if node.val == 0:
                new_tail.next = ListNode(cnt)
                new_tail = new_tail.next
                cnt = 0
            else:
                cnt += node.val
            node = node.next
        return new_head.next


# @lc code=end
def create_list(head: List[int]) -> ListNode:
    new_head = new_tail = ListNode()
    for x in head:
        new_tail.next = ListNode(x)
        new_tail = new_tail.next
    return new_head.next


def print_list(head: Optional[ListNode]):
    node = head
    while node is not None:
        print(node.val, end=", ")
        node = node.next


s = Solution()

head = [0, 3, 1, 0, 4, 5, 2, 0]
head = create_list(head)
res = s.mergeNodes(head)
print_list(res)
