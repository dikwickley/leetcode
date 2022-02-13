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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> lmap;
        ListNode*temp= head;
        int i=0;
        while(temp){
            temp= temp->next;
            i++;
            if(i>10000) return true;
        }
        return false;
    }
};