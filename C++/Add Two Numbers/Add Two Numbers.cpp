// Runtime: 58 ms
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ans = new ListNode(l1->val + l2->val);
		ListNode *_ans = ans;
		while (l1 || l2) {
			l1 = l1 ? l1->next : nullptr; 
			l2 = l2 ? l2->next : nullptr;
			if (!l1 && !l2 && ans->val < 10)	break;
			ans->next = new ListNode(0);
			ans->next->val = (l1 && l2) ? l1->val + l2->val : (l1 ? l1->val : (l2 ? l2->val : 0));
			if (ans->val > 9) {
				ans->val -= 10;
				++ans->next->val;
			}
			ans = ans->next;
		}
		return _ans;
	}
};
// 比较坑的数据
// (1) [1,8]+[0] = [1,8]
// (2) [5]+[5] = [0,1]


// Runtime: 22 ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        
        int carry = 0;
        while(l1 || l2 || carry){
            int n = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            tail -> next = new ListNode(n % 10);
            carry = n / 10;
            tail = tail -> next;
            l1 = l1?l1 -> next:NULL;
            l2 = l2?l2 -> next:NULL;
        }
        return head -> next;
    }
};