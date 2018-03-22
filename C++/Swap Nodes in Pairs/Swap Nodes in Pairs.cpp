// Runtime: 4 ms
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* zeroNode = new ListNode(0);
        zeroNode->next = head;
        ListNode* p = zeroNode, * q = head;
        for (; q && q->next; p = q, q = q->next) {
            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;
        }
        return zeroNode->next;
    }
};