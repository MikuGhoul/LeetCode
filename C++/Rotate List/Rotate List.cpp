// Runtime: 15 ms
class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		// k = 0 || []
		if (k == 0 || !head || !head->next) {
			return head;
		}
		ListNode* p = new ListNode(0);
		p->next = head;
		ListNode* q = head;
		int len = 0;
		for (int i = 0; i != k - 1; ++i) {
			// [1] && k = 99
			// [1, 2] && k = 3 
			// [1, 2, 3] && k = 2000000000
			if (!q->next) {
				q = head;
				len = i + 1;
				k = k % len == 0 ? len : k % len;
				i = 0;
				if (i == k - 1)
					break;
			}
			q = q->next;
		}
		// [1, 2] && k = 2
		if (!q->next)
			return head;
		while (q->next) {
			p = p->next;
			q = q->next;
		}
		ListNode* newHead = p->next;
		q->next = head;
		p->next = NULL;
		return newHead;
	}
};

// 被数据坑死了
// 稍微比较优雅一点的解法，构造一个环，免去了我的 !q->next里q = head的操作
// Runtime: 19 ms
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};

