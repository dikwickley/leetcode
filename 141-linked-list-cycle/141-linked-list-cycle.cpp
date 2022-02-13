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
        while(temp){
            if(lmap.find(temp) == lmap.end()){
                //found
                lmap.insert({temp, false});
            } else {
                return true;
            }
            temp= temp->next;
        }
        return false;
    }
};