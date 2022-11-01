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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> a,b;
        while(l1){
            a.push_back(l1->val);
            l1 = l1->next;
        }
        while(l2){
            b.push_back(l2->val);
            l2 = l2->next;
        }
        // reverse(a.begin(), a.end());
        // reverse(b.begin(), b.end());
        vector<int> c;
        int i=0;
        int carry = 0;
        
        // for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
        // for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
        
        while(i < a.size() && i < b.size()){
            c.push_back((a[i]+b[i]+carry)%10);
            carry = (a[i]+b[i]+carry)/10;
            i++;
        }
        
        for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
        
        while(i < a.size()){
            c.push_back((a[i]+carry)%10);
            carry = (a[i]+carry)/10;
            i++;
        }
        
        while(i < b.size()){
            c.push_back((b[i]+carry)%10);
            carry = (b[i]+carry)/10;
            i++;
        }
        
        if(carry){
            c.push_back(carry);
        }
        
        // for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
        
        // ListNode h = new ListNode(c[0], NULL);
        
        ListNode* head = new ListNode();
        head -> val = c[c.size()-1];
        head -> next = NULL;
        
        for(int i=c.size()-2;i>=0;i--){
            ListNode* temp = new ListNode();
            temp -> val = c[i];
            temp -> next = head;
            head = temp;
        }
        
        return head;
           
    }
};