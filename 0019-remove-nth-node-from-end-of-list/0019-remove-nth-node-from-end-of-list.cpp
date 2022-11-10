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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        int i = 0;
        while(i<n+1 && fast!=NULL){
            i++;
            fast = fast->next;
        }
        
        
        if(i==1){
            return NULL;
        }
        
        if(i==n){
            return head->next;
        }
        
        ListNode* slow = head;
        
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        
        if(slow->next!=NULL){
            slow->next = slow->next->next;
        }else{
            slow->next = NULL;
        }
        
        return head;
    }
};