// Runtime: 13 ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // if (!head || !head->next)
        //     return head;
        ListNode* fast = head, * slow = head;
        while (fast && slow) {
            fast = fast->next;
            while (fast && (fast->val == slow->val)) {
                fast = fast->next;
            }
            slow->next = fast;
            slow = slow->next;            
        }
        return head;
    }
};