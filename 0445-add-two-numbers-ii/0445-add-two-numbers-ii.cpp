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
        vector<int> first,second;
        
        while(l1){
            first.push_back(l1->val);
            l1 = l1->next;
        }
        
        while(l2){
            second.push_back(l2->val);
            l2 = l2->next;
        }
        
        int sum = 0,carry = 0;
        ListNode* head = NULL;
        ListNode* p = NULL;
        
        for(int i=first.size()-1,j=second.size()-1;i>=0 || j>=0 || carry>0 ;i--,j--){
            sum = carry;
            
            if(i>=0){
                sum += first[i];
            }
            
            if(j>=0){
                sum += second[j];
            }
            
            carry = sum/10;
            
            p = new ListNode(sum%10);
            p->next = head;
            head = p;
        }
        
        return head;
    }
};