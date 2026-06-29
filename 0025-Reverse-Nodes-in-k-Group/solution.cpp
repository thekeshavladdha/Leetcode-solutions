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
    void reverse(ListNode* left,int n){
        ListNode* prev=NULL;
        ListNode* nex;
        for(int i=0;i<n;i++){
            nex=left->next;
            left->next=prev;
            prev=left;
            left=nex;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode dummy(0);
        dummy.next=head;
        ListNode* left=dummy.next,*right,*nex,*prev=&dummy;
        while(true){
            right=left;
            for(int i=0;i<k-1;i++){
                if(right) right=right->next;
                else break;
            }
            if(right){
                nex=right->next;
                reverse(left,k);
                prev->next=right;
                prev=left;
                left=nex;
            }
            else{
                prev->next=left;
                break;
            }
        }
        return dummy.next;
    }    
    
};