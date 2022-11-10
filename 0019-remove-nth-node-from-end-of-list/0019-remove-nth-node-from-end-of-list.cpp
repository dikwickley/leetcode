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
        
        int count = 0;
        ListNode* h = head;
        while(h!=NULL){
            h = h->next;
            count++;
        }
        
        if(count==1){
            return NULL;
        }
        
        n = count-n;
        
        if(n==0){
            return head->next;
        }
        
        int i = 0;
        h = head;
        while(i<n-1){
            h = h->next;
            i++;
        }
        
        if(h->next->next != NULL) h->next = h->next->next;
        else h->next = NULL;
        
        
        return head;
    }
};