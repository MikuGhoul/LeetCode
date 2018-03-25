// Runtime: 12 ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = new ListNode(0);
        ListNode* preHead = slow;
        slow->next = head;
        ListNode* fast = head->next;
        while (fast) {
            if (slow->next->val == fast->val) {
                fast = fast->next;
                if (!fast)
                    slow->next = NULL;
            }
            else {
                if (slow->next->next != fast)
                    slow->next = fast;
                else 
                    slow = slow->next;
                if (fast)
                    fast = fast->next;
            }
        }
        return preHead->next;
    }
};