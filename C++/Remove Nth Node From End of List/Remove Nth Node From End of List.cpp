// Runtime: 10 ms

// 单链表，删除倒数第n个元素
// 必须获取第n-1个节点，而且要知道此时是第n-1个节点
// 思路就是用两个指针进行移动，时间复杂度是O(n)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        if (!fast) {
            return slow->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};