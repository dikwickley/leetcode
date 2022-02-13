/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> lmap;
        
        while(headA){
            lmap.insert({headA, false});
            headA = headA->next;
        }
        
        while(headB){
            if(lmap.find(headB) != lmap.end()) return headB;
            headB = headB->next;
        }
        
        return NULL;
    }
};