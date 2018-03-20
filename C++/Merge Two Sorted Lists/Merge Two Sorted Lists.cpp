// Runtime: 15 ms
class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* re_l1 = l1;
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		while (l2 && l1->val > l2->val) {
			ListNode* temp = l2;
			l2 = l2->next;
			temp->next = l1;
			re_l1 = l1 = temp;
		}
		do {
			while (l2 && l1->val <= l2->val && (!l1->next || l1->next->val > l2->val)) {
				ListNode* temp = l2;
				l2 = l2->next;
				temp->next = l1->next;
				l1->next = temp;
			}
			if (!l1->next) {
				l1->next = l2;
				break;
			}
			l1 = l1->next;
		} while (l2);
		return re_l1;
	}
};

// ...我想撞墙
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};