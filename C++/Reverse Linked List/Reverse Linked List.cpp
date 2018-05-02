// Runtime: 9 ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* rev = head;
        ListNode* nex = head->next;
        
        rev->next = NULL;
        while(nex) {
            head = nex;
            nex = nex->next;
            
            head->next = rev;
            rev = head;            
        }
        return rev;
    }
};

// 更简洁的一点的写法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while (head) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

// 递归方式
// (1) 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// (2) 1 -> 2 -> 3 -> 4 -> NULL & 5 -> 4 -> NULL
// (3) 1 -> 2 -> 3 -> NULL & 5 -> 4 -> 3 -> NULL
// (4) ...

class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 
