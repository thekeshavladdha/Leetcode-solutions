/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
    
        while(prev->next && prev->next->next){
            ListNode* left=prev->next,*right=prev->next->next;
            left->next=right->next;
            right->next=left;
            prev->next=right;
            prev=left;
        }
        return dummy.next;
    }
};